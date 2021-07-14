// 1-23
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// dp[i][j].first为先手在i-j之间取得的最大值 跟基础模板是一样的
// 关键是选择变了 原来是左右选择 现在是 左 1 2 3选择
// 状态转移 dp[i][j].first = stoneValue[i ~ x] + dp[i + x][j].second x取1 2 3
class Solution1 {
public:
    struct node {
        int first = INT_MIN, second = INT_MIN;
    };
    vector<vector<int>> sumMemo;
    // unordered_map<string, int> sumMemo;
    void sumCalculate(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sumMemo.resize(n, vector<int>(n));
        for (int i = 0; i < n; i++) {
            int sum = stoneValue[i];
            sumMemo[i][i] = sum;
            for (int j = i + 1; j < n; j++) {
                sum += stoneValue[j];
                sumMemo[i][j] = sum;
            }
        }
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sumCalculate(stoneValue);
        vector<vector<node>> dp(n, vector<node>(n));
        // base case
        for (int i = 0; i < n; i++) {
            dp[i][i].first = stoneValue[i];
            dp[i][i].second = 0;
        }
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int sum, x;
                for (x = 0; x < 3 && i + x <= j; x++) {
                    sum = sumMemo[i][i + x];
                    dp[i][j].first = max(dp[i][j].first, sum + (i + x + 1 > j ? 0 : dp[i + x + 1][j].second)); // 可能会越界
                }
                dp[i][j].second = sumMemo[i][j] - dp[i][j].first;
                // dp[i][j].second = sumCalculate(stoneValue, i, j) - dp[i][j].first; // 每次计算效率很低
            }
        }
        if (dp[0][n - 1].first > dp[0][n - 1].second)
            return "Alice";
        else if (dp[0][n - 1].first < dp[0][n - 1].second)
            return "Bob";
        return "Tie";
    }
};
// 超出时间限制 应该是sumCalculate计算效率太低
// 修改后还是不行 换个思路吧

// dp[i] 定义为从i到n-1先手能拿的最大值
// 转移 dp[i] = max(sum[i] - dp[i + 1~3])
class Solution {
public:
    vector<int> sum;
    void sumCalculate(vector<int> nums) {
        sum = nums;
        for (int i = nums.size() - 2; i >= 0; i--)
            sum[i] += sum[i + 1];
    }
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        sumCalculate(stoneValue);
        vector<int> dp(n + 2, INT_MIN);
        dp[n + 1] = dp[n] = 0;
        dp[n - 1] = stoneValue[n - 1];
        for (int i = n - 2; i >= 0; i--) {
            for (int x = 1; x <= 3; x++) {
                dp[i] = max(dp[i], sum[i] - dp[i + x]);
            }
        }
        int Alice = dp[0], Bob = sum[0] - dp[0];
        if (Alice > Bob)
            return "Alice";
        else if (Alice < Bob)
            return "Bob";
        // Alice > Bob ? return "Alice" : return "Bob";
        return "Tie";
    }
};
// 通过了 可以！
int main() {
    vector<int> v = {-1, -2, -3};
    Solution sol;
    sol.stoneGameIII(v);
}