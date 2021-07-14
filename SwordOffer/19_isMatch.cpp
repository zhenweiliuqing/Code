// 2-10
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 思路：分两种情况 第一种就是.或者是字母匹配
// 第二种时* 可以匹配多个字符
// 第二种 可以有两种情况 1.匹配多个(s+1,p) 或 匹配1个(s+1,p+2) 2. 匹配0个 (s,p+2)
// 注意特殊情况 .* 匹配任意字符 
// 测试用例：
// s=aba p=ab*a
// s=ab p=.*ab / .*b
// "aaaaaaaaaaaaab"
// "a*a*a*a*a*a*a*a*a*a*c"
class Solution {
public:
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

    bool isMatch(string s, int m, string p, int n) {
        if (m == s.size() && n == p.size())
            return true;
        if (m != s.size() && n == p.size())
            return false;
        // * 情况
        if (n < p.size() - 1 && p[n + 1] == '*') {
            // 第一个字符匹配
            if (s[m] == p[n] || p[n] == '.')
                return isMatch(s, m + 1, p, n) || isMatch(s, m + 1, p, n + 2) || isMatch(s, m, p, n + 2);
            else
                return isMatch(s, m, p, n + 2);
        }
        // .情况
        if (s[m] == p[n] || p[n] == '.')
            return isMatch(s, m + 1, p, n + 1);
        return false;
    }
};
// 可以用memo优化一下

int main() {
    Solution sol;
    sol.isMatch("aa", "a*");
}


class Solution {
public:
    // vector<vector<bool>> memo;
    unordered_map<string, bool> mmap;
    bool isMatch(string s, string p) {
        return isMatch(s, 0, p, 0);
    }

    bool isMatch(string s, int m, string p, int n) {
        string tmp = to_string(m) + "," + to_string(n);
        if (mmap.count(tmp) != 0)
            return mmap[tmp];

        bool ans = false;
        if (m == s.size() && n == p.size())
            return true;
        if (m != s.size() && n == p.size())
            return false;
        // * 情况
        if (n < p.size() - 1 && p[n + 1] == '*') {
            // 第一个字符匹配
            if (s[m] == p[n] || (p[n] == '.' && m != s.size()))
                ans = isMatch(s, m + 1, p, n) || isMatch(s, m, p, n + 2);
            else
                ans = isMatch(s, m, p, n + 2);
        }
        // .情况
        else if (s[m] == p[n] ||(p[n] == '.' && m != s.size()))
            ans = isMatch(s, m + 1, p, n + 1);
        mmap[tmp] = ans;
        return ans;
    }
};
// 通过了 太神奇了 自己还没搞明白