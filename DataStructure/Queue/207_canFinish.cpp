#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses, 0);
        int n = prerequisites.size();
        
        // 建立入度表
        for (int i = 0; i < n; i++) {
            indegree[prerequisites[i][0]]++;
        }
        // 建立图
        vector<vector<int>> graph(numCourses, vector<int>(numCourses));
        for (int i = 0; i < n; i++) {
            graph[prerequisites[i][1]][prerequisites[i][0]] = 1;
        }

        queue<int> q;
        for (int i = 0; i < numCourses; i++) {
            if (indegree[i] == 0)
                q.push(i);
        }
        int cnt = numCourses;
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            cnt--;
            for (int i = 0; i < numCourses; i++) {
                if (graph[node][i] == 1) {
                    indegree[i]--;
                    if (indegree[i] == 0)
                        q.push(i);
                }
            }
        }
        return cnt == 0;
    }
};
// 通过了

int main() {
    Solution a;
    vector<vector<int>> pre;
    vector<int> v(2);
    v[0] = 1;
    v[1] = 0;
    pre.push_back(v);
    v[0] = 2;
    v[1] = 1;
    pre.push_back(v);
    a.canFinish(3, pre);
}
