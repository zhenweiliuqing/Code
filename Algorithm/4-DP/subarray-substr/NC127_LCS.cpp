
// 1143是最长公共子序列 不连续
// 127是最长公共字串 连续
// 状态：dp[i][j] 表示以str1[0-i]与str2[0-j]结尾的最大长度 包含当前字符
// 转移：str1[i] == str2[j] 的时候连上 dp[i-1][j-1] 初始状态就是1
//       str1[i] != str2[j] 的时候 dp[i][j] = 0 重新开始

// 测试用例：.ascbb .acb
class Solution {
public:
    /**
     * longest common substring
     * @param str1 string字符串 the string
     * @param str2 string字符串 the string
     * @return string字符串
     */
    string LCS(string str1, string str2) {
        // write code here
        int m = str1.size(), n = str2.size();
        vector<vector<int>> dp(m + 1, vector<int>(n + 1));
        string ans = "";
        for (int i = 1;  i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (str1[i - 1] == str2[j - 1])
                    dp[i][j] = dp[i - 1][j -1] + 1;
                else 
                    dp[i][j] = 0;
                if (dp[i][j] > ans.size())
                    ans = str1.substr(i - dp[i][j], dp[i][j]);
            }
        }
        return ans;
    }
};