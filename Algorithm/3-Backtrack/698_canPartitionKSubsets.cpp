// 1-19
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool backtrack(vector<int>& nums, int k, vector<bool> isUsed, int start, int bucketsum, int sum) {
        if (k == 1)
            return true;
        if (bucketsum == sum)
            return backtrack(nums, k - 1, isUsed, 0, 0, sum);
        for (int i = start; i < nums.size(); i++) {
            // 不能超过sum
            if (!isUsed[i] && bucketsum + nums[i] <= sum) { 
                isUsed[i] = true;
                if (backtrack(nums, k, isUsed, i + 1, bucketsum + nums[i], sum))
                    return true;
                isUsed[i] = false;
            }
        }
        return false;
    }

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0;
        // sort(nums.begin(), nums.end()); 不能排序 为什么?
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (k == 0 || sum % k != 0)
            return false;
        vector<bool> isUsed(nums.size());
        return backtrack(nums, k, isUsed, 0, 0, sum / k);
    }
};
// 有一个细节没有注意到 不能超过sum

int main() {
    Solution sol;
    vector<int> v = {5, 2, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 5, 3};
    int k = 15;
    sol.canPartitionKSubsets(v, k);
}
