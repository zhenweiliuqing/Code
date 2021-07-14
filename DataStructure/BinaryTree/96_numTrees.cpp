#include <iostream>
#include <vector>
#include <map>
using namespace std;

// 4-23
class Solution {
public:
    int numTrees(int n) {
        // int dp[] = new int[n];
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j < i; j++) {
                dp[i] += dp[j] * dp[i - j - 1];
            }
        }
        return dp[n];
    }
};
// 通过了

class Solution {
public:
    int numTrees(int n) {
        if (n == 0)
            return 1;
        if (n == 1 || n == 2)
            return n;
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += numTrees(i) * numTrees(n - i - 1);
        return ans;
    }
};
// 通过了 ans不能是全局变量 1636ms
// 用memo优化一下

class Solution {
public:
    map<int, int> memo;
    int numTrees(int n) {
        if (n == 0)
            return 1;
        if (n == 1 || n == 2)
            return n;
        if (memo.count(n) != 0)
            return memo[n];
        int ans = 0;
        for (int i = 0; i < n; i++)
            ans += numTrees(i) * numTrees(n - i - 1);
        memo[n] = ans;
        return ans;
    }
};
// 0ms 这也太秀了

// 动态规划
class Solution {
public:
    int numTrees(int n) {
        vector<int> G(n + 1, 0);
        G[0] = 1;
        G[1] = 1;

        for (int i = 2; i <= n; ++i) {
            for (int j = 1; j <= i; ++j) {
                G[i] += G[j - 1] * G[i - j];
            }
        }
        return G[n];
    }
};