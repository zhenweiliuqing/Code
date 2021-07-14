#include <iostream>
#include <vector>
using namespace std;

// labuladong
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<vector<int>> dp(N + 1, vector<int>(W + 1), 0);
    for (int i = 1; i <= N; i++) {
        for (int w = 1; w <= W; w++) { // 这里可以优化 可以从w[i]开始 就不用下边判断放不放的下了
            if (w - wt[i - 1] < 0) // 跟N个物品重量一一比较 放不下
                dp[i][w] = dp[i - 1][w]; // 不放这个物品
            else
                dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]);
        }
        // 这个优化是错误的
        // for (int w = wt[i - 1]; w <= W; w++) { // 还是想通用的思路     
        //     // dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i - 1]] + val[i - 1]); 这个感觉不对啊
        //     dp[i][w] = max(dp[i - 1][w], dp[i - 1][w - wt[i]] + val[i]); // w = wt[i - 1]开始？ i从0开始 wt[i-1]就是第i个物品
        // }
    }
    return dp[N][W];
}
// 一定要明白dp数组的定义 明白状态转移的逻辑
// dp[i][w]是前i个物品 重量为w

// 优化空间复杂度
// 这个应该错了 参考NC145
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<int> dp(N + 1, 0);
    for (int i = 1; i <= N; i++) {
        // 这个对吗？？
        for (int w = W; w >= wt[i - 1]; w--)
            dp[w] = max(dp[w], dp[w - wt[i - 1] + val[i - 1]]);
    }
    return dp[N]; // ？ W把
}


// 自己想的 还没验证
// 4,3,[[2,3],[2,6],[4,4]]
// 输出会等于12 思路不对 不能够重复
int knapsack(int W, int N, vector<int>& wt, vector<int>& val) {
    vector<int> dp(W + 1, 0);
    for (int w = 1; w <= W; w++) {
        for (int i = 0; i < N; i++) {
            if (w - wt[i] < 0)
                continue;
            // dp[w-1] 还是 dp[w] 应该是dp[w]
            // 上一个物品放入dp[w] 可能就是最优解
            dp[w] = max(dp[w], dp[w - wt[i]] + val[i]);
        }
    }
}
// 每个w挨个试所有的物品 试完w就定住了 后续就是以之前的w状态为基础进行转移
// 二维数组纵着遍历
// 物品会重复

// 一个一个物品逐渐试所有背包 每增加一个物品 dp[w]就要进行更新 
// 其实就是二维数组横着遍历

