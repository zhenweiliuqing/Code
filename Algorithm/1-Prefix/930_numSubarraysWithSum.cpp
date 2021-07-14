#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 7-11
class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> map_;
        map_[0] = 1;
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            sum += nums[i - 1];
            int need = sum - goal;
            if (map_.find(need) != map_.end())
                ans += map_[need];
            ++map_[sum];
        }
        return ans;
    }
};
// 通过

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        vector<int> pre(n + 1);
        unordered_map<int, int> map_;
        map_[0] = 1;
        for (int i = 1; i <= n; ++i) {
            pre[i] = pre[i - 1] + nums[i - 1];
            map_[pre[i]]++;
        }
        int ans = 0;
        int left = 0, right = 0;
        // 0 1 1 2 2 3
        while (right <= n) {
            int sub = pre[right] - pre[left];
            if (sub == goal) {
                if (goal == 0){
                    ans += (map_[pre[left]] - 1) * map_[pre[left]] / 2;
                } else {
                    ans += map_[pre[right]] * map_[pre[left]];
                }
                int leftnum = pre[left], rightnum = pre[right];
                while (left <= n && leftnum == pre[left])
                    ++left;
                while (right <= n && rightnum == pre[right])
                    ++right;
            } else if (sub < goal) {
                ++right;
            } else if (sub > goal) {
                ++left;
            }
        }
        return ans;
    }
};
// 通过了

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int sum = 0;
        unordered_map<int, int> cnt;
        int ret = 0;
        for (auto& num : nums) {
            cnt[sum]++;
            sum += num;
            ret += cnt[sum - goal];
        }
        return ret;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/binary-subarrays-with-sum/solution/he-xiang-tong-de-er-yuan-zi-shu-zu-by-le-5caf/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        unordered_map<int, int> map_;
        // map_[0] = 1;
        int ans = 0, sum = 0;
        for (int i = 1; i <= n; ++i) {
            ++map_[sum];
            sum += nums[i - 1];
            // int need = sum - goal;
            // if (map_.find(need) != map_.end())
            ans += map_[sum - goal];
        }
        return ans;
    }
};
// 通过