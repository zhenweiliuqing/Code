#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int minimumDeleteSum(string s1, string s2) {
        int m = s1.size(), n = s2.size();
        int sum1 = 0, sum2 = 0;
        for (int i = 0; i < m; i++) 
            sum1 += s1[i];
        for (int i = 0; i < n; i++) 
            sum2 += s2[i];
        vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                if (s1[i - 1] == s2[j - 1])
                    dp[i][j] = dp[i - 1][j - 1] + s1[i - 1];
                else
                    dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
        return sum1 + sum2 - 2 * dp[m][n];
    }
};
// 牛逼 通过了！！
// 712求删去字符的最小ASCII码值，保证求得的lcs有最大的ASCII码值就可以了。