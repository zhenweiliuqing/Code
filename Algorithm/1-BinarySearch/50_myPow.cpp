#include <iostream>
using namespace std;

// 5-9
class Solution {
public:
    double fastPow(const double x, long long n) {
        if (n == 0)
            return 1.0;
        double half = fastPow(x, n / 2);
        if (n & 1)
            return half * half * x;
        else 
            return half * half;
    }

    double myPow(double x, long long n) {
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        return fastPow(x, n);
    }
};
// 通过了

// 暴力法 
class Solution {
public:
    double myPow(double x, int n) {
        double ret = 1;
        if (n > 0) {
            for (int i = 0; i < n ; i++) 
                ret *= x;
        }
        else if (n < 0) {
            for (int i = 0; i < -n ; i++) 
                ret *= x;
            ret = 1 / ret;
        }
        return ret;
    }
};

// 折半法
class Solution1 {
public:
    double myPow(double x, int n) {
        double ret = 1;
        if (n < 0) {
            x = 1 / x;
            n = -n;
        }
        int i = 2;
        ret = x;
        while (i <= n) {
            ret = ret * ret;
            i = 2 * i;
        }
        for (;i < n; i++)
            ret *= x;
        return ret;
    }
};
// 这种思路败在了 2^31-1 这种情况下 剩下还有一半的计算量

class Solution2 {
public:
    double fastPow(double x, long long n) {
        if (n == 0)
            return 1.0;
        double half = fastPow(x, n / 2);
        if (n % 2 == 0)
            return half * half;
        else 
            return half * half * x;
    }
    double myPow(double x, int n) {
        long long N = n;
        if (N < 0) {
            x = 1 / x;
            N = -N;
        }
        return fastPow(x, N);
    }
};
