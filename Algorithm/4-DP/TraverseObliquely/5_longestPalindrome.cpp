#include <string>
#include <iostream>
#include <vector>
using namespace std;

// 就用这个方法
// 动态规划
// 状态: dp[i][j] = true i-j是回文子串
// 转移: dp[i][j] = (s[i] == s[j] && dp[i+1][j-1]) 两边相等 且中间是回文串 

// 用自下而上的方法写
// 4-10
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans = s.substr(0, 1);
        for (int i = 0; i < n; i++)
            dp[i][i] = 1;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                if (j - i == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] && j - i + 1 > ans.size())
                    ans = s.substr(i, j - i + 1);
            }
        }
        return ans;
    }
};
// 通过了


class DP {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n));
        string ans;
        for (int l = 0; l < n; ++l) {
            for (int i = 0; i + l < n; ++i) { // l是扩展长度
                int j = i + l;
                if (l == 0) // 只有一个字符 对角线是1
                    dp[i][j] = 1;
                else if (l == 1)
                    dp[i][j] = (s[i] == s[j]);
                else
                    dp[i][j] = (s[i] == s[j] && dp[i + 1][j - 1]);
                if (dp[i][j] && l + 1 > ans.size())
                    ans = s.substr(i, l + 1);
            }
        }
        return ans;
    }
};

// 1-21
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.size();
        string ans = s.substr(0, 1);
        vector<vector<bool>> dp(n, vector<bool>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = true;
        for (int l = 1; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                if (s[i] == s[j] && (dp[i + 1][j - 1] || l == 1))
                    dp[i][j] = true;
                // dp[i][j] = (dp[i - 1][j - 1] || l == 1); // 应该是dp[i + 1]
                else 
                    dp[i][j] = false;
                if (dp[i][j] && ans.size() < l + 1)
                    ans = s.substr(i, l + 1); // 估计是这里消耗时间太长
            }
        }
        return ans;
    }
};

int main() {
    Solution sol;
    string s = "babsd";
    sol.longestPalindrome(s);
}


class Solution1 {
public:
    string longestPalindrome(string s) {
        // int n = s.size();
        // string temp = "";
        // temp += s[0];
        // string ret = temp;
        // for (int i = 0; i < n - 1; i++) {
        //     if (s[i] == s[i + 1]) {
        //         int j, k;
        //         for (j = i - 1, k = i + 1; j >= 0, k < n; j--, k++) {
        //             if (s[j] != s[k])
        //                 break;
        //         }
        //         temp = s.substr(j + 1, k - j - 1);
        //     } 
        //     if (s[i - 1] == s[i + 1] && i > 0) { // 奇数
        //         int t = 1;
        //         while ((i + t < n) && (i - t >= 0)) {
        //             if (s[i + t] != s[i - t])
        //                 break;
        //             t++;
        //         }
        //         temp = s.substr(i - t + 1, 2 * t - 1);
        //     }
        //     if (ret.size() < temp.size())
        //         ret = temp;
        // }
        // return ret;

        int n = s.size();
        string ans, temp;
        int left, right;
        for (int i = 0; i < n; i++) {
            left = i, right = i;
            // 奇数
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            temp = s.substr(left + 1, right - left - 1);
            if (ans.size() < temp.size())
                ans = temp;

            // 偶数
            left = i, right = i + 1;
            while (left >= 0 && right < n && s[left] == s[right]) {
                left--;
                right++;
            }
            temp = s.substr(left + 1, right - left - 1);
            if (ans.size() < temp.size())
                ans = temp;
        }
        return ans;
        // 通过了 找对思路极其简单
    }
};
// 自己的水平还是停留在三两条枪的阶段
// 但比第一次还是有进步 至少知道偶数了

// 中心扩展算法
class Answer {
public:
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};
// 还是简洁明了啊 自己虽然有思路 但是偏了一点就很麻烦
// 大思路对 细节也很重要啊