// 3-5
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxValue(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        if (m == 0 || n == 0)
            return 0;
        vector<vector<int>> dp = grid;
        for (int i = 1; i < m; i++)
            dp[i][0] += dp[i - 1][0];
        for (int j = 1; j < n; j++)
            dp[0][j] += dp[0][j - 1];
        
        for (int i = 1; i < m; i++) {
            for (int j = 1; j < n; j++) {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + grid[i][j];
            }
        }
        return dp[m - 1][n - 1];
    }
};
// 一次通过 很一般的状态和选择
