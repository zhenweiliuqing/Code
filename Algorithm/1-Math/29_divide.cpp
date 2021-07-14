#include <iostream>
using namespace std;

// 6-16
// 1.快速乘法 2.ans一定在[0,x]内 从其中进行二分
class Solution {
public:
    int divide(int dividend, int divisor) {
        int x = dividend, y = divisor; // 1 2 
        int left = 0, right = x;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            int ans = mul(mid, y);
            if (ans == x)
                return mid;
            else if (ans > x)
                right = mid - 1;
            else if (ans < x)
                left = mid + 1;
        }
        return ;
    }

    int mul(int a, int b) {
        int ans = 0;
        while (b > 0) {
            if ((a & 1) == 1)
                ans += a;
            b >>= 1;
            a += a;
        }
        return ans;
    }
};