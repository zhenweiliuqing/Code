#include <iostream>
#include <vector>
using namespace std;

// 状态：dp长度等于arrLen dp[step][i] 表示第step步第i个位置有几种走法
// 转移：dp[step][i] = dp[step - 1][i] + dp[step - 1][i - 1] + dp[step - 1][i + 1];
// base case: dp[0][i] = 0 dp[0][0] = 1

// 这个题不难 就是超时需要处理一下
class Solution {
public:
    const int mod = 1000000007;
    int numWays(int steps, int arrLen) {
        int col = min(arrLen , steps / 2 + 1);
        vector<vector<int>> dp(steps + 1, vector<int>(col));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            for (int j = 0; j < col; j++) {
                dp[i][j] = dp[i - 1][j];
                if (j - 1 >= 0)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j - 1]) % mod;
                if (j + 1 < col)
                    dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % mod;
            }
        }
        return dp[steps][0];
    }
};
// 通过了

class Solution1 {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
            for (int j = 1; j < arrLen - 1; j++)
                dp[i][j] = ((dp[i - 1][j - 1]  + dp[i - 1][j]) % 1000000007 + dp[i - 1][j + 1]) % 1000000007;
            dp[i][arrLen - 1] = (dp[i - 1][arrLen - 2] + dp[i - 1][arrLen - 1]) % 1000000007;
        }
        return dp[steps][0];
    }
};
// 超出时间限制  走太远是回不去的 进行一下修正
// 这个测试用例就会超时

class Solution {
public:
    int numWays(int steps, int arrLen) {
        vector<vector<int>> dp(steps + 1, vector<int>(arrLen));
        dp[0][0] = 1;
        for (int i = 1; i <= steps; i++) {
            dp[i][0] = (dp[i - 1][0] + dp[i - 1][1]) % 1000000007;
            for (int j = 1; j < min(arrLen  - 1, steps / 2 + 1); j++)
                dp[i][j] = ((dp[i - 1][j - 1]  + dp[i - 1][j]) % 1000000007 + dp[i - 1][j + 1]) % 1000000007;
            dp[i][arrLen - 1] = (dp[i - 1][arrLen - 2] + dp[i - 1][arrLen - 1]) % 1000000007;
        }
        return dp[steps][0];
    }
};
// 超时 但是测试用例可以通过 这个感觉很奇怪
// 438
// 315977



int main() {
    Solution sol;
    sol.numWays(27, 7);
}
// 1636636045 + 954602812 
// 1000000007   1000000007
// 21 4748 3648
