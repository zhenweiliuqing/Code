#include <iostream>
#include <vector>
using namespace std;

// 5-22
class Solution {
public:
    int count(string s, char c) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] != c)
                cnt++;
            c = '1' - c + '0';
        }
        return cnt / 2;
    }
    int minSwaps(string s) {
        int cnt0 = 0, cnt1 = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '0')
                cnt0++;
            else
                cnt1++;
        }
        if (abs(cnt0 - cnt1) > 1)
            return -1;
        int ans = 0;
        if (cnt0 - cnt1 == 1) {
            ans = count(s, '0');
        } else if (cnt1 - cnt0 == 1) {
            ans = count(s, '1');
        } else if (cnt1 == cnt0) {
            ans = min(count(s, '0'), count(s, '1'));
        }
        return ans;
    }
};
// 通过了