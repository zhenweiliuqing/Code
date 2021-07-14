// 1-26
#include <iostream>
#include <vector>
using namespace std;

// 正向思路挺简单的 就是算不重复的 9 * 9 * 8 * 7 ... 
// 算重复的再减去就很麻烦 
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(n + 11);
        dp[0] = 1;
        dp[1] = 10;
        for (int i = 2; i <= 10; i++) {
            int cnt = 9;
            for (int k = 9; k > 10 - i && k >= 0;k--) {
                cnt *= k;
            }
            dp[i] = dp[i - 1] + cnt;
        }
        return n < 10 ? dp[n] : dp[10];
    }
};
// 通过了