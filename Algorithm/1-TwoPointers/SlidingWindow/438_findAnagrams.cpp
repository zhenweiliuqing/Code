#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 5-11
// 当没有达到p长度时 进行扩张 达到p长度时开始收缩 
// 收缩时需要判断一下当前字符串是否符合要求 
// 用个valid判断两个字符串是否相等 当某个字符数量当且仅当相同时 valid++ 
// 判断一下如果valid等于p的mp.size() 就说明这两个字符串相同
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int left = 0, right = 0;
        vector<int> ans;
        unordered_map<char, int> mp;
        unordered_map<char, int> win;
        for (char c : p)
            mp[c]++;
        int valid = 0;
        while (right < s.size()) {
            win[s[right]]++;
            char c = s[right];
            if (mp.find(c) != mp.end() && win[c] == mp[c])
                valid++;
            right++;
            if (right - left == p.size()) {
                if (valid == mp.size())
                    ans.push_back(left);
                char d = s[left];
                if (mp.find(d) != mp.end() && win[d] == mp[d])
                    valid--;
                win[d]--;
                left++;
            }
        }
        return ans;
    }
};
// 通过

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> target, win;
        for (int i = 0; i < p.size(); i++)
            target[p[i]]++;

        int left = 0, right = 0, valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (target.count(c) != 0) {
                win[c]++;
                if (win[c] == target[c])
                    valid++;
            }

            if ((right - left) == p.size()) {
                if (valid == target.size())
                    ans.push_back(left);

                char c = s[left];
                left++;
                if (target.count(c) != 0) {
                    if (win[c] == target[c])
                        valid--;
                    win[c]--;
                }
            }
        }
        return ans;
    }
};
// 这就是框架的力量