// 1-21
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

// 其实就是求最长上升子序列 先对一边排个序 对另一边求最长上升子序列
// 状态: dp[i] 到第i位的最长上升子序列长度
// 转移: dp[i] = max(dp[j from 0 - i-1] + 1) if (nums[i] > nums[j])

class Solution {
public:
    // 对a[0]从小到大排序 如果相等 对a[1]从大到小排序
    // 不然在计算a[1]这一列最长上升子序列会多统计 但是a[0]相等的话 a[1]还是放不进去
    static bool cmp(const vector<int> &a, const vector<int> &b) {
        return a[0] == b[0] ? a[1] > b[1] : a[0] < b[0];
    }
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0)
            return 0;
        sort(envelopes.begin(), envelopes.end(), cmp);
        int n = envelopes.size();
        int ans = 1;
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};
// 不知道为什么编译出错
// 回过头发现是少了个static 加上就通过了

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        if (envelopes.size() == 0)
            return 0;
        // 这个排序第一个升序 相等第二个降序 相等是塞不进去的
        sort(envelopes.begin(), envelopes.end(), [](const vector<int> &a, const vector<int> &b){
            return a[0] == b[0] ? a[1] > b[1]: a[0] < b[0];
        });
        int n = envelopes.size();
        int ans = 1;
        vector<int> dp(n, 1);
        dp[0] = 1;
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (envelopes[i][1] > envelopes[j][1])
                    dp[i] = max(dp[i], dp[j] + 1);
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<int>> v = {{4, 5}, {4, 6}, {6, 7}, {2, 3}, {1, 1}};
    sol.maxEnvelopes(v);
}