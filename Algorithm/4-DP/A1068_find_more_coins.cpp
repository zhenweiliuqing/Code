#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n, target;
    cin >> n >> target;
    vector<int> coins(n);
    for (int i = 0; i < n; i++)
        cin >> coins[i];
    sort(coins.begin(), coins.end());
    // 这个跟那个canPartition很像
    // 这也不是求方法个数 最小硬币数 最大值
    vector<vector<int>> dp(n + 1, vector<int>(target + 1, 0)); // dp 里边存的是面值 其实应该是true false
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= target; j++) {
            if (j - coins[i - 1] >= 0)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - coins[i - 1]] + coins[i - 1]); // 这个其实用max应该也可以
            else
                dp[i][j] = dp[i - 1][j]; // 不选择这个 继承上一状态
        }
    }
    if (dp[n][target] != target)
        cout << "No Solution";
    else {
        
    }
}
