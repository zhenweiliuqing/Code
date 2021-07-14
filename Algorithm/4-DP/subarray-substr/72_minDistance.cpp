#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

// 根据状态定义 dp[m][n]就是答案
// 状态：dp[i][j] word1[0-i] 转成 word2[0-j] 的最少操作数
// 转移：1. 替换 dp[i- 1][j - 1] + 1
//       2. 删除 增加 dp[i - 1][j] / dp[i][j - 1] + 1
//       3. 不变 dp[i - 1][j - 1]
// 删除 插入理解
// dp[i][j - 1]表示字符串s1[0 - i]变成s2[0 - j-1]的操作数 然后再insert s2[j]就可以了 dp[i][j] = dp[i][j-1] + ic
// dp[i - 1][j]表示字符串s1[0 - i-1]变成s2[0 - j]的操作数 然后再delete s1[i]就可以了 dp[i][j] = dp[i-1][j] + dc

// 4-4 
// 精简一下代码
class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        int dp[m + 1][n + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= m; i++)
            dp[i][0] = dp[i - 1][0] + 1;
        for (int i = 1; i <= n; i++) 
            dp[0][i] = dp[0][i - 1] + 1;

        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (word1[i - 1] == word2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1];
                else 
                    dp[i][j] = min(min(dp[i - 1][j] + 1, dp[i][j - 1] + 1), dp[i - 1][j - 1] + 1);
            }
        }
        return dp[m][n];
    }
};


// 变形1 输出每种操作的次数
// 自顶向下 递归
