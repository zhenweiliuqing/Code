#include <iostream>
#include <vector>
using namespace std;

// 一看这种题 就应该是 for + 递归 主要就是回溯的思想
// 无重复元素的candidates 找出数字和等于target
// 1. 每一步循环就是这个数组 说明每一步的选择就是数组中的元素 下一步的选择从j开始
// 2. 一共有多少步 总的步数由sum和target决定 直到满足条件为止

// 5-18
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int idx, vector<int>& tmp, int sum, int target) {
        if (sum > target)
            return;
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }
        for (int i = idx; i < candidates.size(); i++) {
            tmp.push_back(candidates[i]);
            sum += candidates[i];
            backtrack(candidates, i, tmp, sum, target);
            sum -= candidates[i];
            tmp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int> tmp;
        backtrack(candidates, 0, tmp, 0, target);
        return ans;
    }
};


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
        // 需要有重复的元素 就不用+1 还是从这个数开始
        for (int j = i; j < candidates.size(); j++) { // 这样就能把重复的给去掉 不要从0开始
            temp.push_back(candidates[j]);
            helper(candidates, target, ans, temp, sum + candidates[j], j); // 在这之前可以试一下剪枝 sum > target
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
