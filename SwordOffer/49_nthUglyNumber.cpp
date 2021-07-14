// 3-1
#include <iostream>
#include <vector>
using namespace std;

// 思路: 设置3个flag 依次往后递增 
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int> dp(n);
        dp[0] = 1;
        int mul2 = 0, mul3 = 0, mul5 = 0;

        for (int i = 1; i < n; i++) {
            dp[i] = min(dp[mul2] * 2, min(dp[mul3] * 3, dp[mul5] * 5));
            if (dp[i] == dp[mul2] * 2)
                mul2++;
            if (dp[i] == dp[mul3] * 3)
                mul3++;
            if (dp[i] == dp[mul5] * 5)
                mul5++;
        }
        return dp[n - 1];
    }
};
// 一次通过 可以的