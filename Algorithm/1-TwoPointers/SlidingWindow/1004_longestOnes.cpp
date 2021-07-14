#include <iostream>
#include <vector>
using namespace std;

// 5-11
// 问题转化为寻找最长子串 限制条件为最多允许k个0 这就变成了滑动窗口的问题
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int left = 0, right = 0;
        int ans = 0, cnt = 0;
        while (right < nums.size()) {
            if (nums[right] == 0)
                cnt++;
            while (cnt > k) {
                if (nums[left] == 0)
                    cnt--;
                left++;
            }
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};

// 太麻烦了 别看了
class Solution {
public:
    // 先找到最长的那一段 
    // 看看相邻的两段1 有多少个零 如果连接不上就返回最长+k
    // 能连接上就选择最长的那段1 
    // 然后进入递归 k更新为剩余的次数
    // 不对 不一定是贪心算法 也可能是几块小的连起来变成大的 
    // 思路错了
    // 双指针怎么双？
    int longestOnes(vector<int>& nums, int k) {
        int maxst = 0, maxend = 0;
        nums.push_back(0);
        int maxlen = 0, cnt = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] == 1) {
                cnt++;
            } else {
                if (cnt > maxlen) {
                    maxlen = cnt;
                    maxend = i - 1;
                    maxst = maxend - maxlen + 1;
                }
                cnt = 0;
            }
        }

        int left0s = 0, left1s = 0;
        int cnt = 0;
        bool count0 = true;
        for (int i = maxst - 1; i >= 0; i--) {
            if (count0) {
                if (nums[i] == 0)
                    cnt++;
                else {
                    left0s = cnt;
                    cnt = 1;
                    count0 = false;
                }
            } else {
                if (nums[i] == 1)
                    cnt++;
                else {
                    left1s = cnt;
                    break;
                }
            }
        }
        if (count0) 
            left0s = cnt;
        else 
            left1s = cnt;
        
        int right0s = 0, right1s = 0;
        cnt = 0;
        count0 = true;
        for (int i = maxend + 1; i < nums.size(); i++) {
            if (count0) {
                if (nums[i] == 0)
                    cnt++;
                else {
                    right0s = cnt;
                    cnt = 1;
                    count0 = false;
                }
            } else {
                if (nums[i] == 1)
                    cnt++;
                else {
                    right1s = cnt;
                    break;
                }
            }
        }
        if (count0) 
            right0s = cnt;
        else 
            right1s = cnt;
    }
};