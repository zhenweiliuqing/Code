#include <iostream>
#include <vector>
#include <stack>
using namespace std;


// 5-29
// 得用单调栈 
// 之前的思路是枚举所有的范围 求范围内的最小值
// 这个思路是确定一个最小值 求这个最小值为子数组的最长范围
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long> pre(n + 1);
        pre[0] = 0l;
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + long(nums[i]);
        // 利用单调栈 求得每个元素下一个最小值 正着求一遍 倒着求一遍
        // 求得两边第一个最小值后 就知道这个子数组得和范围了
        stack<int> stk;
        vector<long> preMin(n), nextMin(n);
        for (int i = n - 1; i >= 0; i--) {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            nextMin[i] = stk.empty() ? n : stk.top();
            stk.push(i);
        }
        while (!stk.empty())
            stk.pop();
        for (int i = 0; i <= n - 1; i++) {
            while (!stk.empty() && nums[stk.top()] >= nums[i])
                stk.pop();
            preMin[i] = stk.empty() ? -1 : stk.top();
            stk.push(i);
        }

        long maxValue = 0;
        for (int i = 0; i <= n - 1; i++) {
            maxValue = max(maxValue, (pre[nextMin[i]] - pre[preMin[i] + 1]) * nums[i]);
        }
        return maxValue % 1000000007;
    }
};
// 通过了


// 最大值由两个因素决定 一个是和 一个是最小值 
// 和肯定是越大越好 但最小值肯定不能太小
// 枚举法 得到nums的每个子数组 
// 可以用前缀和 dp[i][j] 存i-j内最小值 然后pre[j]-pre[i-1]就是[i][j]内和
class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long> pre(n + 1);
        pre[0] = 0l;
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + long(nums[i]);
        vector<vector<long>> dp(n, vector<long>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = long(nums[i]);
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = min(dp[i][j - 1], long(nums[j]));
            }
        }
        long ans = 0;
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                dp[i][j] *= (pre[j + 1] - pre[i]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans % 1000000007;
    }
};
// 超出时间限制 这个不能两次循环


class Solution {
public:
    int maxSumMinProduct(vector<int>& nums) {
        int n = nums.size();
        vector<long> pre(n + 1);
        pre[0] = 0l;
        for (int i = 0; i < n; i++)
            pre[i + 1] = pre[i] + long(nums[i]);
        vector<vector<long>> minValue(n, vector<long>(n, INT_MAX));
        vector<vector<long>> dp(n, vector<long>(n));
        long ans = 0;
        for (int i = 0; i < n; i++) {
            minValue[i][i] = long(nums[i]);
            ans = max(ans, long(nums[i] * nums[i]));
        }
        
        for (int i = n - 1; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                minValue[i][j] = min(minValue[i][j - 1], long(nums[j]));
                dp[i][j] = minValue[i][j] *  (pre[j + 1] - pre[i]);
                ans = max(ans, dp[i][j]);
            }
        }
        return ans % 1000000007;
    }
};
// 还是超出时间限制

