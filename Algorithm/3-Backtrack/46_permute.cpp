#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 5-18
// for循环就是nums中的元素 需要注意去除重复
// 递归就是一个排列的元素数 递归的次数就是nums的size
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& tmp) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 没有重复的数字 需要跳过自身
            if (find(tmp.begin(), tmp.end(), nums[i]) != tmp.end())
                continue;
            tmp.push_back(nums[i]);
            backtrack(nums, tmp);
            tmp.pop_back();
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<int> tmp;
        backtrack(nums, tmp);
        return ans;
    }
};
// 通过了

// 3-22
// 这种用个isVisited的方式去除重复也挺好
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return ans;
        vector<bool> isVisited(n, false);
        vector<int> tmp;
        backtrack(nums, isVisited, tmp);
        return ans;
    }

    void backtrack(vector<int>& nums, vector<bool>& isVisited, vector<int>& tmp) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isVisited[i])
                continue;
            
            isVisited[i] = true;
            tmp.push_back(nums[i]);
            backtrack(nums, isVisited, tmp);
            tmp.pop_back();
            isVisited[i] = false;
        }
    }
};
// 通过了

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
            if (count(track.begin(), track.end(), nums[i])) // 关键就是这里去除重复元素
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


