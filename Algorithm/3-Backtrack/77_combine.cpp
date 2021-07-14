// 1-4
#include <iostream>
#include <vector>
using namespace std;

// 从1-n数字的k个数字组合 每个数字肯定只能用一次 
// for循环就是从1到n的数字
// 递归就是k次 
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combine(int n, int k) {
        vector<int> v;
        backtrack(v, n, k, 0);
        return ans;
    }

    void backtrack(vector<int> v, int n, int k, int i) {
        if (v.size() == k) {
            ans.push_back(v);
            return;
        }

        for (int j = i + 1; j <= n; j++) {
            v.push_back(j);
            backtrack(v, n, k, j); // 数字只能用一次就得+1 跟40 216一样
            v.pop_back();
        }
    }
};
// 通过了 不过有点慢