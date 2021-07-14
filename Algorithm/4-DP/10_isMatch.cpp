#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    bool helper(string s, string p, int start) {
        if (p[start] == s[start] || p[start] == '.')
            return helper(s.substr(start + 1), p.substr(start + 1), start  + 1);
        
    }

    bool isMatch(string s, string p) {
        int start = 0;
        return
    }
};