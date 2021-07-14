#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); // 至少不比前一天少
        }
        return dp[n - 1];
    }
};
// 执行用时0ms 可也太快了！！ 有时候是4ms
// 只需要保存前两天的状态 所以可以做一个空间优化

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int dp0, dp1;
        dp0 = nums[0];
        dp1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = dp1;
            dp1 = max(dp1, dp0 + nums[i]); // 至少不比前一天少
            dp0 = temp;
        }
        return dp1;
    }
};
// 通过