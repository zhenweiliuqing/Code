#include <iostream>
#include <unordered_map>
using namespace std;

// 把小值放在大值左边就做减法， 否则做加法
class Solution {
private:
    unordered_map<char, int> symbolValues = {
        {'I', 1},
        {'V', 5},
        {'X', 10},
        {'L', 50},
        {'C', 100},
        {'D', 500},
        {'M', 1000},
    };

public:
    int romanToInt(string s) {
        int ans = 0;
        int n = s.length();
        for (int i = 0; i < n; ++i) {
            int value = symbolValues[s[i]];
            if (i < n - 1 && value < symbolValues[s[i + 1]]) {
                ans -= value;
            } else {
                ans += value;
            }
        }
        return ans;
    }
};

// 作者：LeetCode-Solution


// 最暴力的枚举法
class Solution {
public:
    int romanToInt(string s) {
        int ans = 0;
        int idx = 0;
        
        while (idx < s.size() && s[idx] == 'M') {
            ans += 1000;
            idx++;
        }

        while (idx < s.size() && s[idx] == 'D') {
            ans += 500;
            idx++;
        }
        while (idx < s.size() && s[idx] == 'C') {
            if(idx + 1 < s.size() && s[idx + 1] == 'M') {
                ans += 900;
                idx += 2;
            } else if(idx + 1 < s.size() && s[idx + 1] == 'D') {
                ans += 400;
                idx += 2;
            } else {
                ans += 100;
                idx++;
            }
        }
        
        while (idx < s.size() && s[idx] == 'L') {
            ans += 50;
            idx++;
        }
        while (idx < s.size() && s[idx] == 'X') {
            if(idx + 1 < s.size() && s[idx + 1] == 'C') {
                ans += 90;
                idx += 2;
            } else if(idx + 1 < s.size() && s[idx + 1] == 'L') {
                ans += 40;
                idx += 2;
            } else {
                ans += 10;
                idx++;
            }
        }

        while (idx < s.size() && s[idx] == 'V') {
            ans += 5;
            idx++;
        }
        while (idx < s.size() && s[idx] == 'I') {
            if(idx + 1 < s.size() && s[idx + 1] == 'X') {
                ans += 9;
                idx += 2;
            } else if(idx + 1 < s.size() && s[idx + 1] == 'V') {
                ans += 4;
                idx += 2;
            } else {
                ans += 1;
                idx++;
            }
        }
        return ans;
    }
};