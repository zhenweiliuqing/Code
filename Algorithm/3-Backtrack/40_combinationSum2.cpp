// 1-5 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 数组中数字可能重复 但是每个数字每个组合只能使用一次
// 数字和成为目标值

// 5-18
// for循环就是 candidates的元素 需要避免重复 下个递归从下一个元素开始
// 递归的限制由sum和target决定 每次递归从下一个元素开始就好
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& candidates, int target, vector<int> tmp, int sum, int i) {
        if (sum > target)
            return;
        if (sum == target) {
            ans.push_back(tmp);
            return;
        }

        // 效率太低
        // if (sum == target) {
        //     sort(tmp.begin(), tmp.end());
        //     if (!count(ans.begin(), ans.end(), tmp))
        //         ans.push_back(tmp);
        //     return;
        // }

        for (int j = i; j < candidates.size(); j++) {
            // 需要把重复的跳过
            if (j != i && candidates[j] == candidates[j - 1])
                continue;
            tmp.push_back(candidates[j]);
            backtrack(candidates, target, tmp, sum + candidates[j], j + 1); // 数字只能用一次就得+1 跟77 216一样
            tmp.pop_back();
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        vector<int> tmp;
        sort(candidates.begin(), candidates.end());
        backtrack(candidates, target, tmp, 0, 0);
        return ans;
    }
};
// 通过了 可以 剪枝需要效率高一些

int main() {
    Solution sol;
    // vector<int> v = {1, 2, 3};
    // vector<vector<int>> ans = {{1, 2, 3}, {1, 2}};
    // int num = count(ans.begin(), ans.end(), v);

    vector<int> v = {1, 1, 1};
    sol.combinationSum2(v, 5);
    return 0;
}
