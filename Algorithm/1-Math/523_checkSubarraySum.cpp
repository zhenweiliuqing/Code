#include <vector>
#include <unordered_map>
using namespace std;

// 6-2
// 两个数的差是k的倍数 这两个数除以k的余数相同 
// 同余定理
class Solution {
public:
    // 余数 对应的前缀和下标
    unordered_map<int, int> mmap;
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        mmap[0] = 0;
        for (int i = 1; i <= n; i++) {
            int mod = pre[i] % k;
            if (mmap.count(mod) != 0 && i - mmap[mod] >= 2)
                return true;
            else if (mmap.count(mod) == 0)
                mmap[mod] = i;
        }
        return false;
    }
};
// 通过了


// 连续子数组是否为k的倍数
// 状态:dp[i][j]就是i到j的总和
// 转移:dp[i][j] = dp[i][j-1] + nums[j]
class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<vector<int>> dp(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            dp[i][i] = nums[i];
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                dp[i][j] = dp[i][j - 1] + nums[j];
                if (dp[i][j] % k == 0)
                    return true;
            }
        }
        return false;
    }
};
// 超出时间限制
// 可以用前缀和 一维的

class Solution {
public:
    bool checkSubarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        // 感觉还是O(n2)
        for (int i = 2; i <= n; i++) {
            for (int j = 0; j <= i - 2; j++) {
                if ((pre[i] - pre[j]) % k == 0)
                    return true;
            }
        }
        return false;
    }
};
// 93/94 这个还是差一点

