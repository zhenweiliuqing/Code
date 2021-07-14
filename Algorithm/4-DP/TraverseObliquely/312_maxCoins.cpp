// 1-21
#include <iostream>
#include <vector>
using namespace std;

// 定义的很巧妙 dp[i][j] 指戳 (i, j) 气球最大硬币数
// 状态转移也很巧妙 p[i] * p[j] * p[k] = (i, j)中第k个气球最后戳的硬币数
// dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[j] * p[k]); // max(dp[i][j], - )有点熟悉 LIS 01bag coinchange1
// dp[i][j] 通过枚举不断更新
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n + 2, 1);
        // p存的是气球的硬币数 首尾为1
        for (int i = 0; i < n; i++)
            p[i + 1] = nums[i];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));
        // n = 4
        // for (int l = 1; l <= n + 1; l++) { // 1 - 5
        //     for (int i = 0; i + l <= n + 1; i++) { 
        //         int j = i + l;
        //         for (int k = i + 1; k < j; k++) {
        //             dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[j] * p[k]);
        //         }
        //     }
        // }

        // 从下往上遍历 这个好写一些
        for (int i = n; i >= 0; i--) {
            for (int j = i + 1; j < n + 2; j++) {
                // k 肯定是在 i j 之间 i j 是两端
                for (int k = i + 1; k < j; k++) {
                    // 这个是逆向思维 k是最后被戳得到的硬币数 p[i] p[j]指的是两端的气球 
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[j] * p[k]);
                }
            }
        }
        return dp[0][n + 1];
    }
};
// 通过了

class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> p(n + 2, 1);
        for (int i = 0; i < n; i++)
            p[i + 1] = nums[i];
        vector<vector<int>> dp(n + 2, vector<int>(n + 2));

        // 考虑到(i, j)均为开区间 从i j之间至少得有一个数
        // i得从倒数第三行开始 j得从i后两个数开始
        // i结束位置肯定是0 j结束位置就是n+1
        // k从i的下一个开始 到j之前结束
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 2; j < n + 2; j++) {
                for (int k = i + 1; k < j; k++) {
                    dp[i][j] = max(dp[i][j], dp[i][k] + dp[k][j] + p[i] * p[j] * p[k]);
                }
            }
        }
        return dp[0][n + 1];
    }
};

int main() {
    Solution sol;
    vector<int> v = {3, 1, 5, 8, 1};
    sol.maxCoins(v);
}