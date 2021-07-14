// 1-23
#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// dp[i][j] 为i到j之间Alice得到的最大分数 base case dp[i][i] = 0
// 转移 总共有 j - i 个选择 找到 min(abs(sum[i][k] - sum[k][j]))
// dp[i][j] = min(sum[i][k], sum[k][j]) + dp[i][k]/dp[k][j]; 看前面哪个小后边就取对应的
class Solution1 {
public:
    vector<vector<int>> sumMemo;
    void sumCalculate(vector<int> nums) {
        int n = nums.size();
        sumMemo.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            sumMemo[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                sumMemo[i][j] = nums[j] + sumMemo[i][j - 1];
            }
        }
    }
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sumCalculate(stoneValue);
        vector<vector<int>> dp(n, vector<int>(n));
        // 我去 动态规划竟然还不是时间最优的 这里有好多状态其实不必要算
        // 到底减少了多少计算量？？
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                for (int k = i; k < j; k++) {
                    if (sumMemo[i][k] < sumMemo[k + 1][j] || (sumMemo[i][k] == sumMemo[k + 1][j] && dp[i][k] >= dp[k + 1][j]))
                        dp[i][j] = max(dp[i][j], sumMemo[i][k] + dp[i][k]); // 如果进这里 那dp[k + 1][j]就不用算
                    else if (sumMemo[i][k] > sumMemo[k + 1][j] || (sumMemo[i][k] == sumMemo[k + 1][j] && dp[i][k] < dp[k + 1][j]))
                        dp[i][j] = max(dp[i][j], sumMemo[k + 1][j] + dp[k + 1][j]);
                }

                // 这种局部最优不一定是全局最优?
                // 2 2 2 2 | 7 这里分不是最优！！
                // int min = sumMemo[i][j], mink;
                // for (int k = i; k < j; k++) { 
                //     int tmp = abs(sumMemo[i][k] - sumMemo[k + 1][j]);
                //     if (tmp < min) {
                //         min = tmp;
                //         mink = k;
                //     }
                // }
                // if (sumMemo[i][mink] < sumMemo[mink + 1][j] || (sumMemo[i][mink] == sumMemo[mink + 1][j] && dp[i][mink] >= dp[mink + 1][j]))
                //     dp[i][j] = sumMemo[i][mink] + dp[i][mink];
                // else if (sumMemo[i][mink] > sumMemo[mink + 1][j] || (sumMemo[i][mink] == sumMemo[mink + 1][j] && dp[i][mink] < dp[mink + 1][j]))
                //     dp[i][j] = sumMemo[mink + 1][j] + dp[mink + 1][j];
            }
        }
        return dp[0][n - 1];
    }
};
// 解答错误 感觉很奇怪 思路有误？ 局部最优不一定是全局最优 
// 还是超出时间限制了

// C++时间不友好 下一步试试java
class Solution2 {
public:
    vector<vector<int>> sumMemo;
    vector<vector<int>> dp;
    void sumCalculate(vector<int> nums) {
        int n = nums.size();
        sumMemo.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            sumMemo[i][i] = nums[i];
            for (int j = i + 1; j < n; j++) {
                sumMemo[i][j] = nums[j] + sumMemo[i][j - 1];
            }
        }
    }
    int dfs(const vector<int>& nums, int left, int right) {
        if (left == right)
            return 0;
        if (dp[left][right])
            return dp[left][right];
        for (int i = left; i < right; i++) {
            int suml = sumMemo[left][i], sumr = sumMemo[i + 1][right];
            if (suml < sumr)
                dp[left][right] = max(dp[left][right], suml + dfs(nums, left, i));
            else if (sumr < suml)
                dp[left][right] = max(dp[left][right], sumr + dfs(nums, i + 1, right));
            else
                dp[left][right] = max(dp[left][right], suml + max(dfs(nums, left, i), dfs(nums, i + 1, right)));
        }
        return dp[left][right];
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sumCalculate(stoneValue);
        dp.assign(n, vector<int>(n)); // 和resize的区别？
        return dfs(stoneValue, 0, n - 1);
    }
};
// 还是超时 估计还没上一个快
// vector<int>& nums 通过了

class Solution {
private:
    vector<vector<int>> dp;
public:
    int dfs(const vector<int>& nums, int left, int right) {
        if (left == right)
            return 0;
        if (dp[left][right])
            return dp[left][right];
        int sum = accumulate(nums.begin() + left, nums.begin() + right + 1, 0);
        int suml = 0;
        for (int i = left; i < right; i++) {
            suml += nums[i];
            int sumr = sum - suml;
            // 自顶向下 只计算了一半的状态 只有两个相等时才会两边都计算
            if (suml < sumr)
                dp[left][right] = max(dp[left][right], suml + dfs(nums, left, i));
            else if (sumr < suml)
                dp[left][right] = max(dp[left][right], sumr + dfs(nums, i + 1, right));
            else
                dp[left][right] = max(dp[left][right], suml + max(dfs(nums, left, i), dfs(nums, i + 1, right)));
        }
        return dp[left][right];
    }
    
    int stoneGameV(vector<int>& stoneValue) {
        int n = stoneValue.size();
        dp.assign(n, vector<int>(n)); // 和resize的区别？
        return dfs(stoneValue, 0, n - 1);
    }
};
// 改为const vector<int>& nums 就通过了！！！


int main() {
    Solution sol;
    // vector<int> v = {6, 2, 3, 4, 5, 5};
    // vector<int> v = {1, 1, 2};
    vector<int> v = {68, 75, 25, 50, 34, 29, 77, 1, 2, 69};
    sol.stoneGameV(v);
}