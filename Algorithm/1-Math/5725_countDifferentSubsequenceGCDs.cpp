#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

// 这道题超时了 会把求一个序列的最大公约数求出来就可以了

class Solution {
public:
    unordered_set<int> sset;    
    // 求两个数的最大公约数
    int gcd(int a, int b) {
        if (a < b) swap(a, b);
        return b == 0 ? a : gcd(b, a % b);
    }

    int gcd(int a, int b) {
        if (a < b)
            swap(a, b);
        else if (a == b)
            return a;
        
        while (a % b != 0) {
            a = a % b;
            if (a < b)
                swap(a, b);
        }
        return b;
    }
    
    int calGCD(vector<int>& nums) {
        if (nums.size() == 0)
            return 0;
        if (nums.size() == 1)
            return nums[0];
        
        int first = nums[0];
        for (int i = 1; i < nums.size(); i++) {
            int x = gcd(first, nums[i]);
            if (x == 1)
                return 1;
            else 
                first = x;
        }
        return first;
    }
    
    int countDifferentSubsequenceGCDs(vector<int>& nums) {
        int n = nums.size();
        vector<int> tmp;
        for (int mask = 0; mask < (1 << n); mask++) {
            tmp.clear();
            for (int i = 0; i < n; i++) {
                if (mask & (1 << i)) {
                    tmp.push_back(nums[i]);
                }
            }
            sset.insert(calGCD(tmp));
        }
        return sset.size() - 1;
    }

    // void backtrack(vector<int>& nums, vector<int>& tmp, int st) {
    //     if (tmp.size() == 1)
    //         sset.insert(tmp[0]);
    //     else 
    //         sset.insert(calGCD(tmp));
        
    //     for (int i = st + 1; i < nums.size(); i++) {
    //         tmp.push_back(nums[i]);
    //         backtrack(nums, tmp, i); // 竟然在这里出现了错误！！
    //         tmp.pop_back();
    //     }
    // }
    
    // int countDifferentSubsequenceGCDs(vector<int>& nums) {
    //     vector<int> tmp;
    //     backtrack(nums, tmp, -1);
    //     return sset.size() - 1;
    // }
};

int main() {
    Solution sol;
    vector<int> v = {3, 6, 10};
    sol.countDifferentSubsequenceGCDs(v);
}

