// 2-22
#include <iostream>
#include <vector>
using namespace std;

// 哈希表法 可以统计每个数字出现的次数 大于一半就是ans
// 不过空间复杂度为O(n)

// 采用剑指offer第二种算法 
// 第一种算法为快排的partition 需要调换顺序
// 第二种是遍历整个数组 用一个计数器
// 测试用例:
// 1 2 3 4 5 2 1 1 1 1
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        int cnt = 0, num;
        for (int i = 0; i < nums.size(); i++) {
            if (cnt == 0)
                num = nums[i];
            if (nums[i] == num)
                cnt++;
            else
                cnt--;
        }
        return num;
    }
};
// 一次通过

// partition 但是超时了 不知道哪里有错误 
// 排序法都没有超时 他也没有错误用例
// 这种就算了把
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size() - 1;
        int left = 0, right = n;
        int target = n / 2;
        while (left <= right) {
            int index = partition(nums, left, right);
            if (index == target)
                break;
            else if (index < target)
                left = index + 1;
            else if (index > target)
                right = index - 1;
        }
        return nums[target];
    }

    int partition(vector<int>& nums, int start, int end) {
        int left = start, right = end;
        int pivot = nums[start];
        while (left <= right) {
            while (left <= right && nums[left] <= pivot)
                left++;
            while (left <= right && nums[right] > pivot)
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

