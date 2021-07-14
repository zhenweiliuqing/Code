#include <iostream>
#include <vector>
using namespace std;

// 有漏洞 必须最后一个是刚好跳到那个位置才行 2 5 0 0 我应该是看错了
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        vector<int> pos(n);
        pos[0] = nums[0];
        if (pos[0] >= n - 1 || n == 1)
            return true;
        for (int i = 1; i < n; i++) {
            if (pos[i - 1] >= i)
                pos[i] = max(i + nums[i], pos[i - 1]);
            else
                return false;
            //if ((pos[i] >= n - 1 && nums[n - 1] != 0) || pos[i] == n)
            if (pos[i] >= n - 1)            
                return true;
        }
        return false;
    }
};
// 打了这么多补丁 终于通过了 
// 2 5 0 0 开始把我给搞蒙了

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
// 答案还是简洁啊！！