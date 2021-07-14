// 1-25
#include <iostream>
#include <vector>
using namespace std;

// 这个状态转移是挺妙的 总会分成两个
// 状态: dp[i] i拆分成若干个 >= 2 正整数和的最大乘积
// 转移: dp[i] = max(dp[i-j]*j, (i-j)*j); 
// j从1开始分割 j*dp[i-j] , (i-j)*j 关键就是dp[2] dp[3]小于本身 所以这里不能直接dp[i-j]*dp[j]
// 这种思路不好解释
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        dp[1] = 1;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++)
                dp[i] = max(dp[i], max(dp[i - j] * j, (i - j) * j));
        }
        return dp[n];
    }
};

// 这个状态转移应该是当时偶然得到的
// 没想到跟剪绳子是一样的 还是理解的不够深入啊

// 4-8
// 这种方法虽然麻烦一些 但是很好理解
// dp[i] = max(dp[j] * dp[i-j]) 就是从两个状态转移而来
class Solution {
public:
    int integerBreak(int n) {
        vector<int> dp(n + 1);
        // 2 3 的最大值小于本身 单独处理
        if (n == 2)
            return 1;
        if (n == 3)
            return 2;
        // 这里dp的状态要换一下 不能小于自身 
        dp[1] = 1;
        dp[2] = 2;
        dp[3] = 3;
        // 之后的dp[n]都大于等于自身了
        for (int i = 4; i <= n; i++) {
            for (int j = 1; j < i; j++)
                dp[i] = max(dp[i], dp[j] * dp[i - j]);
        }
        return dp[n];
    }
};