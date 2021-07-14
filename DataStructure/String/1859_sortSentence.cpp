#include <iostream>
#include <vector>
using namespace std;

// 5-26
class Solution {
public:
    string sortSentence(string s) {
        vector<string> v(9);
        s.push_back(' ');
        string tmp;
        for (char c : s) {
            if (c == ' ') {
                int i = tmp[tmp.size() - 1] - '0';
                tmp.pop_back();
                v[i - 1] = tmp;
                tmp = "";
            } else 
                tmp += c;
        }
        string ans = v[0];
        for (int i = 1; i < v.size(); i++) {
            if (v[i] == "")
                break;
            ans += ' ';
            ans += v[i];
        }
        return ans;
    }
};
// 通过了