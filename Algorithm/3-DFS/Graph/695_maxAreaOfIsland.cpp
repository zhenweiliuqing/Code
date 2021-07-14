// 3-29
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 这个把岛屿数量和岛屿面积给统一起来了
// 反正greater就代表 > 
// 在排序中 是从大到小排序 比较用 >
// 优先队列中 greater<int>() 是升序 最小堆 
class Solution {
public:
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;
        area++;
        grid[i][j] = 0;
        dfs(grid, i + 1, j, area);
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j + 1, area);
        dfs(grid, i, j - 1, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        vector<int> island;
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                int area = 0;
                dfs(grid, i, j, area);
                island.push_back(area);
            }
        }
        sort(island.begin(), island.end(), greater<int>());
        return island.size() == 0 ? 0 : island[0];
    }
};

class Solution {
public:
    int maxArea = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, int& area) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0)
            return;
        area++;
        if (area > maxArea)
            maxArea = area;
        grid[i][j] = 0;
        dfs(grid, i + 1, j, area);
        dfs(grid, i - 1, j, area);
        dfs(grid, i, j + 1, area);
        dfs(grid, i, j - 1, area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                int area = 0;
                dfs(grid, i, j, area);
            }
        }
        return maxArea;
    }
};
// 通过