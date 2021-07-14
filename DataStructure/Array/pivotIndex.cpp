#include <iostream>
#include <vector>
using namespace std;

// 没有用暴力算法 
// 用的是依次加 依次减 然后比较
class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        if (nums.size() == 0)
            return -1;
        int ret = -1;
        // 得到第一次的左右总和
        int sl = 0, sr = 0;
        for (int i = 1; i < nums.size(); i++)
            sr += nums[i];
        for (int i = 0; i < nums.size() - 1; i++) {
            if (sl != sr) {
                sl += nums[i];
                sr -= nums[i + 1];
            } else {
                ret = i;
                break;
            }
        }
        if (sl == sr && ret == -1)
            ret = nums.size() -1;
        return ret;
    }
};
// 通过！
// 参考答案用整个的sum - sl - x得到sr 也是可以啊 