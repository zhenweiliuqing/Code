#include <vector>
using namespace std;

// 6-20
class Solution {
public:
    int ans = 0;
    int isSub = true;
    void dfs(vector<vector<int>>& grid1, vector<vector<int>>& grid2, int m, int n, int i, int j) {
        if (i < 0 || j < 0 || i >= m || j >= n || grid2[i][j] == 0)
            return;
        if (grid1[i][j] == 0)
            isSub = false;
        grid2[i][j] = 0;
        dfs(grid1, grid2, m, n, i + 1, j);
        dfs(grid1, grid2, m, n, i, j - 1);
        dfs(grid1, grid2, m, n, i - 1, j);
        dfs(grid1, grid2, m, n, i, j + 1);
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int m = grid2.size(), n = grid2[0].size();
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (grid2[i][j] == 0)
                    continue;
                isSub = true;
                dfs(grid1, grid2, m, n, i, j);
                if (isSub)
                    ans++;
            }
        }
        return ans;
    }
};
// 通过了