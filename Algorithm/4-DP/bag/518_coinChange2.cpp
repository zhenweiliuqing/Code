#include <iostream>
#include <vector>
using namespace std;

// 1-18
// 状态:dp[i] 凑成钱数i的方法
// 转移:dp[i] += dp[i - coin in coins]
// 完全背包只能按顺序递推 dp[i]的状态dp[i][w]推导
class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int coin : coins) {
            for (int w = 1; w <= amount; w++) {
                if (w - coin < 0)
                    continue;
                dp[w] += dp[w - coin];
            }
        }
        return dp[amount];
    }
};
// 通过了
// 为什么这样就不会冲突了？ 原来 用1 之前既用了1又用了2  后边又要用2 所以会重复
// 3不能在用1枚硬币的时候 把2用两种硬币的方法数加起来

class Solution1 {
public:
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        if (n == 0 && amount == 0)
            return 1;
        if (n == 0)
            return 0;
        vector<vector<int>> dp(n + 1, vector<int>(amount + 1));
        for (int i = 0; i <= n; i++)
            dp[i][0] = 1;
        for (int i = 0; i <= amount; i++)
            dp[0][i] = 0;

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= amount; j++) {
                if (j - coins[i - 1] >= 0)
                    dp[i][j] = dp[i - 1][j] + dp[i][j - coins[i - 1]]; // 为什么是i 不是i-1 包括i 因为是无限可用
                else
                    dp[i][j] = dp[i - 1][j];
            }
        }
        return dp[n][amount];
    }
};
// 状态转移 好好想一想
// 完全背包问题 这个求的应该就不是 最大值了吧 求的是种类？
// 完全背包求最大值 需要再加一个循环 选择0或k次

class Solution {
public:
    int change(int amount, vector<int>& coins) {
        vector<int> dp(amount + 1);
        dp[0] = 1;
        for (int w = 1; w <= amount; w++) {
            for (int coin : coins) {
                if (w - coin < 0)
                    continue;
                dp[w] += dp[w - coin];
            }
        }
        return dp[amount];
    }
};
// 这个会重复 分析原因：子问题不是独立的



int main() {
    Solution sol;
    vector<int> v = {1, 2, 5};
    sol.change(5, v);
}