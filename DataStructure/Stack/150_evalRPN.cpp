// 3-24

// 逆波兰表达式求值
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int n = tokens.size();
        if (n == 1)
            return stoi(tokens[0]);
        stack<int> s;
        int i = 0;
        int ans = 0;
        while (i < n) {
            if (tokens[i][0] >= '0' && tokens[i][0] <= '9') {
                s.push(stoi(tokens[i]));
            } else if (tokens[i][0] == '-' && tokens[i][1] >= '0' && tokens[i][1] <= '9') {
                s.push(stoi(tokens[i]));
            }
            else {
                int second = s.top();
                s.pop();
                int first = s.top();
                s.pop();
                if (tokens[i][0] == '+')
                    ans = first + second;
                else if (tokens[i][0] == '-')
                    ans = first - second;
                else if (tokens[i][0] == '*')
                    ans = first * second;
                else if (tokens[i][0] == '/')
                    ans = first / second;
                s.push(ans);
            }
            i++;
        }
        return ans;
    }
};


// Leetcode
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> stk;
        int n = tokens.size();
        for (int i = 0; i < n; i++) {
            string& token = tokens[i];
            if (isNumber(token)) {
                stk.push(atoi(token.c_str()));
            } else {
                int num2 = stk.top();
                stk.pop();
                int num1 = stk.top();
                stk.pop();
                switch (token[0]) {
                    case '+':
                        stk.push(num1 + num2);
                        break;
                    case '-':
                        stk.push(num1 - num2);
                        break;
                    case '*':
                        stk.push(num1 * num2);
                        break;
                    case '/':
                        stk.push(num1 / num2);
                        break;
                }
            }
        }
        return stk.top();
    }

    bool isNumber(string& token) {
        return !(token == "+" || token == "-" || token == "*" || token == "/");
    }
};

// 之前做的 也能通过
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        for (int i = 0; i < tokens.size(); i++) {
            if (tokens[i] == "+") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a + b);    
            } else if (tokens[i] == "-") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b - a);    
            } else if (tokens[i] == "*") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(a * b);    
            } else if (tokens[i] == "/") {
                int a = s.top();
                s.pop();
                int b = s.top();
                s.pop();
                s.push(b / a);    
            } else {
                s.push(stoi(tokens[i]));
            }
        }
        return s.top();
    }
};