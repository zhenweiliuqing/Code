#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    void helper(const vector<int>& nums, vector<vector<int>>& ans, vector<int>& cnt, int i) {
        if (cnt.size() == 3) {
            int sum = cnt[0] + cnt[1] + cnt[2];
            if (sum == 0)
                ans.push_back(cnt);
            return;
        }

        for (int j = i; j < nums.size(); j++) {
            if (j > i && nums[j] == nums[j - 1]) // 去掉重复元素
                continue;
            cnt.push_back(nums[j]);
            helper(nums, ans, cnt, j + 1);
            cnt.pop_back();
        }
    }
    
    // vector<vector<int>> threeSum(vector<int>& nums) {
    //     vector<vector<int>> ans;
    //     vector<int> cnt;
    //     helper(nums, ans, cnt, 0);
    //     // 还得判断一下有没有重复元素
    //     unordered_map<int, vector<int>> mmap; // 反过来不行
    //     // unordered_set<vector<int>> sset;
    //     for (int i = 0; i < ans.size(); i++) {
    //         sort(ans[i].begin(), ans[i].end());

    //     }
    //     // 最后怎么把vector<int>这个类型给去重 卡住了 
    //     // vector内置类型是直接可以用 == 比较的
    //     return ans;
    // }

    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> cnt;
        sort(nums.begin(), nums.end());
        helper(nums, ans, cnt, 0);
        return ans;
    }
    // 这个思路应该是没错 但是超出时间限制了
};

class Answer {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;

        for (int first = 0; first < n; ++first) {
            if (first > 0 && nums[first] == nums[first - 1])
                continue;
            int third = n - 1;
            int target = -nums[first];
            for (int second = first + 1; second < n; ++second) {
                if (second > first + 1 && nums[second] == nums[second - 1])
                    continue;
                // 这个third不用再从n - 1开始了 second变大了 third也要接着原来的位置往左移
                while (second < third && nums[second] + nums[third] > target)
                    --third;
                if (second == third)
                    break;
                if (nums[second] + nums[third] == target)
                    ans.push_back({nums[first], nums[second], nums[third]});
            }
        }
        return ans;
    }
};


class Solution {
public:
    // 三重循环 for 循环 加 双指针
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> ans;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            // 把重复的给跳过
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            int target = -nums[i];
            int k = n - 1;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                while (j < k && nums[j] + nums[k] > target)
                    k--;
                if (j >= k)
                    break;
                if (nums[j] + nums[k] == target)
                    ans.push_back({nums[i], nums[j], nums[k]});
            }
        }
        return ans;
    }
};
// 主要是跳过这个操作 外边加了一个for循环 
// 剩下的和两数之和还是很像的 那个也是排了序
