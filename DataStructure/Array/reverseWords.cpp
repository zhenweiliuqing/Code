#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        int len = s.size();
        bool ch = false;
        int st = 0, end = 0;
        string ret;
        for (int i = len - 1; i >= 0; i--) { 
            if (s[i] != ' ' && !ch) { 
                end = i;
                ch = true;
            } else if (s[i] == ' ' && ch) { 
                st = i + 1;
                ch = false;
                if (ret.size() != 0)
                    ret += " ";
                ret += s.substr(st, end - st + 1);
            }
        }
        if (ch) {
            if (ret.size() != 0)
                ret += " ";
            ret += s.substr(0, end + 1);
        }
        return ret;
    }
};