#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

// 和438一样 就是顺序换了一下
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int left = 0, right = 0;
        vector<int> ans;
        unordered_map<char, int> mp;
        unordered_map<char, int> win;
        for (char c : s1)
            mp[c]++;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            win[c]++;
            if (mp.find(c) != mp.end() && win[c] == mp[c])
                valid++;
            right++;
            if (right - left == s1.size()) {
                if (valid == mp.size())
                    ans.push_back(left);
                char d = s2[left];
                if (mp.find(d) != mp.end() && win[d] == mp[d])
                    valid--;
                win[d]--;
                left++;
            }
        }
        return ans.size() != 0;
    }
};
// 通过了


// 判断s2是否包含s1及其排列
class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        unordered_map<char, int> target, win;
        for (int i = 0; i < s1.size(); i++)
            target[s1[i]]++;

        int left = 0, right = 0;
        int valid = 0;
        while (right < s2.size()) {
            char c = s2[right];
            right++;
            if (target.count(c) != 0) {
                win[c]++;
                if (win[c] == target[c])
                    valid++;
            }

            if (s1.size() == (right - left)) {
                if (valid == target.size())
                    return true;

                char c = s2[left];
                left++;
                if (target.count(c) != 0) {
                    if (win[c] == target[c])
                        valid--;
                    win[c]--;
                }
            }
        }
        return false;
    }
};
// 通过了 可以的