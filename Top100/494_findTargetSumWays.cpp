#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int cnt = 0;
    void backtrack(vector<int>&nums, int S, int i, int sum) {
        if (nums.size() == i) { // 这个不是 size()-1
            if (sum == S)
                cnt++;
            return;
        } else {
            backtrack(nums, S, i + 1, sum + nums[i]);
            backtrack(nums, S, i + 1, sum - nums[i]);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        backtrack(nums, S, 0, 0);
        return cnt;
    }
};
// 回溯的方法基本都超出时间限制了 

// 想想动态规划怎么做
// 跟凑硬币方法数完全背包很像 都是求凑到某个数有多少种方法
// 但是这里的target可以是负数 所以要往右平移 最大和是1000 那就弄1000
// dp[i][j] i个数凑成j的方法数
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001));
        dp[0][1000] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = -1000; j <= 1000; j++) {
                if (j - nums[i - 1] >= -1000)
                    dp[i][j + 1000] += dp[i - 1][j - nums[i - 1] + 1000];  
                if (j + nums[i - 1] <= 1000)
                    dp[i][j + 1000] += dp[i - 1][j + nums[i - 1] + 1000];
            }
        }
        return S > 1000 ? 0 : dp[n][S + 1000];
    }
};
// 终于通过了 有了自己的一点思路 200ms


class Answer {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001));
        dp[0][nums[0] + 1000] = 1;
        dp[0][-nums[0] + 1000] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = -1000; j <= 1000; j++) {
                if (dp[i - 1][j] > 0) {
                    dp[i][j + nums[i - 1]] += dp[i - 1][j];
                    dp[i][j - nums[i - 1]] += dp[i - 1][j];
                }
            }
        }
    }
};
// 这个思路以dp[i-1]为主体 遍历dp table大于0的