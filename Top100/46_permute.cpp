#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// track是路径 for循环是选择列表
// 需要维护路径 和 当前可以做的选择列表
// 触发结束条件时 将路径计入结果
class Solution {
public:
    void backtrack(vector<int>& nums, vector<vector<int>>& ans, vector<int>& track) {
        if (track.size() == nums.size()) {
            ans.push_back(track);
            return;
        }

        // 每次从0开始 但是要去掉重复的元素
        for (int i = 0; i < nums.size(); i++) {
            if (count(track.begin(), track.end(), nums[i]))
                continue;
            track.push_back(nums[i]);
            backtrack(nums, ans, track);
            track.pop_back();
        }
    }

    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> track;
        backtrack(nums, ans, track);
        return ans;
    }
};

// 通过了！ 还有一种方法是交换元素
