#include <iostream>
#include <vector>
using namespace std;

// 6-14
class Solution {
public:
    int minOperationsMaxProfit(vector<int>& customers, int boardingCost, int runningCost) {
        int maxProfit = 0, ans = 0;
        int profit = 0, cur = 0, idx = 0;
        for (int i : customers) {
            cur += i;
            if (cur >= 4) {
                profit = profit + 4 * boardingCost - runningCost;
                cur -= 4;
            } else {
                profit = profit + cur * boardingCost - runningCost;
                cur = 0;
            }
            idx++;
            if (maxProfit < profit) {
                maxProfit = profit;
                ans = idx;
            }
        }
        while (cur != 0) {
            if (cur >= 4) {
                profit = profit + 4 * boardingCost - runningCost;
                cur -= 4;
            } else {
                profit = profit + cur * boardingCost - runningCost;
                cur = 0;
            }
            idx++;
            if (maxProfit < profit) {
                maxProfit = profit;
                ans = idx;
            }
        }
        return maxProfit > 0 ? ans : -1;
    }
};
// 是个模拟题 通过

int main() {
    Solution sol;
    vector<int> customers = {8, 3};
    sol.minOperationsMaxProfit(customers, 5, 6);
}