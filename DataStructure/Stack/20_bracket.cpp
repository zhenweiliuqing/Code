#include <iostream>
#include <stack>
#include <map>
using namespace std;

// 3-29 在牛客上通过了 
// 但是有漏洞 (}})
class Solution {
public:
    bool isValid(string s) {
        if (s.size() % 2 == 1)
            return false;
        stack<char> stk;
        unordered_map<char, char> mmap = {
            {')', '('}, {']', '['}, {'}', '{'}
        };
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                stk.push(s[i]);
            else if (!stk.empty() && mmap[s[i]] == stk.top())
                stk.pop();
        }        
        return stk.empty();
    }
};

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



class Solution {
public:
    bool isValid(string s) {
        int len = s.length();
        stack<char> temp;
        for (int i = 0; i < len; i++) {
            if (s[i] == '(' || s[i] == '[' || s[i] == '{')
                temp.push(s[i]);
            else {
                if (temp.empty())
                    return false;
                char top = temp.top();
                if (s[i] == ')' && top != '(')
                    return false;
                if (s[i] == ']' && top != '[')
                    return false;
                if (s[i] == '}' && top != '{')
                    return false;
                temp.pop();
            }
        }
        if (!temp.empty())
            return false;
        return true;
    }
};



class Solution {
public:
    bool isValid(string s) {
        map<char, char> kuohao;
        kuohao['('] = ')';
        kuohao['{'] = '}';
        kuohao['['] = ']';

        stack<char> temp;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                temp.push(s[i]);
            } 
            else if (temp.empty() || kuohao[temp.top()] != s[i]) { // 为什么temp.empty()在后边就会错呢？？？
                return false;
            } 
            else {
                temp.pop();
            }              
        }
        return temp.empty();
    }
};
