// 1-25
#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 参考答案 有时候用递归思路还挺清晰的
// memo[i][j] 从ring的第i个字符开始 找到key中第j个字符所需的最小步数
// 转移 把找到现在这个字符k作为新的起点 目标就是key的下一个字符
// base case 只有一个字符 又知道转盘的起点 那肯定知道最近路径
class Solution {
public:
    unordered_map<char, vector<int>> mmap;
    vector<vector<int>> memo;
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        for (int i = 0; i < m; i++) {
            mmap[ring[i]].push_back(i);
        }
        memo.resize(m, vector<int>(n, -1));
        return dp(ring, key, 0, 0);
    }

    int dp(string ring, string key, int start, int k) {
        if (k == key.size())
            return 0;
        if (memo[start][k] != -1)
            return memo[start][k];
        int n = ring.size();
        int len = INT_MAX;
        for (int i : mmap[key[k]]) {
            // int rotate = min(abs(start - i), abs(start - i + r)); // 逆时针算错了
            int rotate = abs(start - i);
            rotate = min(rotate, n - rotate);
            len = min(len, dp(ring, key, i, k + 1) + rotate + 1);
        }
        memo[start][k] = len;
        return len;
    }
};
// 超出时间限制 需要用个memo
// 通过了 还行吧
// 有两个小错误 1.逆时针不会算 2.memo写错了



// 4-7 自己又做了一遍
// static 注意一下 可能会输出上次的结果 最后不对
// 关键是memo[start][cur] 指的是从ring种start位置转完key[cur]之后的最小步数
class Solution {
public:
    unordered_map<char, vector<int>> mmap;
    // vector<vector<int>> memo(101, vector<int>(101, -1)); 这种会报错
    vector<vector<int>> memo = vector<vector<int>>(101, vector<int>(101, -1)); // 跟887扔鸡蛋相似
    int findRotateSteps(string ring, string key) {
        int n = ring.size();
        for (int i = 0; i < n; i++)
            mmap[ring[i]].push_back(i);
        return dp(ring, key, 0, 0);
    }

    int dp(string ring, string key, int start, int cur) {
        // static vector<vector<int>> memo(ring.size(), vector<int>(key.size(), -1));
        if (cur == key.size())
            return 0;
        if (memo[start][cur] != -1)
            return memo[start][cur];
        int n = ring.size();
        int len = INT_MAX;
        for (auto i : mmap[key[cur]]) {
            int rotate = abs(start - i);
            rotate = min(rotate, n - rotate); // 这里用ring.size()会说与min不匹配
            len = min(len, dp(ring, key, i, cur + 1) + rotate + 1);
        }
        memo[start][cur] = len;
        return len;
    }
};
// 这个不行
// static 会答案错误 但是测试没错


class Solution1 {
public:
    unordered_map<char, vector<int>> charToIndex;
    vector<vector<int>> memo;
    int findRotateSteps(string ring, string key) {
        int m = ring.size();
        int n = key.size();
        memo.resize(m, vector<int>(n, 0));
        for (int i = 0; i < ring.size(); i++) {
            charToIndex[ring[i]].push_back(i);
        }
        return dp(ring, 0, key, 0);
    }
    int dp(string& ring, int i, string& key, int j) {
        if (j == key.size())
            return 0;
        if (memo[i][j] != 0)
            return memo[i][j];
        int n = ring.size();
        int res = INT_MAX;
        for (int k : charToIndex[key[j]]) { // 这个数据结构用的很妙 直奔目标而去
            int delta = abs(k - i);
            delta = min(delta, n - delta); // 顺时针 逆时针
            int subProblem = dp(ring, k, key, j + 1);
            res = min(res, 1 + delta + subProblem);
        }
        memo[i][j] = res;
        return res;
    }
};



int main() {
    Solution sol;
    string ring = "pqwcx";
    string key = "cpqwx";
    sol.findRotateSteps(ring, key);
}
