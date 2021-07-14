// 3-17

int fib(int n) {
    vector<int> dp(n + 1, 0);
    dp[1] = 1;
    for (int i = 2; i <= n; i++)
        dp[i] = dp[i - 1] + dp[i - 2];
    return dp[n];
}


// 不然会heap buffer overflow
class Solution {
public:
    int fib(int n) {
        int ans = n;
        if (n == 0 || n == 1)
            return ans;
        int dp0 = 0, dp1 = 1;
        for (int i = 2; i <= n; i++) {
            ans = (dp0 + dp1)% 1000000007;
            dp0 = dp1;
            dp1 = ans;
        }
        return ans;
    }
};