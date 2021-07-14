#include <vector>
using namespace std;

// 使用一下暴力解法 还是回溯
// 递归就是一个又一个的房子 选择就是每个房子涂成什么颜色
class Solution {
public:
    int ans = INT_MAX;
    bool isValid(const vector<int>& houses, int target) {
        int cnt = 0;
        for (int i = 0; i < houses.size(); i++) {
            if (i != 0 && houses[i] == houses[i - 1])
                continue;
            cnt++;
        }
        return cnt == target;
    }
    void backtrack(vector<int>& houses, int m, int houseidx, vector<vector<int>>& cost, int n, int sumCost, int target) {    
        if (houseidx == m) {
            if (isValid(houses, target) && sumCost < ans)
                ans = sumCost;
            return;
        }

        if (houses[houseidx] != 0) {
            backtrack(houses, m, houseidx + 1, cost, n, sumCost, target);
            return;
        }
        
        for (int color = 0; color < n; color++) {
            houses[houseidx] = color + 1;
            sumCost += cost[houseidx][color];
            backtrack(houses, m, houseidx + 1, cost, n, sumCost, target);
            sumCost -= cost[houseidx][color];
            houses[houseidx] = 0;
        }
    }

    int minCost(vector<int>& houses, vector<vector<int>>& cost, int m, int n, int target) {
        backtrack(houses, m, 0, cost, n, 0, target);
        return ans == INT_MAX ? -1 : ans;
    }
};
// 超时了 9/60
