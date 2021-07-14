#include <iostream>
using namespace std;

// 6-16
// 1.快速乘法 2.ans一定在[0,x]内 从其中进行二分
class Solution {
public:
    int divide(int dividend, int divisor) {
        // 能溢出就只有这一个例子
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        long x = dividend, y = divisor; // 1 2 , 5 2
        bool isNeg = false;
        if ((x > 0 && y < 0) || (x < 0 && y > 0))
            isNeg = true;
        if (x < 0)
            x = -x;
        if (y < 0)
            y = -y;
        long left = 0, right = x;
        // 这个适用于left is answer吗
        // <= 那里边最大的就是答案 right is answer
        while (left <= right) {
            long mid = left + (right - left) / 2;
            long ans = mul(mid, y);
            // if (ans == x) // 这个不一定是ans
                // return mid;
            if (ans > x)
                right = mid - 1;
            else if (ans <= x)
                left = mid + 1;
        }
        return isNeg ? -right : right;
    }

    long mul(long a, long b) {
        long ans = 0;
        while (b > 0) {
            if ((b & 1) == 1)
                ans += a;
            b >>= 1;
            a += a;
        }
        return ans;
    }
};

int main() {
    Solution sol;
    sol.divide(10, 3);
}

// 5-9
class Solution1 {
public:
    int divide(int dividend, int divisor) {
        long ans = long(dividend) / long(divisor);
        if (ans > INT_MAX || ans < INT_MIN)
            return INT_MAX;
        return ans;
    }
};
// 犯规了 不能用除法的

// 也就一个特例
class Solution2 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == INT_MIN && divisor == -1)
            return INT_MAX;
        return dividend / divisor;
    }
};