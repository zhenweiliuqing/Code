#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;

// 3-29
// 用这个答案
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        stack<char> bracket;
        map<char, char> mmap = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        for (int i = 0; i < s.length(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{') // 左括号push进去
                bracket.push(s[i]);
            else if (bracket.empty() || mmap[s[i]] != bracket.top()) // 左右括号不匹配
                return false;
            else
                bracket.pop();
        }
        return bracket.empty();
    }
};


class Answer {
public:
    bool isValid(string s) {
        int n = s.size();
        if (n % 2 == 1)
            return false;
        unordered_map<char, char> pairs = {
            {')', '('},
            {']', '['},
            {'}', '{'}};
        stack<char> stk;
        for (char ch : s) {
            if (pairs.count(ch)) { // map.count(key)
                if (stk.empty() || stk.top () != pairs[ch])
                    return false;
                stk.pop();
            } else {
                stk.push(ch);
            }
        }
        return stk.empty();
    }
};


// 对于右括号 到底怎么办？
// class Solution {
// public:
//     bool isValid(string s) {
//         stack<char> sk;
//         if (s[0] == ')' || s[0] == ']' || s[0] == '}' || s.size() % 2 != 0)
//             return false;
//         for (int i = 0; i < s.size(); i++) {
//             if (s[i] == '(' || s[i] == '[' ||  s[i] == '{') {
//                 sk.push(s[i]);
//             }
//             else {
//                 if (sk.empty() || (s[i] == ')' && sk.top() != '(') || (s[i] == ']' && sk.top() != '[') || (s[i] == '}' && sk.top() != '{'))
//                     return false;
//                 sk.pop();
//             }
//         }
//         if (sk.empty())
//             return true;
//         return false;
//     }
// };
// 终于通过了 真是猫捉老鼠
// 还有一点需要注意s[i]是ASCII值？

