#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[cnt] == 0 && nums[i] != 0) {
                swap(nums[cnt], nums[i]);
                cnt++;
            } else if (nums[cnt] != 0)
                cnt++;
        }
    }
};
// 通过了 思路还可以

class Answer {
public: 
    void moveZeros(vector<int>& nums) {
        for (int cnt = 0, cur = 0; cur < nums.size(); cur++) {
            if (nums[cur] != 0)
                swap(nums[cnt++], nums[cur]);
        }
    }
};
// 有很多自己跟自己交换的