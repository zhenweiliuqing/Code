#include <iostream>
#include <string>
using namespace std;

// 5-25
class Solution {
public:
    bool checkZeroOnes(string s) {
        int len0 = 0, len1 = 0;
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0') {
                cnt0++;
                len1 = max(len1, cnt1);
                cnt1 = 0;
            } else if (s[i] == '1') {
                cnt1++;
                len0 = max(len0, cnt0);
                cnt0 = 0;
            }
        }
        len0 = max(len0, cnt0);
        len1 = max(len1, cnt1);
        return len1 > len0;
    }
};
// 通过了