// 3-29
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int ans = 0;
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                if (i == 0 || grid[i - 1][j] == 0)
                    ans++;
                if (j == 0 || grid[i][j - 1] == 0)
                    ans++;
                if (i == m - 1 || grid[i + 1][j] == 0)
                    ans++;
                if (j == n - 1 || grid[i][j + 1] == 0)
                    ans++;
            }
        }
        return ans;
    }
};
// 通过


// 这题我傻了 直接一个一个判断也出来了
// 总是heap buffer overflow 
class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& isVisited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || isVisited[i][j])
            return;
        isVisited[i][j] = true;
        if (i == 0 || grid[i - 1][j] == 0)
            ans++;
        if (j == 0 || grid[i][j - 1] == 0)
            ans++;
        // 这里两个大错没发现？？
        if (i == grid.size() || grid[i + 1][j] == 0)
            ans++;
        if (i == grid[0].size() || grid[i][j + 1] == 0)
            ans++;
        dfs(grid, i + 1, j, isVisited);
        dfs(grid, i - 1, j, isVisited);
        dfs(grid, i, j + 1, isVisited);
        dfs(grid, i, j - 1, isVisited);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isVisited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                dfs(grid, i, j, isVisited);
            }
        }
        return ans;
    }
};



class Solution {
public:
    int ans = 0;
    void dfs(vector<vector<int>>& grid, int i, int j, vector<vector<bool>>& isVisited) {
        if (i < 0 || j < 0 || i >= grid.size() || j >= grid[0].size() || grid[i][j] == 0 || isVisited[i][j])
            return;
        isVisited[i][j] = true;
        if (i == 0 || grid[i - 1][j] == 0)
            ans++;
        if (j == 0 || grid[i][j - 1] == 0)
            ans++;
        // 这里两个大错没发现？？
        if (i == grid.size() - 1 || grid[i + 1][j] == 0)
            ans++;
        if (j == grid[0].size() - 1 || grid[i][j + 1] == 0)
            ans++;
        dfs(grid, i + 1, j, isVisited);
        dfs(grid, i - 1, j, isVisited);
        dfs(grid, i, j + 1, isVisited);
        dfs(grid, i, j - 1, isVisited);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<bool>> isVisited(m, vector<bool>(n));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == 0)
                    continue;
                dfs(grid, i, j, isVisited);
            }
        }
        return ans;
    }
};
// 这个通过了
