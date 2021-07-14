// 1-23
#include <iostream>
#include <vector>
using namespace std;

// dp[i] 指的是Alice赢或输 dp[0] = false;
// 转移 dp[i] 选择为 1-n的平方 如果有一个为false 就为true
class Solution {
public:
    bool winnerSquareGame(int n) {
        vector<bool> dp(n + 1);
        for (int i = 1; i <= n; i++) {
            for (int s = 1; i - s * s >= 0; s++) {
                if (!dp[i - s * s]) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// 直接通过 牛逼！