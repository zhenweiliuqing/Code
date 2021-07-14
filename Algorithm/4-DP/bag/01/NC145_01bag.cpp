// 4-2
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        vector<vector<int>> dp(n + 1, vector<int>(V + 1, 0));
        for (int i = 1; i <= n; i++) {
            for (int v = 1; v <= V; v++) {
                // 不能分开写 不能跳过装不下的
                if (v - vw[i - 1][0] < 0)
                    dp[i][v] = dp[i - 1][v];
                else 
                    dp[i][v] = max(dp[i - 1][v], dp[i - 1][v - vw[i - 1][0]] + vw[i - 1][1]);
            }
        }
        return dp[n][V];
    }
};

class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     * 计算01背包问题的结果
     * @param V int整型 背包的体积
     * @param n int整型 物品的个数
     * @param vw int整型vector<vector<>> 第一维度为n,第二维度为2的二维数组,vw[i][0],vw[i][1]分别描述i+1个物品的vi,wi
     * @return int整型
     */
    int knapsack(int V, int n, vector<vector<int> >& vw) {
        // write code here
        vector<int> dp(V + 1);
        for (int i = 1; i <= n; i++) {
            for (int v = V; v >= vw[i - 1][0]; v--) {
                dp[v] = max(dp[v], dp[v - vw[i - 1][0]] + vw[i - 1][1]);
            }
        }
        return dp[V];
    }
};