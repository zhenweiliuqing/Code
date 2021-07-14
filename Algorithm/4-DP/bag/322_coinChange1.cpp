#include <iostream>
#include <vector>
using namespace std;


class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        
        for (int w = 1; w <= amount; w++) {
            for (int coin : coins) {
                if (w - coin < 0) // 硬币太大
                    continue;
                dp[w] = min(dp[w], 1 + dp[w - coin]);
            }
        }
    
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};

class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        for (int coin : coins) {
            for (int w = 1; w <= amount; w++) {
                if (w - coin < 0) // 硬币太大
                    continue;
                dp[w] = min(dp[w], 1 + dp[w - coin]);
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// 通过 这种交换顺序是没有影响的

// dp状态
// dp[j] 兑换j块钱 所需要的硬币数 
// 默认是正无穷 无解 要求的是最少硬币数
class Solution {
public:
    int coinChange(vector<int>& coins, int amount) {
        vector<int> dp(amount + 1, amount + 1);
        dp[0] = 0;
        int n = coins.size();
        for (int i = 0; i < n; i++) { // 每一个硬币
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i] < 0) // 硬币太大
                    continue; // 不等于上一个 换不了就是无穷大 无解
                // dp初始化为正无穷 +1 比正无穷还大 所以肯定没有影响
                // 求最大值时 初始化为负无穷 可能会影响吗？
                // 这是个完全背包问题 可以用重复的硬币 所以是正序 dp[j]可能就用了coins[i]
                dp[j] = min(dp[j], 1 + dp[j - coins[i]]); // dp[j]默认是无穷大 这里是amount+1
            }
        }
        return dp[amount] == amount + 1 ? -1 : dp[amount];
    }
};
// 通过了
// 跟之前的两个题还是有相似之处的 这个的dp table 是 dp[j - coins[i]]
// 而之前的是 dp[i - 1][j - 1] 
// 共同点都是建立一个dp table 然后从之前的table里推算现在的结果
