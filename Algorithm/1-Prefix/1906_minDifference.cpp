#include <vector>
#include <algorithm>
using namespace std;

// 6-21
// 前缀和优化
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> pre(nums.size() + 1, vector<int>(101));
        for (int i = 0; i < nums.size(); i++) {
            int c = nums[i];
            copy_n(pre[i].begin(), 101, pre[i + 1].begin()); // 把上一整行都拷贝到下一行
            pre[i + 1][c] = pre[i][c] + 1;
        }

        for (int k = 0; k < queries.size(); k++) {
            int start = queries[k][0], end = queries[k][1] + 1;
            // 从1开始遍历
            int tmpmin = INT_MAX, prenum = -1;
            for (int i = 1; i <= 100; i++) {
                if (pre[end][i] - pre[start][i] != 0) {
                    if (prenum != -1 && i - prenum < tmpmin)
                        tmpmin = i - prenum;
                    prenum = i;
                }
            }
            tmpmin = tmpmin == INT_MAX ? -1 : tmpmin;
            ans.push_back(tmpmin);
        }
        return ans;
    }
};
// 通过


// 6-20
class Solution1 {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto i : queries) {
            int start = i[0], end = i[1];
            vector<int> tmp(nums.begin() + start, nums.begin() + end + 1);
            sort(tmp.begin(), tmp.end());
            int tmpmin = INT_MAX;
            for (int i = 1; i < tmp.size(); i++) {
                if (tmp[i] == tmp[i - 1])
                    continue;
                if (tmp[i] - tmp[i - 1] < tmpmin)
                    tmpmin = tmp[i] - tmp[i - 1];
            }
            tmpmin = tmpmin == INT_MAX ? -1 : tmpmin;
            ans.push_back(tmpmin);
        }
        return ans;
    }
};
// 暴力解法 50/60

// 正确解法得用前缀和
// pre[i][c] 表示前i个元素中包含元素c的个数 i从1开始 i=0时pre为0
// pre[j + 1][c] - pre[i][c] 指的是nums[i, j]之间有多少个c
class Solution {
public:
    vector<int> minDifference(vector<int>& nums, vector<vector<int>>& queries) {
        vector<int> ans;
        vector<vector<int>> pre(nums.size() + 1, vector<int>(101));
        for (int i = 0; i < nums.size(); i++) {
            int c = nums[i];
            pre[i + 1][c] = pre[i][c] + 1;
            // 只拷贝一列 拷贝一整行也没问题的
            for (int j = i + 1; j <= nums.size(); j++)
                pre[j][c] = pre[i + 1][c];
        }

        for (int k = 0; k < queries.size(); k++) {
            int start = queries[k][0], end = queries[k][1] + 1;
            // 从1开始遍历
            int tmpmin = INT_MAX, prenum = -1;
            for (int i = 1; i <= 100; i++) {
                if (pre[end][i] - pre[start][i] != 0) {
                    if (prenum != -1 && i - prenum < tmpmin)
                        tmpmin = i - prenum;
                    prenum = i;
                }
            }
            tmpmin = tmpmin == INT_MAX ? -1 : tmpmin;
            ans.push_back(tmpmin);
        }
        return ans;
    }
};
// 46/60 我更慢了 



int main() {
    Solution sol;
    vector<int> v = {1, 3, 4, 8};
    vector<vector<int>> v2 = {{0, 1}, {1, 2}, {2, 3}};
    sol.minDifference(v, v2);
}