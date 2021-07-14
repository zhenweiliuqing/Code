#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 一条包含字母 A-Z 的消息通过以下映射进行了 编码 ：
// 'A' -> 1
// 'B' -> 2
// ...
// 'Z' -> 26
// 要解码已编码的消息，所有数字必须基于上述映射的方法，反向映射回字母（可能有多种方法）。例如，"111" 可以将 "1" 中的每个 "1" 映射为 "A" ，从而得到 "AAA" ，
// 或者可以将 "11" 和 "1"（分别为 "K" 和 "A" ）映射为 "KA" 。注意，"06" 不能映射为 "F" ，因为 "6" 和 "06" 不同。
// 给你一个只含数字的 非空 字符串 num ，请计算并返回 解码 方法的 总数 。
// 题目数据保证答案肯定是一个 32 位 的整数。

// 动态规划
// 状态：dp[i] 第i位共有多少种解码的方式
// 转移：s[i]为0 那么s[i-1]必须为1或2才合法 dp[i] = dp[i-2] 否则的话 30这种无法解码成功 就要返回0
//       s[i]是1-9  1. s[i-1]s[i]合起来是11-19 21-26之间 dp[i] = dp[i-1] + dp[i-2]
//                  2. s[i-1]为0 >2 || 27-29 dp[i] = dp[i-1]
// 还是判断11-19 21-26这个思路清晰些
class Solution {
public:
    int numDecodings(string s) {
        if (s[0] == '0')
            return 0;
        int n = s.size();
        int dp[n + 1];
        dp[0] = 1;
        dp[1] = 1;

        // for (int i = 2; i <= n; i++) {
        //     if (s[i - 1] == '0' && (s[i - 2] == '0' || s[i - 2] > '2'))
        //         return 0;
        //     if (s[i - 2] == '0' || (s[i - 1] > '6' && s[i - 2] >= '2')|| s[i - 2] > '2')
        //         dp[i] = dp[i - 1];
        //     else if (s[i - 1] == '0')
        //         dp[i] = dp[i - 2];
        //     else 
        //         dp[i] = dp[i - 1] + dp[i - 2];
        // }

        for (int i = 2; i <= n; i++) {
            // 
            if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2] == '2')
                    dp[i] = dp[i - 2];
                else
                    return 0;
            } else if (s[i - 2] == '0' || (s[i - 1] > '6' && s[i - 2] == '2') || s[i - 2] > '2') {
                dp[i] = dp[i - 1];
            } else
                dp[i] = dp[i - 1] + dp[i - 2];
        }

        // 另一种解法 这种思路清晰些
        for (int i = 2; i <= n; i++) {
            if (s[i - 1] == '0') {
                if (s[i - 2] == '1' || s[i - 2] == '2')
                    dp[i] = dp[i - 2];
                else
                    return 0;
            } else if (s[i - 2] == '1' || (s[i - 2] == '2' && s[i - 1] >= '1' && s[i - 1] <= '6')) {
                dp[i] = dp[i - 1] + dp[i - 2]; // 11-19 || 21-26 
            } else
                dp[i] = dp[i - 1];
        }
        return dp[n];
    }
};
// 通过了 打补丁真累

// 第一反应是用回溯来做
class Solution1 {
public:
    // int ans = 0;
    vector<vector<string>> ans;
    bool isValid(string s) {
        if (s[0] == '0')
            return false;
        int num = stoi(s);
        if (num >= 1 && num <= 26)
            return true;
        return false;
    }
    void backtrack(string s, int start, vector<string> stmp) {
        if (start == s.size()) {
            ans.push_back(stmp);
            return;
        }

        // 1个数字
        string tmp = s.substr(start, 1);
        if (!isValid(tmp))
            return;
        stmp.push_back(tmp);
        backtrack(s, start + 1, stmp);
        stmp.pop_back();

        if (start == s.size() - 1)
            return;
        tmp = s.substr(start, 2);
        if (!isValid(tmp))
            return;
        stmp.push_back(tmp);
        backtrack(s, start + 2, stmp);
        stmp.pop_back();
    }

    int numDecodings(string s) {
        vector<string> stmp;
        backtrack(s, 0, stmp);
        return ans.size();
    }
};
// 回溯超出时间限制 超的还不止一点两点
// 这实际上就是斐波那契数列啊！！！

int numDecodings(string s) {
    if (s[0] == '0') return 0;
    int pre = 1, curr = 1;//dp[-1] = dp[0] = 1
    for (int i = 1; i < s.size(); i++) {
        int tmp = curr;
        if (s[i] == '0')
            if (s[i - 1] == '1' || s[i - 1] == '2') 
                curr = pre;
            else 
                return 0;
        else if (s[i - 1] == '1' || (s[i - 1] == '2' && s[i] >= '1' && s[i] <= '6'))
            curr = curr + pre;
        pre = tmp;
    }
    return curr;
}

作者：pris_bupt
链接：https://leetcode-cn.com/problems/decode-ways/solution/c-wo-ren-wei-hen-jian-dan-zhi-guan-de-jie-fa-by-pr/
来源：力扣（LeetCode）
著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

int main() {
    Solution sol;
    // string s = "111111111111111111111111111111"; // 1346269
    string s = "1201234";
    int res = sol.numDecodings(s);
    return 0;
}