#include <iostream>
#include <vector>
using namespace std;

// 1-9 k个数相加等于n 每种组合中不能有重复的数
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(int k, int n, vector<int> tmp, int start) {
        if (tmp.size() == k) {
            int sum = 0;
            for (int i = 0; i < k; i++)
                sum += tmp[i];
            if (sum == n)
                ans.push_back(tmp);
            return;
        }
    
        for (int i = start; i <= 9; i++) {
            tmp.push_back(i);
            backtrack(k, n, tmp, i + 1); // 数字只能用一次就得+1 跟40 77一样
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int> tmp;
        backtrack(k, n, tmp, 1);
        return ans;
    }
};
// 通过了 这题很一般