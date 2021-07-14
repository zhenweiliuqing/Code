#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        dp = nums;
        int ans = dp[0];
        for (int i = 1; i < n; i++) {
            dp[i] = max(dp[i], dp[i - 1] * dp[i]); // 包含符号
            if (nums[i] != 0 && nums[i - 1] != 0)
                nums[i] = nums[i - 1] * nums[i]; // 绝对值 这还是不对 不一定是从头开始的
            ans = max(ans, nums[i], dp[i]);
        }
        return ans;
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