// 1-22
#include <iostream>
#include <vector>
using namespace std;

// dp[i][j]指的是从i到j取得的最大值 base case 就是斜线
// 转移 计算 left right
// left = nums[i] + dp[i + 1][j].second
// right = nums[j] + dp[i][j - 1].second
// left > right : dp[i][j].first = left; dp[i][j].second = dp[i + 1][j].first;
// left < right : dp[i][j].first = right; dp[i][j].second = dp[i][j - 1].first;
class Solution {
public:
    struct node {
        int first, second;
    };
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<node>> dp(n, vector<node>(n));
        for (int i = 0; i < n; i++)
            dp[i][i].first = nums[i];
        for (int i = n - 2; i >= 0; i--) {
            for (int j = i + 1; j < n; j++) {
                int left = nums[i] + dp[i + 1][j].second; // 先拿最左边 之后就只能拿剩下的后手
                int right = nums[j] + dp[i][j - 1].second; // 拿最右边 之后只能拿剩下的后手
                if (left > right) {
                    dp[i][j].first = left;
                    dp[i][j].second = dp[i + 1][j].first;
                } else {
                    dp[i][j].first = right;
                    dp[i][j].second = dp[i][j - 1].first;
                }
            }
        }
        // n == 1应该没问题 n == 0应该不会出现吧
        return dp[0][n - 1].first >= dp[0][n - 1].second;
    }
};
// 通过了 没啥问题

int main() {
    Solution sol;
    vector<int> v = {3, 1, 5, 8};
    sol.PredictTheWinner(v);
}

