#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 反转字符串中每个单词的字符顺序
// 按照空格把字符串给拆分 然后反转
class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        vector<string> v;
        int st = 0;
        for (int i = 0; i < n; i++) {
            if (s[i] == ' ') {
                v.push_back(s.substr(st, i - st));
                st = i + 1;
            }
        }
        v.push_back(s.substr(st, n - st));
        for (int i = 0; i < v.size(); i++) {
            reverse(v[i].begin(), v[i].end());
        }
        string ret = "";
        for (int i = 0; i < v.size() - 1; i++) {
            ret += v[i];
            ret += ' ';
        }
        ret += v[v.size() - 1];
        return ret;
    }
};
