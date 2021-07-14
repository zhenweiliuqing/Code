#include <vector>
#include <algorithm>
using namespace std;

// 6-9
// 从最大值一次一个台阶一个台阶降到最小值
// 数量为50000 就是从前往后遍历 记住当前位置的大小
class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int rank = 0, min = nums[0];
        int ans = 0;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] > nums[i - 1]) 
                rank++;
            ans += rank;
        }
        return ans;
    }
};
// 通过了