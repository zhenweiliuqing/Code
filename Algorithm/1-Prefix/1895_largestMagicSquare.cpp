#include <vector>
using namespace std;

// 6-23 
// 这看着得用前缀和
// 被矩阵给绕糊涂了
class Solution {
public:
    bool isValid(int i, int j, int k, const vector<vector<int>>& grid, const vector<vector<int>>& rowSum, const vector<vector<int>>& colSum) {
        int target = rowSum[i + 1][j + k + 1] - rowSum[i + 1][j];
        for (int x = i + 1; x <= i + k + 1; ++x) {
            if (rowSum[x][j + k + 1] - rowSum[x][j] != target)
                return false;
        }
        for (int x = j + 1; x <= j + k + 1; ++x) {
            if (colSum[i + k + 1][x] - colSum[i][x] != target)
                return false;
        }
        int lr = 0, rl = 0;
        int t = 0;
        while (t <= k) {
            lr += grid[i + t][j + t];
            t++;
        }
        t = 0;
        while (t <= k) {
            rl += grid[i + k - t][j + t];
            t++;
        }
        if (lr != target || rl != target)
            return false;
        return true;
    }
    int largestMagicSquare(vector<vector<int>>& grid) {
        vector<vector<int>> rowSum, colSum;
        int m = grid.size(), n = grid[0].size();
        rowSum.resize(m + 1, vector<int>(n + 1));
        colSum.resize(m + 1, vector<int>(n + 1));
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                rowSum[i][j] = rowSum[i][j - 1] + grid[i - 1][j - 1];
            }
        }
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= m; j++) {
                colSum[j][i] = colSum[j - 1][i] + grid[j - 1][i - 1];
            }
        }

        int len = min(m, n) - 1; 
        // 这个k不是长度 i+k是下标
        for (int k = len; k >= 1; --k) {
            // 遍历每一个位置
            for (int i = 0; i + k < m; ++i) {
                for (int j = 0; j + k < n; ++j) {
                    if (isValid(i, j, k, grid, rowSum, colSum))
                        return k + 1;
                }
            }
        }
        return 1;
    }
};
// 这题不好写 有点麻烦
// 终于通过了 很多细节都太麻烦了

int main() {
    Solution sol;
    vector<vector<int>> v = {{5, 1, 3, 1}, {9, 3, 3, 1}, {1, 3, 3, 8}};
    // vector<vector<int>> v = {{7, 1, 4, 5, 6}, {2, 5, 1, 6, 4}, {1, 5, 4, 3, 2}, {1, 2, 7, 3, 4}};
    sol.largestMagicSquare(v);
}