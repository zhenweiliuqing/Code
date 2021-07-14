#include <iostream>
#include <vector>
#include <numeric>
using namespace std;

// 6-24
class Solution {
public:
    int isValid(int start, vector<int>& gas, vector<int>& cost) {
        int tank = 0, n = gas.size();
        int cnt = 0;
        for (int i = start; i < start + n; ++i) {
            tank += gas[i % n];
            tank -= cost[i % n];
            if (tank < 0)
                return cnt;
            ++cnt;
        }
        return cnt;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);
        if (gasSum < costSum)
            return -1;
        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] - cost[i] < 0)
                continue;
            int cnt = isValid(i, gas, cost);
            if (cnt == gas.size())
                return i;
            else
                i = i + cnt;
        }
        return -1;
    }
};
// 通过了 这次快多了
// [5,8,2,8]
// [6,5,6,6]


// 6-24
class Solution {
public:
    bool isValid(int start, vector<int>& gas, vector<int>& cost) {
        int tank = 0, n = gas.size();
        for (int i = start; i < start + n; ++i) {
            tank += gas[i % n];
            tank -= cost[i % n];
            if (tank < 0)
                return false;
        }
        return true;
    }
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int gasSum = accumulate(gas.begin(), gas.end(), 0);
        int costSum = accumulate(cost.begin(), cost.end(), 0);
        if (gasSum < costSum)
            return -1;
        for (int i = 0; i < gas.size(); ++i) {
            if (gas[i] - cost[i] < 0)
                continue;
            if (isValid(i, gas, cost))
                return i;
        }
        return -1;
    }
};
// 通过了 但是可以优化