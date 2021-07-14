#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 就是要划3刀 判断是否符合条件
class Solution {
public:
    vector<string> ans;
    bool isValid(string s) {
        if (s.size() > 3)
            return false;
        if (s[0] == '0' && s.size() > 1)
            return false;
        int num = stoi(s);
        if (num > 255)
            return false;
        return true;
    }
    void backtrack(string s, int start, vector<string> tmp) {
        if (tmp.size() == 4) {
            if (start == s.size()) {
                string res = tmp[0];
                for (int i = 1; i < 4; i++) {
                    res += '.';
                    res += tmp[i];
                }
                ans.push_back(res);
            }
            return;
        }

        for (int i = start; i < s.size(); i++) {
            string str = s.substr(start, i - start + 1);
            if (!isValid(str))
                continue;
            tmp.push_back(str);
            backtrack(s, i + 1, tmp);
            tmp.pop_back();
        }
    }
    vector<string> restoreIpAddresses(string s) {
        vector<string> tmp;
        backtrack(s, 0, tmp);
        return ans;
    }
};
// 直接通过 卧槽 牛逼！
// 不过效率依然不高 只超过了5%