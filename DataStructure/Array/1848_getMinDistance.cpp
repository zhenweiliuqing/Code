#include <vector>
using namespace std;

// 5-29
// 就是从start开始找 往两边找
class Solution {
public:
    int getMinDistance(vector<int>& nums, int target, int start) {
        int n = nums.size() - 1;
        int i = start, j = start;
        while (i >= 0 && j <= n) {
            if (nums[i] == target || nums[j] == target)
                return abs(start - i);
            i--, j++;
        }
        while (i >= 0) {
            if (nums[i] == target)
                return abs(start - i);
            i--;
        }
        while(j <= n) {
            if (nums[j] == target)
                return abs(start - j);
            j++;
        }
        return 0;
    }
};
// 通过了