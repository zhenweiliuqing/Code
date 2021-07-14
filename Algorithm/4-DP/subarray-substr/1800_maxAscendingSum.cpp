#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 最大升序子数组和 要求是连续的
// 这个和53不同的一点需要判断一下是不是比之前的大 这个没有负数

// 状态: dp[i] 包含元素i的最大连续子数组
// 转移: 1. 满足上升 连上之前的 2. 自己独立
class Solution {
public:
    int maxAscendingSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp = nums;
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1])
                dp[i] = dp[i - 1] + nums[i];
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};