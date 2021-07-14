#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

class Solution {
public:
    string helper(int n) {
        if (n == 1)
            return "()";
        string ret = helper(n - 1);
        // 在所有的下一级元素里在两边加两个括号
        vector<string> cur_str;
        cur_str.push_back('(' + ret + ')');

        // 在所有下一级元素里 找空插入一对括号
    }
    // 但是这两种方法可能会有遗漏 (())(())从3到4的时候
    vector<string> generateParenthesis(int n) {
        
    }
};

// 回溯法 push pop 这一对操作结合起来就很秀
class Answer {
public:
    void backtrack(vector<string>& ans, string& cur, int open, int close, int n) {
        if (cur.size() == n * 2) {
            ans.push_back(cur);
            return;
        }
        if (open < n) {
            cur.push_back('(');
            backtrack(ans, cur, open + 1, close, n);
            cur.pop_back();
        }
        if (close < open) {
            cur.push_back(')');
            backtrack(ans, cur, open, close + 1, n);
            cur.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string current;
        backtrack(result, current, 0, 0, n);
        return result;
    }
}; 

// 回溯法 本质上是路径选择问题
class Solution {
public:
    void helper(vector<string>& ans, string& str, int open, int close, int n) {
        if (str.size() == n * 2) {
            ans.push_back(str);
            return;
        }
        // 只有两条路径 就没有for循环
        if (open < n) {
            str.push_back('('); // string也可以push_back pop_back?
            helper(ans, str, open + 1, close, n);
            str.pop_back();
            
        }
        if (close < open) {
            str.push_back(')');
            helper(ans, str, open, close + 1, n);
            str.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        vector<string> ans;
        string str = ""; // const char[1] 赋值给 string?
        helper(ans, str, 0, 0, n);
        return ans;
    }
};