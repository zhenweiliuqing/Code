#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> countBits(int num) {
        vector<int> dp(num + 1);
        dp[0] = 0;
        for (int i = 0; pow(2, i) <= num; i++)
            dp[pow(2, i)] = 1;
        int bias = 0;
        for (int i = 1; i <= num; i++) {
            if (dp[i] == 1) {
                bias = i;
                continue;
            }
            dp[i] = dp[i - bias] + 1;
        }
        return dp;
    }
};
// 通过了 牛逼 4ms 超过了98%
// 我是利用了最高位之后的内容和上一阶段的相同 

// 还有一种方法是把最后一位看作0 1 0 1的序列 前面几位偶数除以2 
vector<int> countBits(int num) {
    vector<int> result(num+1);
    result[0] = 0;
    for(int i = 1; i <= num; i++) {
        if(i % 2 == 1)
            result[i] = result[i-1] + 1;
        else
            result[i] = result[i/2];
    }
    return result;
}