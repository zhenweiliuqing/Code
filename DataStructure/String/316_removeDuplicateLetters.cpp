#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

class Solution {
public:
    string removeDuplicateLetters(string s) {
        unordered_map<char, int> string_map, stack_map;
        stack<char> sk;

        for (int i = 0; i < s.size(); i++) {
            string_map[s[i]]++;
        }

        for (int i = 0; i < s.size(); i++) {
            char c = s[i];
            string_map[c]--;
            if (stack_map[c] != 0) // "abacb" 如果现在不能颠覆之前的 就跳过
                continue;
            
            // 该怎么实现单调栈
            // "bacbc" 如果可以颠覆之前的 就把之前的pop出去
            while (!sk.empty() && c < sk.top()) {
                if (string_map[sk.top()] == 0)
                    break;
                stack_map[sk.top()]--;
                sk.pop();
            }
            sk.push(c);
            stack_map[c]++;
        }

        string ans = "";
        while (!sk.empty()) {
            ans = sk.top() + ans;
            sk.pop();
        }
        return ans;
    }
};

// 通过了

int main() {
    Solution solution;
    string ans = solution.removeDuplicateLetters("acbbc");
}