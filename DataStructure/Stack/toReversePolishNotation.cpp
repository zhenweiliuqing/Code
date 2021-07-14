// 3-24
#include <iostream>
#include <stack>
#include <string>
#include <queue>
using namespace std;

bool isOperator(char c) {
    return c == '+' || c == '-' || c == '*' || c == '/';
}

bool isGreater(char a, char b) {
    if (b == '(')
        return true;
    if (a == '*' || a == '/') {
        if (b == '+' || b == '-')
            return true;
    }
    return false;
}

// 队列存储数字 栈存储运算符
// 1. 遇到数字进队列 
// 2. 遇到运算符
//    <1> 栈为空直接进
//    <2> 优先级大于栈顶 直接进  栈顶是左括号不影响 直接进 优先级是加减乘除
//    <3> 优先级小于等于 出栈入列 然后循环
// 3. ( 直接入栈
// 4. ) 把运算符出栈入列 直到遇到 ( 扔掉

string reversePolish(string s) {
    stack<char> stk;
    queue<char> q;
    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            stk.push(s[i]);
        } else if (isalpha(s[i])) {
            q.push(s[i]);
        } else if (isOperator(s[i])) {
            if (stk.empty() || isGreater(s[i], stk.top())){
                stk.push(s[i]);
            }
            else {
                while (!stk.empty() && !isGreater(s[i], stk.top())) {
                    q.push(stk.top());
                    stk.pop();
                }
                stk.push(s[i]);
            }
        } else if (s[i] == ')') {
            while (stk.top() != '(') {
                q.push(stk.top());
                stk.pop();
            }
            stk.pop();
        }
    }
    while (!stk.empty()) {
        q.push(stk.top());
        stk.pop();
    }
    string ans;
    while (!q.empty()) {
        ans += q.front();
        q.pop();
    }
    return ans;
}





int main() {
    string str = "(a+b)*c-(a+b)/e";
    string ans = reversePolish(str);
}


