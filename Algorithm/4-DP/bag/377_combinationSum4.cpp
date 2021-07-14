#include <vector>
using namespace std;

// 6-7
// 完全背包 nums中的值是可以重复的
// dp[w] 用nums中的元素凑成w组合的个数

// 输入：nums = [1,2,3], target = 4
// 输出：7
// 解释：
// 所有可能的组合为：
// (1, 1, 1, 1)
// (1, 1, 2)
// (1, 2, 1)
// (1, 3)
// (2, 1, 1)
// (2, 2)
// (3, 1)
// 请注意，顺序不同的序列被视作不同的组合。

class Solution {
public:
    int combinationSum4(vector<int>& nums, int target) {
        vector<unsigned int> dp(target + 1);
        dp[0] = 1;
        // 为什么需要颠倒循环顺序 
        // 这里需要考虑num的顺序 
        for (int w = 1; w <= target; w++) {
            for (int num : nums) {
                if (w - num < 0)
                    continue;
                dp[w] += dp[w - num];
            }
        }
        return dp[target];
    }
};
// 通过了 
