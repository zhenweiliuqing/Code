#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 5-25
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            if (!dp[i])
                continue;
            for (int j = i + minJump; j <= i + maxJump && j < n; j++) {
                if (s[j] == '0')
                    dp[j] = true;
            }
        }
        return dp[n - 1];
    }
};
// 超时

// 利用前缀和进行优化
class Solution {
public:
    bool canReach(string s, int minJump, int maxJump) {
        int n = s.size();
        vector<bool> dp(n);
        vector<int> pre(n);
        dp[0] = true;
        pre[0] = 1;
        for (int i = 1; i < minJump; i++) {
            pre[i] = pre[i - 1];
        }
        for (int i = minJump; i <= maxJump; i++) {
            if (s[i] == '0') {
                dp[i] = true;
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = pre[i - 1];
            }
            
        }
        for (int i = maxJump + 1; i < n; i++) {
            if (s[i] == '0' && pre[i - minJump] - pre[i - maxJump - 1] > 0) {
                dp[i] = true;
                pre[i] = pre[i - 1] + 1;
            } else {
                pre[i] = pre[i - 1];
            }
        }
        return dp[n - 1];
    }
};
// 通过了 和答案思路一样 具体实现还是有差别 有时间再看一下