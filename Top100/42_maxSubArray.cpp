// 3-5
#include <iostream>
#include <vector>
using namespace std;

// 状态:dp[i] 以i为结尾的子数组最大和
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        int ans = dp[0];
        for (int i = 1 ; i < n; i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// 一次通过