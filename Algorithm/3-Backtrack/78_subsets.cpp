// 1-5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 4-7 在牛课上看到的一种解法
// 刚开始就是空 
// 后来每多一个元素 就在原来的基础上加上这个元素
class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        ans.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> tmp(ans);
            for (auto it : tmp) {
                it.push_back(nums[i]);
                ans.push_back(it);
            }
        }
        return ans;
    }
};

// 传统回溯法
// for循环就是nums里的元素 不能重复就从下一个元素开始
// 递归次数就是把所有元素的个数 每次+1 最后就没有for循环了
class Solution1 {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int> v, int i) {
        ans.push_back(v);

        for (int j = i + 1; j < nums.size(); j++) {
            v.push_back(nums[j]);
            backtrack(nums, v, j);
            v.pop_back();
        }
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> v;
        backtrack(nums, v, -1);
        return ans;
    }
};
// 通过了

// 迭代法
// 1<<n 1左移n位 & 按位与
class Solution {
public:
    vector<int> t;
    vector<vector<int>> ans;

    vector<vector<int>> subsets(vector<int>& nums) {
        int n = nums.size();
        // 1左移n位就是1000 变成顺序就是
        // 000 001 010 011 100 101 110 111
        // nums[2] = 3, nums[1] = 2, nums[0] = 1
        // 哪一位为1 nums[i]就push进去
        for (int mask = 0; mask < (1 << n); ++mask) {
            t.clear();
            // 每一位 001 010 100
            for (int i = 0; i < n; ++i) {
                if (mask & (1 << i)) {
                    t.push_back(nums[i]);
                }
            }
            ans.push_back(t);
        }
        return ans;
    }
};
// 作者：LeetCode-Solution

int main() {
    Solution sol;
    vector<int> v = {1, 2, 3};
    // int ans = *min_element(v.begin(), v.end());
    sol.subsets(v);
}
