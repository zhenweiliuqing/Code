#include <iostream>
#include <vector>
using namespace std;

// 给定一个三角形 triangle ，找出自顶向下的最小路径和。
// 每一步只能移动到下一行中相邻的结点上。相邻的结点 在这里指的是 下标 与 上一层结点下标 相同或者等于 上一层结点下标 + 1 的两个结点。
// 也就是说，如果正位于当前行的下标 i ，那么下一步可以移动到下一行的下标 i 或 i + 1 。

// 状态：dp[i][j] 表示坐标i,j的最小路径和
// 转移：dp[i][j] = min(dp[i-1][j-1], dp[i-1][j]) + triangle[i][j];

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        vector<vector<int>> dp(triangle);
        int m = triangle.size();
        for (int i = 1; i < m; i++) {
            dp[i][0] = dp[i - 1][0] + triangle[i][0];
            dp[i][i] = dp[i - 1][i - 1] + triangle[i][i];
            for (int j = 1; j < i; j++) {
                dp[i][j] = min(dp[i - 1][j - 1] + triangle[i][j], dp[i - 1][j] + triangle[i][j]);
            }
        }
        int ans = dp[m - 1][0];
        for (int i : dp[m - 1])
            ans = min(ans, i);
        return ans;
    }
};
// 通过了 这题思路很好找
// 下一步再优化空间复杂度把

