// 3-9
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n == 0)
            return 0;
        int ans = 0;
        int curMin = prices[0];
        for (int i = 1; i < n; i++) {
            curMin = min(curMin, prices[i]);
            ans = max(ans, prices[i] - curMin);
        }
        return ans;
    }
};