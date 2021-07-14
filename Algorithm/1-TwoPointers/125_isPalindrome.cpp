#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.size();
        int left = 0, right = n - 1;
        while (left < right) {
            while (!isalnum(s[left]) && left < n)
                left++;
            if (left == n) // 都是标点符号
                break;
            while (!isalnum(s[right]) && right >= 0)
                right--;
            
            if (tolower(s[left]) != tolower(s[right]))
                return false;
            left++;right--;
        }
        return true;
    }
};
// 通过了 其实可以先筛选出来 比较好弄

// 筛选 + 判断
class Solution {
public:
    bool isPalindrome(string s) {
        string sgood;
        for (char ch: s) {
            if (isalnum(ch)) {
                sgood += tolower(ch);
            }
        }
        string sgood_rev(sgood.rbegin(), sgood.rend());
        return sgood == sgood_rev;
    }
};

