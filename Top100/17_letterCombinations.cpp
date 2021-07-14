#include <iostream>
#include <string>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<string> ch = {"abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    vector<string> letterCombinations(string digits) {
        vector<string> ret;
        int in_digits = stoi(digits);
        int temp = 1;
        while(temp != 0) {
            temp = in_digits % 10;
            temp /= 10;
            for (int i = 0; i < ch[temp - 2].size(); i++) {

            }
        }
    }
};
// 看着很简单 就是不知道如何循环啊！

class Answer {
public:
    vector<string> letterCombinations(string digits) {
        vector<string> combinations;
        if (digits.empty())
            return combinations;
        unordered_map<char, string> phoneMap{
            {'2', "abc"},
            {'3', "def"},
            {'4', "ghi"},
            {'5', "jkl"},
            {'6', "mno"},
            {'7', "pqrs"},
            {'8', "tuv"},
            {'9', "wxyz"}};
        string combination;
        backtrack(combinations, phoneMap, digits, 0, combination);
        return combinations;
    }
    void backtrack(vector<string>& combinations, const unordered_map<char, string>& phoneMap, const string& digits, int index, string& combination) {
        if (index == digits.length())
            combinations.push_back(combination);
        else {
            char digit = digits[index];
            const string &letters = phoneMap.at(digit);
            for (const char& letter:letters) {
                combination.push_back(letter);
                backtrack(combinations, phoneMap, digits, index + 1, combination);
                combination.pop_back();
            }
        }
    }
};

// 也是用回溯法
class Solution {
public:
    unordered_map<char, string> mmap = {
        {'2', "abc"},
        {'3', "def"},
        {'4', "ghi"},
        {'5', "jkl"},
        {'6', "mno"},
        {'7', "pqrs"},
        {'8', "tuv"},
        {'9', "wxyz"}};
    void helper(vector<string>& ans, string digits, string cur, int i) {
        if (i == digits.size()) {
            ans.push_back(cur);
            return;
        }
        // for循环加递归 真的强
        // 这里循环的是不同的数组
        for (int k = 0; k < mmap[digits[i]].size(); k++){
            cur.push_back(mmap[digits[i]][k]);
            helper(ans, digits, cur, i + 1);
            cur.pop_back();
        }
    }
    
    vector<string> letterCombinations(string digits) {
        vector<string> ans;
        if (digits.size() == 0)
            return ans;
        string temp;
        helper(ans, digits, temp, 0);
        return ans;
    }
};
// 击败了100%的人也是可以的
// 还是记我自己的方法吧 简单明了 