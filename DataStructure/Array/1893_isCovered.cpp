#include <vector>
#include <algorithm>
using namespace std;

// 6-23
// 56题也是合并
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> merged;
        merged.push_back(ranges[0]);
        for (int i = 1; i < ranges.size(); ++i) {
            if (ranges[i][0] > merged.back()[1] + 1)
                merged.push_back(ranges[i]);
            else
                merged.back()[1] = max(merged.back()[1], ranges[i][1]);
        }
        for (auto it : merged) {
            if (it[0] <= left && it[1] >= right)
                return true;
        }
        return false;
    }
};
// 通过 更优雅了一些

// 6-23
// 这个跟区间有关
class Solution {
public:
    bool isCovered(vector<vector<int>>& ranges, int left, int right) {
        sort(ranges.begin(), ranges.end());
        vector<vector<int>> merged;
        int t1 = ranges[0][0], t2 = ranges[0][1];
        for (int i = 1; i < ranges.size(); ++i) {
            if (ranges[i][0] > t2 + 1) {
                merged.push_back({t1, t2});
                t1 = ranges[i][0];
                t2 = ranges[i][1];
            } else {
                t2 = max(t2, ranges[i][1]);
            }
        }
        merged.push_back({t1, t2});
        for (auto it : merged) {
            if (it[0] <= left && it[1] >= right)
                return true;
        }
        return false;
    }
};
// 通过