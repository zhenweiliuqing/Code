#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// 5-31
class Solution {
public:
    int minPairSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int ans = 0, n = nums.size();
        for (int i = 0; i <= n / 2 - 1; i++) {
            ans = max(ans, nums[i] + nums[n - i - 1]);
        }
        return ans;
    }
};
// 通过
