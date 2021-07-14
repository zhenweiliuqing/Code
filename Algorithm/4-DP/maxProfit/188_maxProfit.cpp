#include <iostream>
#include <vector>
using namespace std;

// 最多完成k笔交易
class Solution {
public:
    int maxProfit_inf(vector<int>& prices) {
        int n = prices.size();
        int dp0 = 0;
        int dp1 = -prices[0];
        for (int i = 1; i < n; i++) {
            dp0 = max(dp0, dp1 + prices[i]);
            dp1 = max(dp1, dp0 - prices[i]);
        }
        return dp0;
    }

    int maxProfit(int k, vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        //vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));
        
        if (k >= n / 2)
            return maxProfit_inf(prices);
        // k = 10 0000 0000 10亿
        int dp[n + 1][k + 1][2]; // 放到下边就通过了

        // base case 
        for (int i = 0; i <= k; i++) { // 第一天
            dp[0][i][0] = 0;
            dp[0][i][1] = -prices[0];
        }
        for (int i = 0; i < n; i++) { // 第0次交易
            dp[i][0][0] = 0;
        }

        // 状态转移
        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= k; j++) {
                dp[i][j][0] = max(dp[i - 1][j][0], dp[i - 1][j][1] + prices[i]);
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]); // 交易次数需要在买入的时候减
            }
        }
        return dp[n - 1][k][0];
    }
};