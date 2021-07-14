#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 合并区间 主要是两个问题
// 第一是排序 第二是多区间合并 v.back()[1]比较关键
class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size() == 0)
            return intervals;
        vector<vector<int>> v;
        // 对元素挨个比较 按照从小到大排序 字典序
        sort(intervals.begin(), intervals.end());
        v.push_back(intervals[0]);
        for (int i = 1; i < intervals.size(); i++) {
            // 如果后边一个的开始大于第一个的结尾 那就不重叠了
            if (intervals[i][0] > v.back()[1])
                v.push_back(intervals[i]);
            else
                v.back()[1] = max(v.back()[1], intervals[i][1]); // 更新结尾
        }
        return v;
    }
};
// 完成了 但是感觉用时较长啊！！

class Solution1 {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        int pre_r, next_l;
        vector<vector<int>> ret;
        for (int i = 0; i < intervals.size(); i++) {
            vector<int> temp;
            if (i == intervals.size() - 1) {
                ret.push_back(intervals[i]);
                break;
            }
            pre_r = intervals[i][1];
            next_l = intervals[i + 1][0];
            if (next_l <= pre_r) {
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i + 1][1]);
                ret.push_back(temp);
                i++;
            } else {
                temp.push_back(intervals[i][0]);
                temp.push_back(intervals[i][1]);
                ret.push_back(temp);                
            }
        }
        return ret;
    }
};

