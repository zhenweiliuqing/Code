#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //先用二分法找到中间任意一个再说
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (target == mid)
                break;
            else if (target < mid)
                right = mid;
            else if (target > mid)
                left = mid;
        }
    }
};

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        //先用二分法找到中间任意一个再说
        vector<int> ans = {-1, -1};
        int n = nums.size();
        if (n == 0)
            return ans;
        int left = 0, right = n - 1;
        int leftindex = 0, rightindex = n - 1;

        // 找到左下标
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            // 找到之后不要退出
            if (target <= nums[mid])
                right = mid;
            else if (target > nums[mid])
                left = mid + 1;
        }
        leftindex = right;
        if (nums[leftindex] != target)
            return ans;
        ans[0] = leftindex;

        left = 0, right = n;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            // 找到之后不要退出
            if (target < nums[mid])
                right = mid;
            else if (target >= nums[mid])
                left = mid + 1; // 由于mid会因为int去掉小数 偏左 所以left要加个1 不然会卡在这里
        }
        rightindex = left - 1; // 这里是由于left 加了1 所以要减去
        ans[1] = rightindex;
        
        return ans;
    }
};
// 看着答案写的 终于通过了 