#include <iostream>
#include <vector>
using namespace std;

// 你是一个专业的小偷，计划偷窃沿街的房屋。每间房内都藏有一定的现金，影响你偷窃的唯一制约因素就是相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 不触动警报装置的情况下 ，一夜之内能够偷窃到的最高金额。

// 状态：dp[i] 偷到第i家的最高金额
// 转移：dp[i] = (dp[i-1], dp[i-2] + nums[i]) 两种选择 不偷那就是上一家的收获 偷那就是上上家加上这一家

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int dp[n];
        dp[0] = nums[0];
        dp[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + nums[i]); // 至少不比前一天少
        }
        return dp[n - 1];
    }
};
// 执行用时0ms 可也太快了！！ 有时候是4ms
// 只需要保存前两天的状态 所以可以做一个空间优化

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        int dp0, dp1;
        dp0 = nums[0];
        dp1 = max(nums[0], nums[1]);
        for (int i = 2; i < n; i++) {
            int temp = dp1;
            dp1 = max(dp1, dp0 + nums[i]); // 至少不比前一天少
            dp0 = temp;
        }
        return dp1;
    }
};
// 通过