// 3-1
#include <iostream>
#include <string>
#include <vector>
using namespace std;

// 思路：动态规划
// 状态转移: f(i) = f(i - 1) + f(i - 2) 如果前两位满足10-25
// base case: f(1) = 1;
class Solution {
public:
    int translateNum(int num) {
        if (num < 0)
            return 0;

        string s = to_string(num);
        int n = s.size();
        vector<int> dp(n + 1);
        dp[0] = 1;
        dp[1] = 1;
        // 注意下标
        for (int i = 2; i <= n; i++) {
            dp[i] += dp[i - 1];
            if (stoi(s.substr(i - 2, 2)) <= 25 && stoi(s.substr(i - 2, 2)) >=10 )
                dp[i] += dp[i - 2];
        }
        return dp[n];
    }
};
// 通过了