#include <iostream>
using namespace std;

// 6-3
// s[i] 加上数字就是下一个ASCII值
class Solution {
public:
    string replaceDigits(string s) {
        for (int i = 1; i < s.size(); i+=2) 
            s[i] = s[i - 1] + s[i] - '0';
        return s;
    }
};

int main() {
    Solution sol;
    sol.replaceDigits("a1");
}