// 1-18
#include <iostream>
using namespace std;

// 编写一个程序，找出第 n 个丑数。
// 丑数就是质因数只包含 2, 3, 5 的正整数。

// 状态: dp[i] 第i个丑数
// 转移: 不能直接从dp[i-1]这些状态转 得用三个标志位 指向前面的状态 代表*2 *3 *5
//       dp[i] = min(tmp2, tmp3, tmp5); 对于最小的tmp 标志位往后移动 指向下一个dp

// 知道应该从前一个状态 *2 *3 *5
// 但是不知道该按什么顺序 数越来的越多之后就乱了
// 其实只有3个标志位 乘完之后往后移 这样就不会乱了
class Solution {
public:
    int nthUglyNumber(int n) {
        int dp[n + 1];
        dp[1] = 1;
        int mul2 = 1, mul3 = 1, mul5 = 1;
        for (int i = 2; i <= n; i++) {
            int tmp2 = dp[mul2] * 2, tmp3 = dp[mul3] * 3, tmp5 = dp[mul5] * 5;
            dp[i] = min(tmp2, min(tmp3, tmp5));
            if (dp[i] == tmp2)
                mul2++;
            if (dp[i] == tmp3)
                mul3++;
            if (dp[i] == tmp5)
                mul5++;
        }
        return dp[n];
    }
};
// 通过了 
