#include <iostream>
#include <vector>
#include <string>
#include <unordered_set>
using namespace std;

// 1-4
// 递归就是括号的数量 一共有2n个括号 
// 每次选择就是 左括号 或 右括号
class Solution {
public:
    vector<string> ans;
    void backtrack(string& str, int left, int right, int n) {
        if (left < right || left > n || right > n)
            return;
        if (left == n && right == n) {
            ans.push_back(str);
            return;
        }
        str.push_back('(');
        backtrack(str, left + 1, right, n);
        str.pop_back();
            
        str.push_back(')');
        backtrack(str, left, right + 1, n);
        str.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        string str;
        backtrack(str, 0, 0, n);
        return ans;
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

