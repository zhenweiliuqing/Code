#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        // erase
        // auto it = nums.begin();
        // while ( it != nums.end()) {
        //     if (*it == val)
        //         nums.erase(it);
        //     else
        //         it++;
        // }
        // return nums.size();

        // 快慢指针法
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) { // 不是val 就通过慢指针覆盖 跳过val
                nums[cnt] = nums[i];
                cnt++;
            }
        }
        return cnt;
    }
};