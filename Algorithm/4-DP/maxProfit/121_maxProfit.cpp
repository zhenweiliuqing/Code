#include <iostream>
#include <vector>

// 一次操作 
// 如果遇到更小的数 就记下最小值 后边的利润肯定更大 之前的最大利润肯定也记下来了
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int n = prices.size();
        int mindex = 0;
        for (int i = 0; i < n; i++) {
            if (prices[i] < prices[mindex])
                mindex = i;
            if (prices[i] - prices[mindex] > max)
                max = prices[i] - prices[mindex];
        }
        return max;
    }
};
// 通过


// 又是只想到O(n2)
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int max = 0;
        int n = prices.size();
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (max < prices[j] - prices[i])
                    max = prices[j] - prices[i];
            }
        }
        return max;
    }
};



