#include <iostream>
using namespace std;

// 6-20
class Solution {
public:
    string largestOddNumber(string num) {
        string tmp = num;
        while ((tmp.back() - '0') % 2 == 0) {
            tmp.pop_back();
        }
        return tmp;
    }
};
