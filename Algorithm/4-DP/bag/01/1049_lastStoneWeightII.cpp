#include <vector>
#include <numeric>
using namespace std;

// 6-8
// 转换成01背包问题 求两堆石头的最小差值 石头总和为sum 
// 则问题转化为背包最多装sum/2的石头 这跟那个分割数组多像
class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        int sum = accumulate(stones.begin(), stones.end(), 0);
        int W = sum / 2;
        vector<vector<int>> dp(n + 1, vector<int>(W + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int w = 1; w <= W; w++) {
                if (w - stones[i - 1] < 0)
                    dp[i][w] = dp[i-1][w];
                else 
                    dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - stones[i - 1]] + stones[i - 1]);
            }
        }
        return sum - 2 * dp[n][W];
    }
};
// 通过了 但是不明白其中的道理
// 之前也分析出来应该给stones中每个数字添加 +/- 号 使得形成的表达式绝对值最小
// 进一步分析为划分为两堆石头 使得它们差值最小
// 再转化为从stones中选择 凑出总和不超过sum/2的最大值

// 这个思路求出来的是stones中两堆石头差值最小 但这个表达式是合法的吗?


class Solution {
public:
    int lastStoneWeightII(vector<int>& stones) {
        int n = stones.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = stones[i];
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i; k < j; k++) {
                    dp[i][j] = min(dp[i][j], abs(dp[i][k] - dp[k + 1][j]));
                }
            }
        }
        return dp[0][n - 1];
    }
};
// 答案错误 还是看看解析吧

