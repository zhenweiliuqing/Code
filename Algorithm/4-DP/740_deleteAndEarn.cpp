#include <iostream>
#include <vector>
using namespace std;

// 这个和打家劫舍真的一样啊 首先把给出的nums 转成打家劫舍中的nums

// 状态 dp[i] 偷到第i家的最大金额
// 转移 这个题目的要求是选了i 就不能选择i-1 i+1 
// 打家劫舍要求你抢了这一家 就不能抢上一家 同理 如果要抢下一家 就不能抢你
class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        int maxV = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] > maxV)
                maxV = nums[i];
        }
        vector<int> v(maxV + 1);
        for (int i = 0; i < n; i++) {
            v[nums[i]] += nums[i];
        }

        vector<int> dp(maxV + 1);
        dp[0] = v[0];
        dp[1] = max(v[0], v[1]);
        for (int i = 2; i <= maxV; i++) {
            dp[i] = max(dp[i - 1], dp[i - 2] + v[i]);
        }
        return dp[maxV];
    } 
};
// 通过了
