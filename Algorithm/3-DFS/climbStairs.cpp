#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> m;
    int climbStairs(int n) {
        int cnt = 0;
        if (n == 1 || n == 2)
            return n;
        if (m.count(n) != 0)
            return m[n];
        cnt = climbStairs(n - 1) + climbStairs(n - 2);
        m[n] = cnt;
        return cnt;
    }
};
// 就是斐波那契数