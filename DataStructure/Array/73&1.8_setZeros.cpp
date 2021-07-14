#include <iostream>
#include <vector>
#include <set>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        set<int> row, col;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (auto it = row.begin(); it != row.end(); it++) {
            for (int j = 0; j < n; j++) {
                matrix[*it][j] = 0;
            }
        }

        for (int i = 0; i < m; i++) {
            for (auto it = col.begin(); it != col.end(); it++) {
                matrix[i][*it] = 0;
            }
        }
    }
};
// 通过

class Solution1 {
public:
    void setZeros(vector<vector<int>>& matrix) {
        int mRow = matrix.size();
        int mCol = matrix[0].size();
        if (mRow == 0 || mCol == 0)
            return;
        vector<bool> row(mRow, false);
        vector<bool> col(mCol, false);
        for (int i = 0; i < mRow; i++) {
            for (int j = 0; j < mCol; j++) {
                if (matrix[i][j] == 0) {
                    row[i] = true;
                    col[j] = true;
                }
            }
        }
        for (int i = 0; i < mRow; i++) {
            for (int j = 0; j < mCol; j++) {
                if (row[i] || col[j])
                    matrix[i][j] = 0;
            }
        }
    }
};

// 3-15
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        set<int> row, col;
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j <= n; j++) {
                if (matrix[i][j] == 0) {
                    row.insert(i);
                    col.insert(j);
                }
            }
        }
        for (auto it = row.begin(); it != row.end(); it++) {
            for (int j = 0; j <= n; j++)
                matrix[*it][j] = 0;
        }
        for (auto it = col.begin(); it != col.end(); it++) {
            for (int i = 0; i <= m; i++)
                matrix[i][*it] = 0;
        }
    }
};

// 最优解
// 不用额外空间
// 遍历矩阵 发现是0 就把行首和列首置为0
