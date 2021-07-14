// 2-25
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 这个就是回溯 string里应该会有重复元素
// 忘记了labuladong是怎么在全排列跳过重复元素的 
// 怎么避免重复呢？最后用set做一个拦截

// 这和47就是一样的
class Solution {
public:
    vector<string> ans;
    void backtrack(vector<char>& str, string tmp, vector<int>& index) {
        if (tmp.size() == str.size()) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < str.size(); i++) {
            // 需要用一个index存储下标 跳过自己
            if (count(index.begin(), index.end(), i))
                continue;
            index.push_back(i);
            tmp += str[i];
            backtrack(str, tmp, index);
            tmp.pop_back();
            index.pop_back();
            // 需要保留一个 跳过其他重复的
            while (i + 1 < str.size() && str[i] == str[i + 1])
                i++;
        }
    }

    vector<string> permutation(string s) {
        if (s.size() == 0)
            return ans;
        vector<char> str;
        for (int i = 0; i < s.size(); i++)
            str.push_back(s[i]);
        sort(str.begin(), str.end());
        string tmp;
        vector<int> index;
        backtrack(str, tmp, index);
        return ans;
    }
};
// 通过了 

// 试一下其他的
class Solution {
public:
    vector<string> ans;
    void backtrack(vector<char>& str, string tmp, vector<bool>& isVisited) {
        if (tmp.size() == str.size()) {
            ans.push_back(tmp);
            return;
        }
        // 1 1 1 2 2 3 4
        for (int i = 0; i < str.size(); i++) {
            if (isVisited[i])
                continue;
            if (i != 0 && str[i] == str[i - 1] && !isVisited[i - 1])
                continue;

            isVisited[i] = true;
            tmp += str[i];
            backtrack(str, tmp, isVisited);
            tmp.pop_back();
            isVisited[i] = false;
        }
    }

    vector<string> permutation(string s) {
        if (s.size() == 0)
            return ans;
        vector<char> str;
        for (int i = 0; i < s.size(); i++)
            str.push_back(s[i]);
        sort(str.begin(), str.end());

        string tmp;
        vector<bool> isVisited(s.size(), false);
        backtrack(str, tmp, isVisited);
        return ans;
    }
};
