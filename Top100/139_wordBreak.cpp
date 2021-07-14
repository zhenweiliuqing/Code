#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 感觉这也不是动态规划啊
// dict可以不全用 只要有满足的就行
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        map<string, bool> dp;
        for (int i = 0; i < wordDict.size(); i++)
            dp[wordDict[i]] = false;
        while (s.size() != 0) {
            int n = s.size();
            for (int i = 0; i < wordDict.size(); i++) {
                int position = s.find(wordDict[i]);
                if (position == s.npos) 
                    continue;
                dp[wordDict[i]] = true;
                s = s.substr(0, position) + s.substr(position + wordDict[i].size()); // 那就不能这样截取了
            }
            if (n == s.size())
                return false;
        }
        return true;
    }
};

// 参考答案
// dp[i] 代表字符串的前i个字符能否被拆分
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.size();
        vector<bool> dp(n + 1);
        dp[0] = true;
        for (int i = 0; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                if (dp[j] && count(wordDict.begin(), wordDict.end(), s.substr(j, i - j))) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp[n];
    }
};
// 通过了 好好理解一下
// 这利用之前的状态确实是妙啊 我是理解错题意了 理解正确的话 也不一定做的对