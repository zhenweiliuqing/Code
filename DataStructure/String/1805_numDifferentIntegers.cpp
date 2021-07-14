// 3-31
#include <iostream>
#include <vector>
#include <string>
#include <set>
#include <unordered_set>
using namespace std;

// 这个思路不错
int numDifferentIntegers(string word) {
    word += '-';
    string res;
    unordered_set<string> set;
    for (auto c : word) {
        if (!isdigit(c)) {
            if (res != "") {
                set.insert(res);
                res = "";
            }
        }
        else {
            if (res == "0") 
                res = "";
            res += c;
        }
    }
    return set.size();
}

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<string> ans;
        int n = word.size();
        if (n == 0)
            return ans.size();
        string tmp;
        for (int i = 0; i < n; i++) {
            if (i > 0 && isalpha(word[i]) && isdigit(word[i - 1])) {
                ans.insert(tmp);
                tmp = "";
            } else if (word[i] >= '0' && word[i] <= '9') {
                tmp += word[i]; 
            }
        }
        if (isdigit(word[n - 1]))
            ans.insert(tmp);
        set<string> anss;
        for (auto it : ans) {
            anss.insert(removeZero(it));
        }
        return anss.size();
    }

    string removeZero(string str) {
        while (str[0] == '0')
            str = str.substr(1, str.size() - 1);
        return str;
    }
};
// 通过了 不过有点麻烦啊

class Solution {
public:
    int numDifferentIntegers(string word) {
        set<int> ans;
        int n = word.size();
        if (n == 0)
            return ans.size();
        int mul = 0;
        for (int i = 0; i < n; i++) {
            if (i > 0 && isalpha(word[i]) && isdigit(word[i - 1])) {
                ans.insert(mul);
                mul = 0;
            } else if (word[i] >= '0' && word[i] <= '9') {
                mul = mul * 10 + word[i] - '0'; 
            }
        }
        return isdigit(word[n - 1]) ? ans.size() + 1 : ans.size();
    }
};
// int会溢出