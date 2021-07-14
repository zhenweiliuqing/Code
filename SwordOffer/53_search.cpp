// 3-6
#include <iostream>
#include <vector>
using namespace std;

// 注意 2 2 2 找3 或 1这种样例 容易出界
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 0)
            return 0;
        
        int left = 0, right = n - 1;
        int leftAns = left, rightAns = right;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] >= target)
                right = mid - 1;
        }
        leftAns = left;

        left = 0; 
        right = n - 1;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (nums[mid] <= target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        rightAns = right;
        
        if (leftAns >= 0 && leftAns <= n - 1 && rightAns >= 0 && rightAns <= n - 1)
            return nums[leftAns] == nums[rightAns] ? rightAns - leftAns + 1 : 0;
        return 0;
    }
};
// 通过了 