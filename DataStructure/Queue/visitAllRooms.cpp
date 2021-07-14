// 思路：用dfs 跟求连通域差不多
// 进到一个房间看见钥匙 push进stack 

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
using namespace std;

class Solution {
private:
    vector<bool> visit;
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int rnums = rooms.size();
        visit.resize(rnums);
        queue<int> s; // 这里应该用队列 不是用栈
        s.push(0);
        while (!s.empty()) {
            int temp = s.front();
            visit[temp] = true;
            for (int j = 0; j < rooms[temp].size(); j++) {
                if (!visit[rooms[temp][j]])
                    s.push(rooms[temp][j]); // push emplace区别
            }
            s.pop();
        }
        for (int i = 0; i < rnums; i++) {
            if (!visit[i])
                return false;
        }
        return true;
    }
};

// 其实这是用的queue 广度优先搜索