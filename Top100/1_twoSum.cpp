#include <iostream>
#include <vector>
#include <map>
using namespace std;

class Solution {
public:
    // 暴力法
    vector<int> twoSum(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> ret;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (nums[i] + nums[j] == target) {
                    ret = {i, j};
                }
            }
        }
        return ret;
    }

    // 用map
    vector<int> twoSum1(vector<int>& nums, int target) {
        map<int, int> m;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            m[nums[i]] = i; // 建立索引
        }
        for (int i = 0; i < n; i++) {
            auto it = m.find(target - nums[i]);
            if (it != m.end() && m[target - nums[i]] != i)
                return {i, m[target - nums[i]]}; // 这个为什么可以转换成vector
        }
        return {0, 0};
    }
    // 一次遍历也是可以的 因为有两个数 第一次不存在的时候push进去 在后边的时候前面已经存在了
};

