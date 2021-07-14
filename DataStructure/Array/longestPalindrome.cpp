#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if (s.size() <= 1)
            return s;
        else if (s.size() == 2) {
            if (s[0] == s[1])
                return s;
            else 
                return s.substr(0, 1);
        }
        int len = s.size();
        string ret = "";
        for (int i = 1; i < len - 1; i++) { 
            int left = i - 1, right = i + 1;
            if (s[i] == s[left]) 
                left--;
            if (s[i] == s[right])
                right++;
            while (left >= 0 && right < len) { 
                if (s[left] != s[right]) {
                    if (ret.size() < right - left - 1)
                        ret = s.substr(left + 1, right - left - 1);
                    break;
                }
                left--;right++;
            }
            if (left == 0 || right == len - 1) { 
                if (ret.size() < right - left + 1)
                        ret = s.substr(left, right - left + 1);
            }
        }
        return ret;
    }
};

class Answer {
public:
    pair<int, int> expandAroundCenter(const string &s, int left, int right) {
        while (left >= 0 && right < s.size() && s[left] == s[right]) {
            --left;
            ++right;
        }
        return {left + 1, right - 1};
    }
    string longestPalindrome(string s) {
        int start = 0, end = 0;
        for (int i = 0; i < s.size(); i++) {
            auto [left1, right1] = expandAroundCenter(s, i, i);
            auto [left2, right2] = expandAroundCenter(s, i, i + 1);
            if (right1 - left1 > end - start) {
                start = left1;
                end = right1;
            }
            if (right2 - left2 > end - start) {
                start = left2;
                end = right2;
            }
        }
        return s.substr(start, end - start + 1);
    }
};