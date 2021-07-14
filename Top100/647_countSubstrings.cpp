#include <iostream>
#include <vector>
using namespace std;

// 答案上用的是dp[i][j] = True表示是回文子串
class Solution {
public:
    int countSubstrings(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, false));
        int cnt = 0;
        for (int l = 0; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (i == j || (l == 1 && s[i] == s[j]) || (l > 1 && s[i] == s[j] && dp[i + 1][j - 1])) {
                    dp[i][j] = true;
                    cnt++;
                }
            }
        }
        return cnt;
    }
};
// 通过了 我这个循环写的比较复杂