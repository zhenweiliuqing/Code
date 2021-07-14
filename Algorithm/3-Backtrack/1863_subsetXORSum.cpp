#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

// 5-21
// 这个就是求子集 有三种方法 
// 回溯 位运算 和这种迭代
class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        vector<vector<int>> subset;
        subset.push_back({});
        for (int i = 0; i < nums.size(); i++) {
            vector<vector<int>> tmp = subset;
            for (int j = 0; j < tmp.size(); j++) {
                tmp[j].push_back(nums[i]);
                subset.push_back(tmp[j]);
            }
        }
        int ans = 0;
        for (int i = 0; i < subset.size(); i++) {
            int tmp = 0;
            for (int j = 0; j < subset[i].size(); j++) {
                tmp ^= subset[i][j];
            }
            ans += tmp;
        }
        return ans;
    }
};
// 通过


