#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 就是记录一个最远到达的位置 如果i到达不了这个位置 那就是false 如果能到达最后一个位置 就是true
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int maxPos = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i <= maxPos) {
                maxPos = max(maxPos, i + nums[i]);
                if (maxPos >= n - 1)
                    return true;
            } else 
                return false;
        }
        return false;
    }
};

class Answer {
public:
    bool canJump(vector<int> &nums) {
        int n = nums.size();
        int rightmost = 0;
        for (int i = 0; i < n; i++)
        {
            if (i <= rightmost)
            {
                rightmost = max(rightmost, i + nums[i]);
                if (rightmost >= n - 1)
                    return true;
            }
        }
        return false;
    }
};


