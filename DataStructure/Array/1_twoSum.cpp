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

// 3-25
// 牛客两数之和 是无序的
class Solution {
public:
    /**
     * 
     * @param numbers int整型vector 
     * @param target int整型 
     * @return int整型vector
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        // write code here
        vector<int> ans(2);
        vector<int> nums = numbers;
        sort(nums.begin(), nums.end());
        int left = 0, right = numbers.size() - 1;
        while (left <= right) {
            int sum = nums[left] + nums[right];
            if (sum == target)
                break;
            else if (sum < target)
                left++;
            else if (sum > target)
                right--;
        }
        
        for (int i = 0; i < numbers.size(); i++) {
            if (numbers[i] == nums[left] && ans[0] == 0)
                ans[0] = i + 1;
            else if (numbers[i] == nums[right] && ans[1] == 0)
                ans[1] = i + 1;
        }
        sort(ans.begin(), ans.end());
        return ans;
    }
};