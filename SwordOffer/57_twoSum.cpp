// 3-9
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<int> ans(2);
        int n = nums.size();
        if (n < 2)
            return ans;
        int left = 0, right = n - 1;
        while (left < right) {
            int sum = nums[left] + nums[right];
            if (sum == target) {
                ans[0] = nums[left];
                ans[1] = nums[right];
                return ans;
            } else if (sum > target) {
                right--;
            } else if (sum < target) {
                left++;
            }
        }
        return ans;
    }
};
