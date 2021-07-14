#include <iostream>
#include <vector>
using namespace std;

// 最长递增子序列 子序列不是连续的
// dp状态含义
// 包含array[i]的目标子序列（最长递增子序列）的长度是dp[i] 
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ret = 1;
        vector<int> dp(n, 1);
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[j] < nums[i])
                    dp[i] = max(dp[j] + 1, dp[i]);
            }
            ret = max(ret, dp[i]); // 需要更新 53也需要更新
        }
        return ret;
    }
};
// 通过了 

// 暴力算法是指数级的
// 动态规划是把哪些重复的运算给减去的？