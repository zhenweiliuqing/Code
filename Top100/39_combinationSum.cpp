#include <iostream>
#include <vector>
using namespace std;

// 一看这种题 就应该是 for + 递归 主要就是回溯的思想
// 无重复元素 数字可以被无限制重复选取
class Solution {
public:
    void helper(const vector<int>& candidates, int target, vector<vector<int>>& ans, vector<int>& temp, int sum, int i) {
        if (sum > target)
            return;
        if (sum == target) {
            ans.push_back(temp);
            return;
        }

        // 循环的是一个数组 所以要注意 j = i 不要重复
        // 下次还是从当前这个数开始 不用+1
        for (int j = i; j < candidates.size(); j++) { // 这样就能把重复的给去掉 不要从0开始
            temp.push_back(candidates[j]);
            sum += candidates[j];
            helper(candidates, target, ans, temp, sum, j); // 在这之前可以试一下剪枝 sum > target
            sum -= candidates[j];
            temp.pop_back();
        }
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        helper(candidates, target, ans, temp, 0, 0);
        return ans;
    }
};
// 通过了 666 去重也很重要

// 试一下剪枝的改进！！