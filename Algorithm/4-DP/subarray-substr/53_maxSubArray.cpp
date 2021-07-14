#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 状态: dp[i] 包含元素i的最大连续子数组和
// 转移: 1. 连上之前的 2. 自己独立
// 统一一下思路
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        vector<int> dp = nums;
        for (int i = 1 ; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};


class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ret = nums[0];
        vector<int> dp = nums;
        for (int i = 1; i < nums.size(); i++) { 
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            if (dp[i] > ret)
                ret = dp[i];
        }
        return ret;
    }
};
// 通过！

// 最大连续子数组和 要求连续的
// 1800 是要求上升的
// 1-19
class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans = nums[0];
        vector<int> dp(nums.size());
        dp[0] = nums[0];
        for (int i = 1 ; i < nums.size(); i++) {
            dp[i] = max(dp[i - 1] + nums[i], nums[i]);
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
//这次做有点卡住了 
// 主要是dp状态没有想清楚 dp里边存的不是当前子序列的最大值
// dp[i]有两种「选择」，要么与前面的相邻子数组连接，形成一个和更大的子数组；
// 要么不与前面的子数组连接，自成一派，自己作为一个子数组。


