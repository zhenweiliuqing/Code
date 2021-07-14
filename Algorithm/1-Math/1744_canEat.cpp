#include <iostream>
#include <vector>
using namespace std;

// 6-1
// 还是要注意数值范围
class Solution {
public:
    vector<bool> canEat(vector<int>& candiesCount, vector<vector<int>>& queries) {
        int n = queries.size();
        vector<bool> ans(n);
        vector<long> candiesSum(candiesCount.begin(), candiesCount.end());

        for (int i = 1; i < candiesSum.size(); i++) {
            candiesSum[i] += candiesSum[i - 1];
        }

        for (int k = 0; k < n; k++) {
            auto q = queries[k];
            // 要吃的糖果的范围
            int type = q[0];
            long r1 = type == 0 ? 1 : candiesSum[type - 1] + 1, r2 = candiesSum[type];

            long day = q[1] + 1, maxeatOneday = q[2];
            // 能吃到的范围
            long eatr1 = day, eatr2 = day * maxeatOneday;

            // 要吃的糖果范围跟能吃的糖果范围重合就是true
            if (eatr2 < r1 || r2 < eatr1)
                ans[k] = false;
            else
                ans[k] = true;
        }
        return ans;
    }
};
// 通过了

int main() {
    Solution sol;
    vector<int> c = {5, 2, 6, 4, 1};
    vector<vector<int>> q = {{3, 1, 2}, {4, 10, 3}, {3, 10, 100}, {4, 100, 30}, {1, 3, 1}};
    sol.canEat(c, q);
}