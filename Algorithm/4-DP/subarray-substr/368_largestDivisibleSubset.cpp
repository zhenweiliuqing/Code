// 1-26
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 有点像最长上升子序列 这个把数组排个序后 需要判断nums[i] % nums[j] == 0 由num[j]的状态转移而来 然后挑个长的
 
// 动态规划 状态 dp[i] 以i为结尾数字序列最长的子集
// 转移 如果i%j==0 那么之前的状态就可以直接用 再加上自己就是新的状态
class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans;
        sort(nums.begin(), nums.end());
        vector<vector<int>> dp(n);
        dp[0].push_back(nums[0]);
        ans = dp[0];
        for (int i = 1; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] % nums[j] == 0 &&  dp[i].size() < dp[j].size()) {
                    dp[i] = dp[j];
                }
            }
            dp[i].push_back(nums[i]);
            if (ans.size() < dp[i].size())
                ans = dp[i];
        }
        return ans;
    }
};
// 通过了 可以的 就是刚开始没想明白怎么动态规划 状态没想好 转移的思路是有的

class Solution1 {
public:
    unordered_map<int, bool> isVisited;
    //unordered_set<int> sset;
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            isVisited[nums[i]] = false;
            //sset.insert(nums[i]);
        }
        int count = 0;
        vector<int> ans;
        while (count != n) {
            vector<int> tmp;
            for (int i = 0; i < n; i++) {
                if (isVisited[nums[i]])
                    continue;
                if (tmp.size() == 0) {
                    tmp.push_back(nums[i]);
                    isVisited[nums[i]] = true;
                    count++;
                } else if (nums[i] % tmp[tmp.size() - 1] == 0) {
                    tmp.push_back(nums[i]);
                }
            }
            if (tmp.size() > ans.size())
                ans = tmp;
        }
        return ans;
    }
};
// 这种不行 还是第一个能算到 后面更长的没机会了 
// 然后想到回溯了 感觉回溯效率会比较低

class Solution {
public:
    vector<int> ans;
    void backtrack(vector<int>& nums, int start, vector<int> tmp) {
        if (start == nums.size())
            return;

        for (int i = start; i < nums.size(); i++) {
            if (nums[i] % tmp[tmp.size() - 1] == 0) {
                tmp.push_back(nums[i]);
                if (tmp.size() > ans.size())
                    ans = tmp;
                backtrack(nums, i + 1, tmp);
                tmp.pop_back();
            }
        }
    }

    vector<int> largestDivisibleSubset(vector<int>& nums) {
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++) {
            tmp.push_back(nums[i]);
            if (tmp.size() > ans.size())
                ans = tmp;
            backtrack(nums, i + 1, tmp);
            tmp.pop_back();
        }
        return ans;
    }
};
// 果然超出时间限制了



int main() {
    Solution sol;
    vector<int> v = {2,3,4,9,8};
    sol.largestDivisibleSubset(v);
}