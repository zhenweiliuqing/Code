// 1-26
#include <iostream>
#include <vector>
using namespace std;

// 正向思路挺简单的 就是算不重复的 9 * 9 * 8 * 7 ... 
// 算重复的再减去就很麻烦 

// 状态: dp[i] 10^i 有多少种方法
// 转移: dp[i] = dp[i - 1] + (10^i-1 ~10^i-1)不重复的个数
// 对于n位数来说 第一位可以放9个数 第二位可以放9个 加上0 第三位 放8个 ...

// 跟美团4_4那个字母组合多像 那个是全排列的问题转化成排列组合
// 这个就是排列组合
class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        vector<int> dp(11);
        dp[0] = 1;
        dp[1] = 10;
        // 只有10个数
        for (int i = 2; i <= 10; i++) {
            int cnt = 9;
            for (int k = 9; k > 10 - i; k--) {
                cnt *= k;
            }
            dp[i] = dp[i - 1] + cnt;
        }
        return n < 10 ? dp[n] : dp[10];
    }
};
// 通过了