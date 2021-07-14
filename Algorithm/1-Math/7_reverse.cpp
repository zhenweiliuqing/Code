#include <iostream>
#include <algorithm>
using namespace std;

// 5-3
// 其实-号不用提出来 反转和+是一样 每次取余都会带一个-号
class Solution1 {
public:
    int reverse(int x) {
        int flag = 1;
        // 这个要特殊处理
        if (x == INT_MIN)
            return 0;
        if (x < 0) {
            flag = -1;
            x = -x;            
        }
        int ans = 0;
        while (x != 0) {
            if (ans > INT_MAX / 10)
                return 0;
            ans = ans * 10 + (x % 10);
            x = x / 10;
        }
        return flag * ans;
    }
};

class Solution {
public:
    int reverse(int x) {
        if (x == INT_MIN)
            return 0;
        long ans = 0; // long 就是 int
        int tmp = abs(x);
        while (tmp != 0) {
            ans *= 10;
            ans += tmp % 10;
            tmp /= 10;
        }
        if (ans > INT_MAX)
            return 0;

        return x > 0 ? ans : -ans;
    }
};
// 通过了 但是感觉不对 不知道是怎么通过的 
// 在这里long 是int 但是在leetcode编译器中 long 是long long
// 964 632 435 * 10 = 1056 389 758 ?
// 0011 1001 0111 1111 0001 1111 0111 0011          964 632 435 
// 0010 0011 1110 1111 0111 0011 1010 0111 1110     964 632 4350
//      0011 1110 1111 0111 0011 1010 0111 1110     1056 389 758
// long 最大值为 2 147 483 647

class Solution2 {
public:
    int reverse(int x) {
        int rev = 0;
        while (x != 0) {
            int pop = x % 10;
            x /= 10;
            if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
            if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
            rev = rev * 10 + pop;
        }
        return rev;
    }
};

int main() {
    Solution2 sol;
    sol.reverse(-1534236469);
    cout << LONG_MAX << endl;
    return 0;
}
// [-2147483648, 2147483647]
// 1534236469