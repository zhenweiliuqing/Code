#include <iostream>
#include <vector>
using namespace std;

// 还得跟哈希表有关 用一个vector存储一下人数
class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        vector<int> p(101);
        for (auto log : logs) {
            for (int i = log[0]; i < log[1]; i++) {
                p[i - 1950]++;
            }
        }
        int maxid = 0;
        for (int i = 0; i < 101; i++) {
            if (p[i] > p[maxid]) {
                maxid = i;
            }
        }
        return maxid + 1950;
    }
};
// 通过了