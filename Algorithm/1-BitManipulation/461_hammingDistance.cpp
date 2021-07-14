#include <iostream>
#include <vector>
using namespace std;

// 5-27
// 运算符优先级
// [] () . ->
// - ++ -- * &取地址 ! ~
// / * %
// + -
// << >>
// > >= < <=
// == !=
// & ^ | && ||
// ?:
// = /= *= += -=
class Solution {
public:
    int hammingDistance(int x, int y) {
        int xor1 = x ^ y;
        int ans = 0, i = 0;
        // 左移右移运算符 > != > &
        while (xor1 >> i != 0) {
            if (xor1 >> i & 1)
                ans++;
            i++;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    sol.hammingDistance(1, 4);
}