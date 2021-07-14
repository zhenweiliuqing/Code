#include <vector>
#include <algorithm>
using namespace std;

// 6-23
class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {
        intervals.push_back(newInterval);
        sort(intervals.begin(), intervals.end());
        vector<vector<int>> v;
        v.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); ++i) {
            if (v.back()[1] < intervals[i][0])
                v.push_back(intervals[i]);
            else
                v.back()[1] = max(v.back()[1], intervals[i][1]);
        }
        return v;
    }
};
// 通过了 这不跟56一样
// 这个已经是排过序的 这样做效率太低