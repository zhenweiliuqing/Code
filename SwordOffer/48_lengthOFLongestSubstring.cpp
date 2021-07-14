// 3-5
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <unordered_map>
using namespace std;

// 这个就是滑动窗口
// 测试用例:
// bbbbb
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int n = s.size();
        if (n == 0)
            return 0;
        int left = 0, right = 0, ans = 1;
        map<char, int> win;
        bool flag = false;

        while (right < n) {
            win[s[right]]++;
            if (win[s[right]] > 1)
                flag = true;

            // 开始缩减窗口
            // left < right 没用 
            while (left < right && flag) {
                // 如何直接判断这个窗口内有重复元素
                if (win[s[left]] == 2) {
                    flag = false;
                }
                win[s[left]]--; // 得把之前的都减掉
                left++;
            }
            right++;
            ans = max(ans, right - left);
        }
        return ans;
    }
};
// 通过了 

// 之前的方法 labuladong
int length(string s) {
    unordered_map<char, int> window;

    int left = 0, right = 0;
    int res = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        window[c]++;

        // 当有了重复元素就在当前进行判断
        while (window[c] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }
        res = max(res, right - left);
    }
    return res;
}
