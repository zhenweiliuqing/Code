#include <iostream>
#include <vector>
using namespace std;

// 5-9
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int max = 0, cnt = 0;
        nums.push_back(0);
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                if (cnt > max)
                    max = cnt;
                cnt = 0;
            }
        }
        return max;
    }
};

// 注意最后出来也许是最长的 但是没有!= 1可以赋给max了
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int cnt = 0, max = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1)
                cnt++;
            else if (nums[i] != 1) {
                if (cnt > max)
                    max = cnt;
                cnt = 0;
            }
        }
        if (cnt > max)
            return cnt;
        return max;
    }
};
// 完成了 112ms 时间有些长