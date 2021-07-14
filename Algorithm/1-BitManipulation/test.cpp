#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;

// class Solution {
// public:
//     vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//         vector<int> ans;
//         int max = pow(2, maximumBit) - 1;
//         int tmp = ~nums[0]; // 怎么对部分取反
//         for (int i = 0; i < nums.size(); i++) {
//             tmp = tmp ^ nums[i];
//             ans.push_back(tmp ^ max);
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// class Solution {
// public:
//     vector<int> getMaximumXor(vector<int>& nums, int maximumBit) {
//         vector<int> ans;
//         int max = pow(2, maximumBit) - 1;
//         // int tmp = ~nums[0];
//         int tmp = nums[0];
//         ans.push_back(tmp ^ max);
//         for (int i = 1; i < nums.size(); i++) {
//             tmp = tmp ^ nums[i];
//             ans.push_back(tmp ^ max);
//         }
//         reverse(ans.begin(), ans.end());
//         return ans;
//     }
// };

// int main() {
//     Solution sol;
//     vector<int> v = {0, 1, 1, 3};
//     sol.getMaximumXor(v, 2);
//     return 0;
// }

class Solution {
public:
    int maxIndexi(string& s) {
        for (int i = s.size() - 1; i > 0; i--) {
            if (s[i] < s[i - 1])
                return i;
        }
        return -1;
    }
    
    int maxIndexj(string& s, int i) {
        int j;
        for (j = i; j < s.size(); j++) {
            if (s[j] > s[i - 1])
                return j - 1;
        }
        return j-1;
    }
    
    bool isSorted(string s) {
        string tmp = s;
        sort(s.begin(), s.end());
        if (tmp == s)
            return true;
        return false;
        // return tmp == s;
    }
    
    int makeStringSorted(string s) {
        long long op = 0;
        while (!isSorted(s)) {
            int i = maxIndexi(s);
            int j = maxIndexj(s, i);
            swap(s[i-1], s[j]);
            reverse(s.begin() + i, s.end());
            op++;
        }
        return op % 1000000007;
    }
};

int main() {
    Solution sol;
    sol.makeStringSorted("cba");
    return 0;
}