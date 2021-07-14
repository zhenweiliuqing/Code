// 1-10
#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    vector<int> ans;
    set<string> sset;
    int binary2decimal(string v) {
        int ans = 0;
        for (int i = 0; i < v.size(); i++)
            ans += pow(2, i) * (v[i] - '0');
        return ans;
    }
    void backtrack(int n, string s) {
        sset.insert(s);
        ans.push_back(binary2decimal(s));

        for (int i = 0; i < n; i++) {
            string tmp = s;
            tmp[i] = s[i] == '1' ? '0' : '1';
            if (sset.count(tmp))
                continue;
            backtrack(n, tmp);
            break;
        }
    }
    vector<int> grayCode(int n) {
        string s = "";
        for (int i = 0; i < n; i++)
            s += '0';
        backtrack(n, s);
        return ans;
    }
};
// 通过了 可以