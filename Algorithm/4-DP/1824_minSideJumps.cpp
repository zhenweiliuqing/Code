#include <iostream>
#include <vector>
using namespace std;

// 状态: dp[i][j] i通道到达位置j需要的最少侧跳次数 base case dp[0][1] = 0
// 转移: dp[i][j] = min(dp[i][j-1], dp[i+-1][j] + 1);
class Solution {
public:
    int minSideJumps(vector<int>& obstacles) {
        int n = obstacles.size() - 1;
        vector<vector<int>> dp(3, vector<int>(n + 1, INT_MAX));
        dp[1][0] = 0;
        dp[0][0] = dp[2][0] = 1;
        for (int j = 1; j <= n; j++) {
            if (obstacles[j] == 0) {
                dp[0][j] = dp[0][j - 1];
                dp[1][j] = dp[1][j - 1];
                dp[2][j] = dp[2][j - 1];
            } else if (obstacles[j] == 1) {
                dp[1][j] = dp[1][j - 1];
                dp[2][j] = dp[2][j - 1];

            }

        }
    }
};
// 思路不清晰 看答案吧 脑子一片混乱

