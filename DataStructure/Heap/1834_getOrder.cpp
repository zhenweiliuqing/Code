#include <vector>
#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

// 6-6
class Solution {
public:
    // 能进来的话时间都符合要求 主要就是比执行时间和下标
    static bool cmp(const pair<int, int>& p1, const pair<int, int>& p2) {
        if (p1.first == p2.first)
            return p1.second > p2.second;
        return p1.first > p2.first;
    }

    vector<int> getOrder(vector<vector<int>>& tasks) {
        vector<int> ans;
        for (int i = 0; i < tasks.size(); i++) {
            tasks[i].push_back(i);
        }
        // 复合vector是按照标准什么排序的
        sort(tasks.begin(), tasks.end()); // 按照入队时间 处理时间 下标 从小到大排序
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);
        int t = tasks[0][0], i = 0; // 运行时间
        while (i < tasks.size()) {            
            while (i < tasks.size() && tasks[i][0] <= t) {
                q.emplace(make_pair(tasks[i][1], tasks[i][2]));
                i++;
            }
            // 有的执行完下一个任务还没来
            if (q.empty()) {
                t = tasks[i][0];
                continue;
            }
            auto it = q.top();
            ans.push_back(it.second);
            t = it.first + t;
            q.pop();
        }
        while (!q.empty()) {
            ans.push_back(q.top().second);
            q.pop();
        }
        return ans;
    }
};
// 通过了 
// {{5,2},{7,2},{9,4},{6,3},{5,10},{1,1}}