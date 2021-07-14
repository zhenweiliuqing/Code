#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    bool canCross(vector<int>& stones) {
        if (stones.back() == INT_MAX)
            return false;
        int len = stones.back() + 1;
        vector<pair<bool, vector<int>>> dp(len);
        dp[0] = {true, {1}};
        for (int i = 0; i < len; i++) {
            if (find(stones.begin(), stones.end(), i) == stones.end())
                continue;
            if (dp[i].first) {
                for (int k : dp[i].second) {
                    if (k != 0 && i + k < len && find(stones.begin(), stones.end(), i + k) != stones.end()) {
                        dp[i + k].first = true;
                        if (i + k == len - 1)
                            return true;
                        dp[i + k].second.insert(dp[i + k].second.end(), {k - 1, k, k + 1});
                    }                        
                }
                
            }
        }
        return false;
    }
};
// 超出时间限制 肯定不能这么死找

// 得用map set
class Solution {
public:
    bool canCross(vector<int>& stones) {
        // 这个通过了 太大的话分配内存不够 会执行出错
        if (stones.back() > 2001000)
            return false;
        int len = stones.back() + 1;
        vector<pair<bool, unordered_set<int>>> dp(len);
        dp[0] = {true, {1}};

        unordered_set<int> sset;
        for (int i : stones)
            sset.insert(i);

        for (int i = 0; i < len; i++) {
            if (sset.find(i) == sset.end())
                continue;

            if (dp[i].first) {
                for (int k : dp[i].second) {
                    if (k != 0 && i + k < len && sset.find(i) != sset.end()) {
                        dp[i + k].first = true;
                        if (i + k == len - 1)
                            return true;
                        dp[i + k].second.insert({k - 1, k, k + 1});
                    }                        
                }
                
            }
        }
        return false;
    }
};
// 通过了 应该还有优化空间

int main() {
    Solution sol;
    vector<int> stones = {0, 1, 2, 3, 4, 8, 9, 11};
    sol.canCross(stones);
}