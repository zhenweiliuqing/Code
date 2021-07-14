#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int n = coins.size();
        for (int i = 0; i < n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] < 0) // 硬币太大
                    continue;
                dp[j] = min(dp[j], 1 + dp[j - coins[i]]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// 通过了
// 跟之前的两个题还是有相似之处的 这个的dp table 是 dp[j - coins[i]]
// 而之前的是 dp[i - 1][j - 1] 
// 共同点都是建立一个dp table 然后从之前的table里推算现在的结果