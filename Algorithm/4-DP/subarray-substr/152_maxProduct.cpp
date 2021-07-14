#include <iostream>
#include <vector>
using namespace std;

// 就用这个答案
// 状态：maxp[i] 乘上nums[i]的最大值 要包含nums[i]
// 转移：1. 整数 可以乘上之前的最大值maxp[i- 1]
//       2. 负数 可以乘上之前的最小值
//       3. 本身
class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> maxp(nums);
        vector<int> minp(nums);
        int ans = nums[0];
        for (int i = 1; i < n; i++) {
            maxp[i] = max(nums[i], max(minp[i - 1] * nums[i], maxp[i - 1] * nums[i]));
            minp[i] = min(nums[i], min(maxp[i - 1] * nums[i], minp[i - 1] * nums[i]));
            ans = max(ans, maxp[i]);
        }
        return ans;
    }
};
// 通过了 12ms

// 看一下答案
// 大致思路就是维护一个最大的 再维护一个最小的
class Answer {
public:
    int maxproduct(vector<int>& nums) {
        int maxans = -99999999, imax = 1, imin = 1;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] < 0) {
                int temp = imax;
                imax = imin;
                imin = temp;
            }
            imax = max(imax * nums[i], nums[i]);
            imin = min(imin * nums[i], nums[i]);
            maxans = max(maxans, imax);
        }
        return maxans;
    }
};


// 想到了回文子串的方法
class Solution {
public:
    int mul(const vector<int>&nums, int st, int end) {
        int ans = 1;
        for (int i = st; i <= end; i++)
            ans *= nums[i];
        return ans;
    }
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            dp[i][i] = nums[i];
        }
        for (int l = 1; l < n; l++) {
            for (int i = 0; i + l < n; i++) {
                int j = i + l;
                dp[i][j] = max(mul(nums, i, j), max(dp[i][j - 1], dp[i + 1][j]));
            }
        }
        return dp[0][n - 1];
    }
};
// 这个逻辑上应该是没什么错误 但是超出时间限制了




