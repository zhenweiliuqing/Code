// 4-14
#include <vector>
#include <stack>
#include <iostream>
using namespace std;

class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> stk;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                stk.push(i);
            else if (s[i] == ')') {
                int start = stk.top();
                stk.pop();
                reverse(s.begin() + start + 1, s.begin() + i);
            }
        }
        string ans;
        for (int i = 0; i < s.size(); i++) {
            if (isalpha(s[i]))
                ans += s[i];
        }
        return ans;
    }
};
// 一次通过 可以的