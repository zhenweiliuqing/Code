#include <iostream>
#include <vector>
using namespace std;

// 5-26
// 状态：dp[i][j] 字符串s[i]-s[j]打印的最少次数
// 转移：s[i] = s[j] 首尾相同 在打印s[i]的时候顺便打印了s[j] dp[i][j] = dp[i][j-1]
//       s[i] != s[j] 首尾不同 就得把s[i]的每一段分割开来 相加得到一个最小的结果
// 刚开始想不出状态 光想着一层一层可以覆盖 挺复杂的 找不出转移的规律 用暴力法都不知道怎么用
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, n));
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (s[i] == s[j]) {
                    dp[i][j] = dp[i][j - 1];
                } else {
                    for (int k = i; k < j; k++) {
                        dp[i][j] = min(dp[i][j], dp[i][k] + dp[k + 1][j]);
                    }
                }
            }
        }
        return dp[0][n - 1];
    }
};
// 通过了 和戳气球那几个题目很像

int main() {
    Solution sol;
    sol.strangePrinter("aaabbb");
}