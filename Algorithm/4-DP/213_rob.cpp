#include <iostream>
#include <vector>
using namespace std;

// 你是一个专业的小偷，计划偷窃沿街的房屋，每间房内都藏有一定的现金。这个地方所有的房屋都 围成一圈 ，
// 这意味着第一个房屋和最后一个房屋是紧挨着的。同时，相邻的房屋装有相互连通的防盗系统，
// 如果两间相邻的房屋在同一晚上被小偷闯入，系统会自动报警 。
// 给定一个代表每个房屋存放金额的非负整数数组，计算你 在不触动警报装置的情况下 ，能够偷窃到的最高金额。

// 状态和转移与198题一样
// 这个题主要就是分成两段 取最大值即可

class Solution {
public:
    int rob(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        if (n == 1)
            return nums[0];
        if (n == 2)
            return max(nums[0], nums[1]);
        
        // 分为两段计算 取个最值 
        int dp1[n - 1];
        dp1[0] = nums[0];
        dp1[1] = max(nums[0], nums[1]);
        for (int i = 2; i < n -1; i++)
            dp1[i] = max(dp1[i - 1], dp1[i - 2] + nums[i]); // 至少不比前一天少

        int dp2[n - 1];
        dp2[0] = nums[1];
        dp2[1] = max(nums[1], nums[2]);
        for (int i = 2; i < n - 1; i++)
            dp2[i] = max(dp2[i - 1], dp2[i - 2] + nums[i + 1]);
        return max(dp1[n - 2], dp2[n - 2]);
    }
};
// 通过了 