#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

// 最坏情况下 至少扔几次测出鸡蛋恰好摔不碎的楼层
// 最坏 至少 分别是什么意思？？
class Solution {
public:
    map<pair<int, int>, int> memo; // unordered_map 不行
    int superEggDrop(int K, int N) {
        if (K == 1)
            return N;
        if (N == 0)
            return 0;
        if (memo.count(make_pair(K, N)) != 0)
            return memo[make_pair(K, N)];
        int res = 99999999;
        for (int i = 1; i <= N; i++) { // 从哪一层楼开始呢？
            // 每一层扔 返回最多需要的次数 在哪一层需要次数最少呢 
            res = min(res, max(superEggDrop(K, N - i), superEggDrop(K - 1, i - 1)) + 1);
        }
        memo[make_pair(K, N)] = res;
        return res;
    }
};
// 这个超时了 做一下二分搜索优化

class Solution {
public:
    map<pair<int, int>, int> memo; // unordered_map 不行
    int superEggDrop(int K, int N) {
        if (K == 1)
            return N;
        if (N == 0)
            return 0;
        if (memo.count(make_pair(K, N)) != 0)
            return memo[make_pair(K, N)];
        int res = 99999999;
        int low = 1, high = N;
        while (low <= high) {
            int mid = low + ((high - low) >> 1);
            int not_broken = superEggDrop(K, N - mid);
            int broken = superEggDrop(K - 1, mid - 1);
            if (broken <= not_broken) {
                res = min(res, not_broken + 1);
                low = mid + 1;
            } else {
                res = min(res, broken + 1);
                high = mid - 1;
            }
        }

        memo[make_pair(K, N)] = res;
        return res;
    }
};
// 又超时了 但是用python都能通过？？是不是make_pair比较费时间？？

int main() {
    Solution drop;
    int res = drop.superEggDrop(2, 100);
    for (auto it : drop.memo)
        cout << "(" << it.first.first << "," << it.first.second << ")" << " " << it.second << endl;
        
    return 0;
}
// static int memo[101][10001]; 不行 静态成员变量必须在类外初始化才能使用
// 3-14
// 有两个问题
// 1. 为什么会出现 heap buffer overflow  这个K N每次都会初始化吧
// 2. 为什么static 比全局变量速度快 占用内存少
class Solution {
public:
    // vector<vector<int>> memo = vector<vector<int>>(101, vector<int>(10001)); 200ms 336MB
    // int memo[101][10001]; 64ms 10MB
    
    int superEggDrop(int K, int N) {
        // static vector<vector<int>> memo(K + 1, vector<int>(N + 1)); heap buffer overflow
        // static vector<vector<int>> memo(101, vector<int>(10000 + 1)); 20ms 10 MB 这个变化最大
        static int memo[101][10001]; // 8ms 6MB
        if (K == 1)
            return N;
        if (N == 0 || N == 1)
            return N;
        if (memo[K][N] != 0)
            return memo[K][N];
                
        int ans = INT_MAX;
        // 线性算法 
        // for (int i = 1; i <= N; i++)
        //     ans = min(ans, max(superEggDrop(K - 1, i - 1), superEggDrop(K, N - i)) + 1);
        
        // 二分法
        int low = 1, high = N;
        while (low <= high) {
            int mid = (low + high)/2;
            int not_broken = superEggDrop(K, N - mid);
            int broken = superEggDrop(K - 1, mid - 1);
            if (broken < not_broken) {
                ans = min(ans, not_broken + 1);
                low = mid + 1;
            } else {
                ans = min(ans, broken + 1);
                high = mid - 1;
            }
        }
        
        memo[K][N] = ans;
        return ans;
    }
};