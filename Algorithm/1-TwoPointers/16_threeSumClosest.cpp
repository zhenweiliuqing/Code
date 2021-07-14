// 12-29
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int twosum(vector<int>& nums, int target, int start) {
        int left = start, right = nums.size() - 1;
        int closest = INT_MAX;
        int ans = INT_MAX;
        while (left < right) {
            int leftVal = nums[left], rightVal = nums[right];
            int sum = leftVal + rightVal;
            if (abs(sum - target) < closest) {
                closest = abs(sum - target);
                ans = sum;
            }
            if (sum > target)
                right--;
            else if (sum < target)
                left++;
            else
                break;
        }
        return ans;
    }

    int threeSumClosest(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int closest = INT_MAX;
        int ans = INT_MAX;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int res = twosum(nums, target - nums[i], i + 1);
            if (res == INT_MAX)
                continue;
            if (abs(res + nums[i] - target) < closest) {
                closest = abs(res + nums[i] - target);
                ans = res + nums[i];
            }
        }
        return ans;
    }
};
// 通过了

int main() {
    Solution sol;
    vector<int> nums = {0,1,2};
    sol.threeSumClosest(nums, 3);
}