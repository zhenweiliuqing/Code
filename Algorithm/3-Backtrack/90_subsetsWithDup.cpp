// 1-10
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 还是老问题 第一个要 后边重复的都不要
// 全排列47的时候有过这个问题 还有个题40也是不过是从i开始的
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int> tmp, int k) {
        ans.push_back(tmp);
        for (int i = k; i < nums.size(); i++) {
            // 第一个可以保留下来
            if (i != k && nums[i] == nums[i - 1])
                continue;
            tmp.push_back(nums[i]);
            backtrack(nums, tmp, i + 1);
            tmp.pop_back();

        }
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(nums, tmp, 0);
        return ans;
    }
};
// 通过了 就是个去重