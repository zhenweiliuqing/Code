#include <iostream>
#include <vector>
using namespace std;

// 需要二分查找找位置
class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        int mid = (left + right) / 2;
        // 这些在边边角角的特殊情况 好烦啊
        if (target <= nums[left])
            return left;
        if (target == nums[right])
            return right;
        if (target > nums[right])
            return right + 1;
        
        int ret;
        while (left + 1 < right) {
            if (nums[mid] == target) {
                ret = mid;
                break;
            }
            else if (nums[mid] > target) 
                right = mid;
            else if (nums[mid] < target) 
                left = mid;
            mid = (left + right) / 2;
        }
        if (left + 1 == right)
            ret = right;
        return ret;
    }
};
// 通过了


int searchInsert(vector<int>& nums, int target) {
    int n = nums.size();
    int left = 0, right = n - 1, ans = n;
    while (left <= right) {
        int mid = ((right - left) >> 1) + left; // 防止溢出 运算快
        if (target <= nums[mid]) {
            ans = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }
}