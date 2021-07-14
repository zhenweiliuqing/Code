#include <iostream>
#include <vector>
using namespace std;

// 最多完成2笔交易
// 状态: dp[i][k][0] 第i天第k次交易没有股票
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        int k = 2;
        vector<vector<vector<int>>> dp(n + 1, vector<vector<int>>(k + 1, vector<int>(2)));
        
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
                dp[i][j][1] = max(dp[i - 1][j][1], dp[i - 1][j - 1][0] - prices[i]);
            }
        }
        return dp[n - 1][k][0];
    }
};
// 这降维打击 肯定能赢啊 就是内存和时间都比较大