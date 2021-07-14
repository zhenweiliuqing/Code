#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 6-3
// 必须得想办法用O(n)
// map中存的是前缀和第一次出现的下标 这里把0当作-1 
// 遇到下一个一样的前缀和 j-i中间的和为0 也就是0 1个数相等
// 这种只要遍历一次就够了 
// 跟523同余定理很像
class Solution {
public:
    unordered_map<int, int> mmap;
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        int ans = 0, cnt = 0;
        mmap[0] = -1;
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1)
                cnt++;
            else
                cnt--;
            if (mmap.count(cnt) != 0)
                ans = max(i - mmap[cnt], ans);
            else if (mmap.count(cnt) == 0)
                mmap[cnt] = i;
        }
        return ans;
    }
};


// 还是有点像动态规划 得用O(n2)的方法
// 最长上升子序列 i得跟0~i-1的每个值进行一下比较 这个是可以不连续的
// 状态:dp[i][j] i-j 0的数量和1的数量
// 转移:dp[i][j] = dp[i][j-1] + 0/1的数量
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n));
        for (int i = 0; i < n; i++) {
            if (nums[i] == 0)
                dp[i][i].first = 1;
            else if (nums[i] == 1)
                dp[i][i].second = 1;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[j] == 0) {
                    dp[i][j].first = dp[i][j - 1].first + 1;
                    dp[i][j].second = dp[i][j - 1].second;
                }
                else {
                    dp[i][j].first = dp[i][j - 1].first;
                    dp[i][j].second = dp[i][j - 1].second + 1;
                }
                if (dp[i][j].first == dp[i][j].second)
                    ans = max(dp[i][j].first * 2, ans);
            }
        }
        return ans;
    }
};
// 感觉可能会超时
// 31/564

// 又得用前缀和
// pre[i]是1的个数 i+1是总元素个数
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size();
        vector<int> pre(n + 1);
        pre[0] = 0;
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        int ans = 0;
        for (int i = 2; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if ((i - j + 1) % 2 == 0 &&  pre[i] - pre[j - 1] == (i - j + 1) / 2) {
                    ans = max(ans, i - j + 1);
                    break;
                } 
            }
        }
        return ans;
    }
};
// 仍然超出时间限制 
// 32/564


