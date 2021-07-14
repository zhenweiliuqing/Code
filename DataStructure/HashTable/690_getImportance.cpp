#include <unordered_map>
#include <queue>
#include <vector>
using namespace std;
// Definition for Employee.
class Employee {
public:
    int id;
    int importance;
    vector<int> subordinates;
};


class Solution {
public:
    int ans = 0;
    unordered_map<int, Employee*> mmap;
    void dfs(Employee* root) {
        ans += root->importance;
        if (root->subordinates.size() == 0)
            return;
        for (auto it : root->subordinates)
            dfs(mmap[it]);
    }

    int getImportance(vector<Employee*> employees, int id) {
        for (auto employee: employees)
            mmap[employee->id] = employee;
        dfs(mmap[id]);
        return ans;
    }
};
// 通过 
// 1145要找到一个根节点 能用map吗 应该不需要

// BFS
class Solution {
public:
    unordered_map<int, Employee*> mmap;
    int getImportance(vector<Employee*> employees, int id) {
        for (auto employee : employees) {
            mmap[employee->id] = employee;
        }
        queue<int> q;
        q.push(id);
        int ans = 0;
        while (!q.empty()) {
            int tmp = q.front();
            q.pop();
            ans += mmap[tmp]->importance;
            for (auto it : mmap[tmp]->subordinates) {
                q.push(it);
            }
        }
        return ans;
    }
};
// 通过