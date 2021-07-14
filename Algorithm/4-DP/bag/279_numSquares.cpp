#include <iostream>
#include <vector>
using namespace std;

// 完全背包 这个跟兑换硬币最小数是一样的
// 硬币和平方数都是可以重复的
class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, n);
        vector<int> squares;
        for (int i = 1; i * i <= n; i++) {
            dp[i * i] = 1;
            squares.push_back(i * i);
        }
        // 完全背包的for循环顺序是可以交换的 那硬币交换为什么不能
        // 如果是求最大最小值可以交换 统计方法数不能交换
        for (int sq : squares) {
            for (int w = 1; w <= n; w++) {
                if (w - sq < 0)
                    continue;
                dp[w] = min(dp[w], dp[w - sq] + 1);
            }
        }
        return dp[n];
    }
};


// 动态规划 这个有点像回溯 
// 状态: dp[i] i由完全平方数组成的最小数量 初始状态 i本身是平方数 则dp[i] = 1
// 转移: dp[i] = dp[i - sq[j]] + 1 对平方数枚举 i-这个平方数需要的数量再加上1

class Solution {
public:
    int numSquares(int n) {
        vector<int> dp(n + 1, INFINITY);
        vector<int> square;
        for (int i = 1; i * i <= n; i++) {
            dp[i * i] = 1;
            square.push_back(i * i);
        }
        for (int i = 1; i <= n; i++) {
            // 这个挨个找肯定不对劲 超时了
            // for (int j = 1, k = i - 1; j <= k; j++,k--) {
            //     dp[i] = min(dp[i], dp[j] + dp[k]); // 这个太慢 1 4 9一定是其中一个最小的 把它减去找另一个最小的即可
            // }
            for (int j = 0; j < square.size(); j++) {
                if (square[j] > i)
                    break;
                // 有没有可能两个不是最小的加起来反而是最小的
                // 感觉不对 最小的里边一定愿意包含dp=1的数
                // 证明：不包含dp=1的所有组合都小于最优解
                // 刚开始最少的肯定是dp=1 后来的也一定是含有最少的dp=1 所以往上一定要包含dp=1
                // 有点像贪心策略 包含dp=1的里边才有最优解
                dp[i] = min(dp[i], dp[i - square[j]] + 1);                                      
            }
        }
        return dp[n];
    }
};
// 这个通过了 456ms 比回溯好一点

// 回溯法
class Solution {
public:
    // 这里i这个下标一定得注意一下
    void backtrack(const int &n, vector<int> &num, int i, int ans, int &min) {
        if (ans > min)
            return;
        if (n == 0) {
            if (ans < min)
                min = ans;
            return;
        }
        for (int j = i; j >= 0; j--) {
            if (num[j] * num[j] > n)
                continue;
            ans++;
            backtrack(n - num[j] * num[j], num, j, ans, min);
            ans--;
        }
    }

    int numSquares(int n) {
        vector<int> num;
        for (int i = 1; i * i <= n; i++)
            num.push_back(i);
        int min = 99999999;
        backtrack(n, num, num.size() - 1, 0, min);
        return min;
    }
};
// 这个通过了 虽然只击败了5%