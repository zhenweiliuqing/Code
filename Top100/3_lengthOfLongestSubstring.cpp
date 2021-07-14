#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
#include <map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        // int n = s.size();
        // set<char> sset;
        // int max = 0;
        // for (int i = 0; i < n; i++) {
        //     auto it = sset.find(s[i]);
        //     // 找到了
        //     if (it != sset.end()) {
        //         if (sset.size() > max)
        //             max = sset.size();
        //         sset.clear();
        //     }
        //     sset.insert(s[i]);
        // }
        // if (sset.size() > max)
        //     max = sset.size(); // 之前哪个题有？
        // return max;

        // 思路：遇到重复的，从重复的后一位开始 但是数据结构不会实现 怎么在字符串中查找？
        // int n = s.size();
        // map<char, int> mmap;
        // int max = 0;
        // for (int i = 0; i < n; i++) {
        //     auto it = mmap.find(s[i]);
        //     if (it != mmap.end()) {
        //         if (mmap.size() > max)
        //             max = mmap.size();
                
        //     }
        // }

        int n = s.size(), max = 0;
        string temp = "";
        for (int i = 0; i < n; i++) {
            // 找到了
            int pos = temp.find(s[i]);
            if (pos != -1) {
                if (temp.size() > max)
                    max = temp.size();
                temp = temp.substr(pos + 1, temp.size() - pos - 1);
            }
            temp += s[i];
        }
        if (temp.size() > max)
            max = temp.size();
        return max;
    }
};
// 通过了 内存消耗有点大

// 滑动窗口解法
class Answer {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_set<char> occ;
        int n = s.size();
        int rk = -1, ans = 0;
        for (int i = 0; i < n; i++) {
            if (i != 0) {
                occ.erase(s[i - 1]); // 这里是每次移动一位 得一次一次挪
            }
            while (rk + 1 < n && !occ.count(s[rk + 1])) { // count为0
                occ.insert(s[rk + 1]); // 没有重复就不断插入
                rk++; // 向右移动指针
            } // 重复了就退出
            ans = max(ans, rk - i - 1); // 得到字串长度
        }
        return ans;
    }
};
