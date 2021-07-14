#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<vector<int>> twoSum(vector<int> &numbers, int target, int start) {
        vector<vector<int>> ans;
        int low = start, high = numbers.size() - 1;
        while (low < high) {
            int left = numbers[low], right = numbers[high];
            int sum = left + right;
            if (sum == target) {
                ans.push_back({left, right});
                while (low < high && numbers[low] == left)
                    ++low;
                while (low < high && numbers[high] == right)
                    --high;
            } else if (sum < target) {
                while (low < high && numbers[low] == left)
                    ++low;
            } else {
                while (low < high && numbers[high] == right)
                    --high;
            } 
        }
        return ans;
    }
    
    vector<vector<int>> threeSum(vector<int>& nums, int target, int start) {
        vector<vector<int>> ans;
        for (int i = start; i < nums.size(); i++) {
            if (i > start && nums[i] == nums[i - 1])
                continue;
            vector<vector<int>> tuples = twoSum(nums, target - nums[i], i + 1);
            for (vector<int> tuple : tuples) {
                tuple.push_back(nums[i]);
                ans.push_back(tuple);
            }
        }
        return ans;
    }

    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        for (int i = 0; i < nums.size(); i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            vector<vector<int>> triples = threeSum(nums, target - nums[i], i + 1);
            for (vector<int> triple : triples) {
                triple.push_back(nums[i]);
                ans.push_back(triple);
            }
        }
        return ans;
    }
};
// 通过了 代码逻辑比threesum优化了一点