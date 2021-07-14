#include <iostream>
#include <vector>
using namespace std;

// 状态：dp[i][j] i到j 的最长回文子序列长度
// 转移：如果s[i]==s[j] dp[i][j] = dp[i+1][j-1] + 2
//       不相等的话 dp[i][j] = max(dp[i][j-1], dp[i+1][j]);

class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int l = 1; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (s[i] == s[j])
                    // dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]) + 1; // 有时候+1 有时候+2 有时候+0 这个转移不太会啊
                    dp[i][j] = dp[i + 1][j - 1] + 2;
                else
                    dp[i][j] = max(dp[i + 1][j], dp[i][j - 1]);
            }
        }
        return dp[0][n - 1];
    }
};
// 差一点就得到正确的状态转移了！！！
// 通过了