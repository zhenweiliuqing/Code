#include <iostream>
#include <vector>
using namespace std;

// 6-18
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1)
            return nums[0] == target;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) 
                return true;
            if (nums[mid] == nums[left] && nums[mid] == nums[right]) {
                left++, right--;
                continue;
            }
            if (nums[mid] >= nums[left]) { 
                if (target >= nums[left] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (target <= nums[right] && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return false;
    }
};
// 通过了 但并不是很清楚


// 6-17
// 和33类似有重复的数字 关键是找到最小值 这第一问不就是154题
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else 
                right--; // 之所以这个格式不对也能正确的道理是right--
        }
        int min = nums[left];
        int ans = -1;
        if (target >= min && target <= nums[nums.size() - 1])
            ans = search(nums, target, left, nums.size() - 1);
        else if (right >= 0 && target >= nums[0] && target <= nums[right])
            ans = search(nums, target, 0, right);
        return ans;
    }

    int search(vector<int>& nums, int target, int left, int right) {
        if (left > right)
            return -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        return -1;
    }
};
// 答案错误 11121 这种情况154找的是第一个1 并不是分隔点