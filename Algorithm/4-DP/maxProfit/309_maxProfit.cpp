#include <iostream>
#include <vector>
using namespace std;

// 含冷冻期 动态规划的核心就是状态转移
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int dp[n][2];
        dp[0][0] = 0;
        dp[0][1] = -prices[0];
        for (int i = 1; i < n; i++) {
            if (i == 1) {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 1][0] - prices[i]);
            }
            else {
                dp[i][0] = max(dp[i - 1][0], dp[i - 1][1] + prices[i]);
                dp[i][1] = max(dp[i - 1][1], dp[i - 2][0] - prices[i]); 
            }
        }
        return dp[n - 1][0];
    }
};
// 竟然通过了 但是这个空间我不会优化 因为不是只有前一天的两个状态
// 答案设了3个状态 可以优化