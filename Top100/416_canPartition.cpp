#include <iostream>
#include <vector>
using namespace std;

// 这是动态规划？
class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size(), sum = 0;
        for (int i = 0; i < n; i++)
            sum += nums[i];
        if (sum % 2 == 1)
            return false;
        int w = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(w + 1, 0)); // 初始化全为0？
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= w; j++) {
                if (j - nums[i - 1] < 0)
                    dp[i][j] = dp[i - 1][j];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - nums[i - 1]] + nums[i - 1]);
                if (dp[i][j] == w)
                    return true;
            }
        }
        return false;
    }
};
// 这个竟然通过了 
// dp定义 状态转移方程都是什么意思？？？

// labuladong
bool canPartition(vector<int>& nums) {
    int sum = 0;
    for (int num:nums)
        sum += num;
    if (sum % 2 != 0)
        return false;
    int n = nums.size();
    sum = sum / 2;
    vector<vector<bool>> dp(n + 1, vector<bool>(sum + 1, false));
    for (int i = 0; i <= n; i++)
        dp[i][0] = true;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (j - nums[i - 1] < 0)
                dp[i][j] = dp[i - 1][j]; // j没有变 背包容量没有变 只是第 i 个物品不装入
            else
                dp[i][j] = dp[i - 1][j] | dp[i - 1][j - nums[i - 1]];
        }
    }
    return dp[n][sum];
}
