#include <vector>
using namespace std;

// 6-10
class Solution {
public:
    int arraySign(vector<int>& nums) {
        if (find(nums.begin(), nums.end(), 0) != nums.end())
            return 0;
        int cnt = 0;
        for (int num : nums) {
            if (num < 0)
                cnt++;
        }
        return cnt % 2 == 0 ? 1 : -1;
    }
};
// 通过了