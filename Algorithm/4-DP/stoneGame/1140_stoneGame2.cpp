// 1-22
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// dp定义 dp[i][m] 当为m时取第i个之后的石头堆的最大值
// 转移 两种情况 第一种情况 可以全部拿走
// 第二种情况 核心 x=[1, 2m]  dp[i][m] = max(dp[i][m], sum[i] - dp[i + x][max(x, m)]);
class Solution {
public:
    vector<int> sum;
    void sumCalculate(vector<int>& piles) {
        int n = piles.size();
        sum = piles;
        for (int i = n - 2; i >= 0; i--)
            sum[i] += sum[i + 1];
    }
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        sumCalculate(piles);
        if (n == 1 || n == 2)
            return sum[0];
        vector<vector<int>> dp(n, vector<int>(n));
        for (int m = n - 1; m >= 1; m--) {
            for (int i = n - 1; i >= 0; i--) {
                if (i + 2 * m >= n)
                    dp[i][m] = sum[i];
                else {
                    for (int x = 1; x <= 2 * m; x++) {
                        dp[i][m] = max(dp[i][m], sum[i] - dp[i + x][max(x, m)]);
                    }
                }
            }
        }
        return dp[0][1];
    }
};
// 通过了 可以的