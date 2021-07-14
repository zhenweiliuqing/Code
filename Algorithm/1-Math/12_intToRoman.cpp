#include <iostream>
using namespace std;

class Solution {
public:
    string intToRoman(int num) {
        string ans;
        if (num >= 1000) {
            for (int i = 0; i < num / 1000; i++)
                ans += 'M';
            num %= 1000;
        } 

        if (num >= 900) {
            ans += "CM";
            num -= 900;
        } else if (num >= 500) {
            ans += 'D';
            num -= 500;
            int cnt = num / 100;
            for (int i = 0; i < cnt; i++) {
                ans += 'C';
                num -= 100;
            }
        } else if (num >= 400) {
            ans += "CD";
            num -= 400;
        } else {
            int cnt = num / 100;
            for (int i = 0; i < cnt; i++) {
                ans += 'C';
                num -= 100;
            }
        }

        if (num >= 90) {
            ans += "XC";
            num -= 90;
        } else if (num >= 50) {
            ans += 'L';
            num -= 50;
            int cnt = num / 10;
            for (int i = 0; i < cnt; i++) {
                ans += 'X';
                num -= 10;
            }
        } else if (num >= 40) {
            ans += "XL";
            num -= 40;
        } else {
            int cnt = num / 10;
            for (int i = 0; i < cnt; i++) {
                ans += 'X';
                num -= 10;
            }
        }
        
        if (num >= 9) {
            ans += "IX";
            num -= 9;
        } else if (num >= 5) {
            ans += 'V';
            num -= 5;
            int cnt = num;
            for (int i = 0; i < cnt; i++) {
                ans += 'I';
                num -= 1;
            }
        } else if (num >= 4) {
            ans += "IV";
            num -= 4;
        } else {
            int cnt = num;
            for (int i = 0; i < cnt; i++) {
                ans += 'I';
                num -= 1;
            }
        }
        return ans;
    }
};

// 通过了 有点长

const pair<int, string> valueSymbols[] = {
    {1000, "M"},
    {900,  "CM"},
    {500,  "D"},
    {400,  "CD"},
    {100,  "C"},
    {90,   "XC"},
    {50,   "L"},
    {40,   "XL"},
    {10,   "X"},
    {9,    "IX"},
    {5,    "V"},
    {4,    "IV"},
    {1,    "I"},
};

class Solution {
public:
    string intToRoman(int num) {
        string roman;
        for (const auto &[value, symbol] : valueSymbols) {
            while (num >= value) {
                num -= value;
                roman += symbol;
            }
            if (num == 0) {
                break;
            }
        }
        return roman;
    }
};
// 作者：LeetCode-Solution
