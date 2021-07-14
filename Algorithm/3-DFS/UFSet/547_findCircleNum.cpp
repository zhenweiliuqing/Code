// 4-13
#include <iostream>
#include <vector>
using namespace std;

// 并查集
class Solution {
public:
    int father[200];
    int findFather(int x) {
        if (x == father[x])
            return x;
        father[x] = findFather(father[x]);
        return father[x];
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        for (int i = 0; i < 200; i++) {
            father[i] = i;
        }
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    // isConnected[i][j] = 0;
                    // isConnected[j][i] = 0; 这里加个两行完全不影响 看到grid[i][j] = 0; 但其实一点用也没有
                    int fa = findFather(i);
                    int fb = findFather(j);
                    if (fa != fb)
                        father[fa] = fb;
                }
            }
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (father[i] == i)
                ans++;
        }
        return ans;
    }
};

// DFS
// 这个选择跟岛屿数量的选择还是不一样
// 岛屿数量下一步就是选择上下左右的位置 这个应该是选择城市连通的位置
class Solution {
public:
    bool isVisited[200];
    void dfs(vector<vector<int>>& isConnected, int start) {
        int n = isConnected.size();
        // 这个得从0开始 如果跳到最后一行还得回头看看
        for (int i = 0; i < n; i++) {
            if (!isVisited[i] && isConnected[start][i] == 1) {
                isVisited[i] = true;
                dfs(isConnected, i);
            }
        }
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (isVisited[i])
                continue;
            isVisited[i] = true; // 这个可以省去是因为isConnected[i][i]等于1 从i开始一定会到i
            dfs(isConnected, i);
            ans++;
        }
        return ans;
    }
};
// 通过了