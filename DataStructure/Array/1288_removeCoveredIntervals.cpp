#include <vector>
#include <algorithm>
using namespace std;

// 6-23
// 必须得是一个区间完全被另一个区间覆盖才可以消除
class Solution {
public:
    static bool cmp(const vector<int>& a, const vector<int>& b) {
        if (a[0] == b[0])
            return a[1] > b[1];
        return a[0] < b[0];
    }
    int removeCoveredIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end(), cmp);
        int ans = 1;
        for (int i = 1; i < intervals.size(); ++i) {
            if (intervals[i][0] >= intervals[i - 1][0] && intervals[i][1] <= intervals[i - 1][1]) {
                intervals[i] = intervals[i - 1];
                continue;
            }
            ++ans;
        }
        return ans;
    }
};
// 通过了