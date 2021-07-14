// 1-26
#include <iostream>
#include <vector>
using namespace std;

// 这个跟戳气球好像 
// 状态 dp[i][j] 从i到j最坏情况下所需最少现金
// 转移 从中间j-i-1个数中选 dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));

// 比如求1-5需要多少现金 可以先猜个2 2肯定告诉你错了 然后你会往一个方向找 他肯定说小了 说大了那就是1 你直接就赢了
// 现在问题就转化成了猜 3-5 之间最少需要多少现金 猜个4 无论大小你都赢了 
// 所以 dp[i][j]的问题 可以由dp[i][k-1] dp[k+1][j]转换而来
class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        // BASE CASE
        // 从两个数当中选的话 就选最小的那个数就可以了 
        for (int i = 1; i < n; i++) {
            dp[i][i] = 0;
            dp[i][i + 1] = i;
        }
        dp[n][n] = 0;

        for (int i = n - 1; i >= 1; i--) {
            for (int j = i + 1; j <= n; j++) {
                // 猜i - j之间 从中间的数中一个一个开始猜
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
// 通过了 真棒！！！

class Solution {
public:
    int getMoneyAmount(int n) {
        vector<vector<int>> dp(n + 1, vector<int>(n + 1, INT_MAX));
        // BASE CASE
        for (int i = 1; i < n; i++) {
            dp[i][i] = 0;
            dp[i][i + 1] = i;
        }
        dp[n][n] = 0;

        // 边界进一步细化 
        for (int i = n - 2; i >= 1; i--) {
            for (int j = i + 2; j <= n; j++) {
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = min(dp[i][j], k + max(dp[i][k - 1], dp[k + 1][j]));
                }
            }
        }
        return dp[1][n];
    }
};
// 通过了

int main() {
    Solution sol;
    sol.getMoneyAmount(10);
}