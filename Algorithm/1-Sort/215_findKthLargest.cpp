// 3-5
#include <iostream>
#include <vector>
using namespace std;

// 1. 排序取下标 O(nlogn) 
// 2. partiton O(n)
// 3. 最大堆 最小堆 最小堆取heap[0]就是第k大的数

// 4-26 换了种快排的思路
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = partition(nums, left, right);
            if (mid + 1 == k)
                break;
            else if (mid + 1 < k)
                left = mid + 1;
            else if (mid + 1 > k)
                right = mid - 1;
        }
        return nums[k - 1];
    }
    int partition(vector<int>& nums, int start, int end) {
        int pivot = nums[start];
        int slow = start;
        for (int fast = slow + 1; fast <= end; fast++) {
            // > >= 都是可以通过的
            if (nums[fast] > pivot) {
                slow++;
                swap(nums[fast], nums[slow]);
            }
        }
        swap(nums[slow], nums[start]);
        return slow;
    }
};
// 通过了

// 算法时间复杂度 为O(n)
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        int n = nums.size();
        int left = 0, right = n - 1, ans = 0;
        while (left <= right) {
            ans = partition(nums, left, right);
            if (ans + 1 == k)
                break;
            else if (ans + 1 > k)
                right = ans - 1;
            else if (ans + 1 < k)
                left = ans + 1;
        }
        return nums[ans];
    }
    int partition(vector<int>& nums, int start, int end) {
        if (start == end)
            return start;
        int pivot = nums[start];
        int left = start, right = end;
        while (left < right) {
            while (left <= end && nums[left] >= pivot)
                left++;
            while (right >= 0 && nums[right] < pivot)
                right--;
            if (left < right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        nums[start] = nums[right];
        nums[right] = pivot;
        return right;
    }
};


// 牛客网上 这个必须得按照从大到小排
// 终于找到问题了 如果按照从小到大排
// [3,1,2] 3 第3大的数是2
class Solution {
public:
    int findKth(vector<int> a, int n, int K) {
        // write code here
        int left = 0, right = n - 1, index = 0;
        while (left <= right) {
            index = partition(a, left, right);
            if (index == K - 1)
                break;
            else if (index > K - 1)
                right = index - 1;
            else if (index < K - 1)
                left = index + 1;
        }
        return a[K - 1];
    }
    
    int partition(vector<int>& nums, int start, int end) {
        if (start == end)
            return start;
        int pivot = nums[start];
        int left = start, right = end;
        while (left <= right) {
            while (left <= right && nums[left] >= pivot)
                left++;
            while (left <= right && nums[right] < pivot)
                right--;
            if (left < right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
        nums[start] = nums[right];
        nums[right] = pivot;
        return right;
    }
};