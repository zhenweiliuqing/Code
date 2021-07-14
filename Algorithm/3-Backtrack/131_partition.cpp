// 1-5
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<string>> ans;
    bool isPalindrome(string s) {
        int n = s.size() - 1;
        for (int i = 0; i <= n / 2; i++) {
            if (s[i] != s[n - i])
                return false;
        }
        return true;
    }

    // 这个时间也没好到那里去
    bool isPalindrome(string s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right])
                return false;
            left++;
            right--;
        }
        return true;
    }
    
    void backtrack(string s, vector<string> tmp, int i, int n) {
        if (i == n) {
            ans.push_back(tmp);
            return;
        }

        for (int j = i; j < n; j++) {
            // 这一步可以用传索引的方式验证 截取字符串消耗性能
            // string top = s.substr(i, j - i + 1);
            // if (!isPalindrome(top)) 
            //     continue;

            if (!isPalindrome(s, i, j))
                continue;
            tmp.push_back(s.substr(i, j - i + 1));
            backtrack(s, tmp, j + 1, n);
            tmp.pop_back();
        }
    }
    vector<vector<string>> partition(string s) {
        vector<string> tmp;
        backtrack(s, tmp, 0, s.size());
        return ans;
    }
};
// 一次通过 牛逼！就是时间有点长