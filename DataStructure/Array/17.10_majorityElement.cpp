#include <vector>
using namespace std;

// 7-9
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int cnt = 1, cur = nums[0];
        for (int i = 1; i < nums.size(); ++i) {
            if (cnt == 0 || cur == nums[i]) {
                ++cnt;
                cur = nums[i];
            } else if (cur != nums[i]) {
                --cnt;
            }   
        }
        cnt = 0;
        for (int i : nums) {
            if (cur == i)
                ++cnt;
        }
        return cnt > nums.size() / 2 ? cur : -1;
    }
};
// 通过