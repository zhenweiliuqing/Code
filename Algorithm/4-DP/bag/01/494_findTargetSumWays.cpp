#include <iostream>
#include <vector>
using namespace std;

// 想想动态规划怎么做
// 跟凑硬币方法数完全背包很像 都是求凑到某个数有多少种方法 但是这个是01背包
// 但是这里的target可以是负数 所以要往右平移 最大和是1000 那就弄1000
// 状态：dp[i][j] i个数凑成j的方法数
// 转移：dp[i][j] += dp[i-1][j - nums[i]]
//       dp[i][j] += dp[i-1][j + nums[i]] 
// 默认的dp[0][1000] = 1 1000指的就是0 左右各1000 0-999指-1000~-1 1001~2001指的是1-1000

// 假如下标可以到负数
class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001));
        dp[0][0] = 1;
        // nums中的数
        for (int i = 1; i <= n; i++) {
            for (int j = -1000; j <= 1000; j++) {
                // dp[i-1]是不用这个数凑成-1000到1000的结果 加上或减去这个数凑成的结果就是dp[i][j]
                dp[i][j] += dp[i - 1][j - nums[i - 1]];  
                dp[i][j] += dp[i - 1][j + nums[i - 1]];
            }
        }
        return dp[n][S];
    }
};

class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int S) {
        int n = nums.size();
        vector<vector<int>> dp(n + 1, vector<int>(2001));
        dp[0][1000] = 1;
        for (int i = 1; i <= n; i++) {
            for (int j = -1000; j <= 1000; j++) {
                // +nums[i] 需要知道凑成j-nums[i]有多少种方法
                if (j - nums[i - 1] >= -1000)
                    dp[i][j + 1000] += dp[i - 1][j - nums[i - 1] + 1000];  
                if (j + nums[i - 1] <= 1000)
                    dp[i][j + 1000] += dp[i - 1][j + nums[i - 1] + 1000];

                // 这么做也是可以的 就是这么几种情况
                // if (j - nums[i - 1] >= -1000 && j + nums[i - 1] <= 1000)
                //     dp[i][j + 1000] = dp[i - 1][j - nums[i - 1] + 1000] + dp[i - 1][j + nums[i - 1] + 1000]; 
                // else if (j - nums[i - 1] >= -1000)
                //     dp[i][j + 1000] += dp[i - 1][j - nums[i - 1] + 1000];  
                // else if (j + nums[i - 1] <= 1000)
                //     dp[i][j + 1000] += dp[i - 1][j + nums[i - 1] + 1000];
            }
        }
        return S > 1000 ? 0 : dp[n][S + 1000];
    }
};
// 终于通过了 有了自己的一点思路 200ms

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



// 2020-4-11
// 这个好像去年通过了
class Solution {
public:
    int count = 0;
    // 不知道为什么 vector必须放在最前边
    void cauculate(vector<int>& nums, int i, int sum, int S){
        if (i == nums.size()) { // 这个可不是size - 1
            if (sum == S)
                count++; // 这后边加不加return都没什么意义
        } else {
            cauculate(nums, i + 1, sum + nums[i], S);
            cauculate(nums, i + 1, sum - nums[i], S);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        cauculate(nums, 0, 0, S);
        return count;
    }
};

class Solution {
public:
    int count = 0;
    void dfs(vector<int>& nums, int i, int sum, int S) {
        if (i == nums.size()) {
            if (sum == S) 
                count++;
            return;
        } else {
            dfs(nums, i + 1, sum + nums[i], S);
            dfs(nums, i + 1, sum - nums[i], S);
        }
    }
    int findTargetSumWays(vector<int>& nums, int S) {
        dfs(nums, 0, 0, S);
        return count;
    }
};

// class Answer {
// public:
//     int findTargetSumWays(vector<int>& nums, int S) {
//         int n = nums.size();
//         vector<vector<int>> dp(n + 1, vector<int>(2001));
//         dp[0][nums[0] + 1000] = 1;
//         dp[0][-nums[0] + 1000] = 1;
//         for (int i = 1; i <= n; i++) {
//             for (int j = -1000; j <= 1000; j++) {
//                 if (dp[i - 1][j] > 0) {
//                     dp[i][j + nums[i - 1]] += dp[i - 1][j];
//                     dp[i][j - nums[i - 1]] += dp[i - 1][j];
//                 }
//             }
//         }
//     }
// };
// 这个思路以dp[i-1]为主体 遍历dp table大于0的