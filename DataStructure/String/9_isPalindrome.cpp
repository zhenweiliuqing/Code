#include <string>
using namespace std;

// 6-11
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0)
            return false;
        string s = to_string(x);
        int len = s.size();
        for (int i = 0; i < s.size() / 2; i++) {
            if (s[i] != s[len - 1 - i])
                return false;
        }
        return true;
    }
};
// 通过了