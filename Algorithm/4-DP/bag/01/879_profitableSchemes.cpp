#include <vector>
#include <numeric>
using namespace std;

// 6-10
class Solution {
public:
    // 转移dp[i][j][k] = dp[i-1][j-group[i]][k-profit[i]]
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        const int mod = 1e9+7;
        int tasks = group.size();
        vector<vector<vector<int>>> dp(tasks + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
        for (int i = 0; i <= n; i++)
            dp[0][i][0] = 1;
        for (int i = 1; i <= tasks; i++) {
            // 这俩得从0开始
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    if (j - group[i-1] < 0)
                        dp[i][j][k] = dp[i-1][j][k];
                    else
                        // 不放这个有多少种方法 + 放这个有多少种方法
                        // 放这个有多少种方法k至少得从0开始 利润k-profit[i-1]这是个底线 往上肯定是符合要求的
                        dp[i][j][k] = (dp[i-1][j][k] + dp[i-1][j-group[i-1]][max(0, k-profit[i-1])]) % mod;
                }
            }
        }
        return dp[tasks][n][minProfit];
    }
};
// 通过了


// 6-9
// 这不是01背包问题吗 占用n个人 求产生多少利润 但是这里求的是产生超过minProfit的方法 最后把超过minProfit的加起来就行了
// 状态: dp[i][j] 用i个人达到j的利润有多少种方法 如果 j >= minProfit 就累加
// 转移: dp[i][j] += dp[i-group[i]][j - profit[i]];
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int sum = accumulate(profit.begin(), profit.end(), 0);
        vector<vector<int>> dp(n + 1, vector<int>(sum + 1));
        dp[0][0] = 1;
        // 感觉思路不复杂 就是没想清楚
        // i要是用了人数 就没法得到group[i] 我的状态和转移矛盾了
        for (int i = 0; i < group.size(); i++) {
            for (int j = 1; j <= sum; j++) {
            }
        }
    }
};

// 有人数和利润两个限制 得用三维数组
// 状态:dp[i][j][k]前i个工作量 恰好使用j个员工 获得利润至少为k的方法 注意恰好和至少 那么初始情况只有dp[0][0][0]=1
// 如果是使用不超过j个员工 初始化需要dp[0][j][0]=1

// 这个跟之前做的还不是太一样 这个里面有至少 所以要把dp[i-1][j][k]的方法也算上 
// 之前都是 += 因为完全背包是一维的 494有两种情况
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int len = group.size(), MOD = (int)1e9 + 7;
        vector<vector<vector<int>>> dp(len + 1, vector<vector<int>>(n + 1, vector<int>(minProfit + 1)));
        dp[0][0][0] = 1;
        for (int i = 1; i <= len; i++) {
            int members = group[i - 1], earn = profit[i - 1];
            for (int j = 0; j <= n; j++) {
                for (int k = 0; k <= minProfit; k++) {
                    if (j < members) {
                        dp[i][j][k] = dp[i - 1][j][k];
                    } else {
                        // 定义的第三维是工作利润至少为 k 而不是 工作利润恰好为 k 没体会到至少的意思
                        // members = 2则dp[1][2][0] = dp[0][2][0] + dp[0][0][0]
                        dp[i][j][k] = (dp[i - 1][j][k] + dp[i - 1][j - members][max(0, k - earn)]) % MOD;
                    }
                }
            }
        }
        int sum = 0;
        for (int j = 0; j <= n; j++) {
            sum = (sum + dp[len][j][minProfit]) % MOD;
        }
        return sum;
    }
};
// 定义的状态还不是很明白

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/profitable-schemes/solution/ying-li-ji-hua-by-leetcode-solution-3t8o/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。