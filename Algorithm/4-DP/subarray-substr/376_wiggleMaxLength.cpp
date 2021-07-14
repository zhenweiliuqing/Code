// 1-31
#include <iostream>
#include <vector>
using namespace std;

// 摆动序列 一大一小 可以不连续
// 状态 dp[i] 到下标i的摆动序列最大长度
// 转移 和之前都做一个比较 选出一个最长的序列来  

// 找到一个之前比自己大的 一个比自己小的 还是不太对劲 
// 难点在于如何摆动 每一个序列要有一个标志位 记录下一个应该是变大还是变小
// 用什么数据结构比较方便? pair struct?

// 测试用例
// 2 3 1 5 7 4 9 10
// 空
// 1
class Solution {
public:
    struct node {
        int len = 1;
        int flag = 0;
    };
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        vector<node> dp(n);
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                // flag = 1 说明该上升
                if (nums[i] > nums[j] && dp[j].flag >= 0) {
                    if (dp[i].len < dp[j].len + 1) {
                        dp[i].len = dp[j].len + 1;
                        dp[i].flag = -1;
                    }
                }
                if (nums[i] < nums[j] && dp[j].flag <= 0) {
                    if (dp[i].len < dp[j].len + 1) {
                        dp[i].len = dp[j].len + 1;
                        dp[i].flag = 1;
                    }
                }
            }
        }
        return dp[n - 1].len;
    }
};
// 直接通过 牛逼!

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) {
            return n;
        }
        vector<int> up(n), down(n);
        up[0] = down[0] = 1;
        for (int i = 1; i < n; i++) {
            if (nums[i] > nums[i - 1]) {
                up[i] = max(up[i - 1], down[i - 1] + 1);
                down[i] = down[i - 1];
            } else if (nums[i] < nums[i - 1]) {
                up[i] = up[i - 1];
                down[i] = max(up[i - 1] + 1, down[i - 1]);
            } else {
                up[i] = up[i - 1];
                down[i] = down[i - 1];
            }
        }
        return max(up[n - 1], down[n - 1]);
    }
};

// 作者：LeetCode-Solution
// 这种交错递增的状态之前在哪里见过 
// 就是最大乘积那里 可能有负的