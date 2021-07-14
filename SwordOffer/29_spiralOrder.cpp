// 2-19
#include <iostream>
#include <vector>
using namespace std;

// 顺时针打印矩阵
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        if (matrix.size() == 0)
            return ans;
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int rowEnd = m, colEnd = n;
        for (int i = 0; i <= rowEnd && i <= colEnd; i++) {
            // 打印上行
            for (int j = i; j <= colEnd; j++) 
                ans.push_back(matrix[i][j]);
            
            // 打印最右列
            for (int j = i + 1; j <= rowEnd; j++)
                ans.push_back(matrix[j][colEnd]);
            
            // 打印最下行
            if (rowEnd > i) {
                for (int j = colEnd - 1; j >= i; j--)
                    ans.push_back(matrix[rowEnd][j]);
            }
            // 打印最左行
            if (i < colEnd) {
                for (int j = rowEnd - 1; j >= i + 1; j--)
                    ans.push_back(matrix[j][i]);
            }
            rowEnd--;
            colEnd--;
        }
        return ans;
    }
};
// 通过了 瑕疵就是异常情况没有考虑清楚
// 剑指offer变量太多了 不好记忆


// 3-16
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int> ans;
        // 这一段不能合在一起写
        int m = matrix.size();
        if (m == 0)
            return ans;
        int n = matrix[0].size();
        if (n == 0)
            return ans;
        int row = m - 1, col = n - 1;
        for (int k = 0; k <= row && k <= col; k++) {
            for (int i = k; i <= col; i++)
                ans.push_back(matrix[k][i]);
            for (int i = k + 1; i <= row; i++)
                ans.push_back(matrix[i][col]);
            if (row > k) {
                for (int i = col - 1; i >= k; i--)
                    ans.push_back(matrix[row][i]);
            }
            if (col > k) {
                for (int i = row - 1; i >= k + 1; i--)
                    ans.push_back(matrix[i][k]);
            }
            row--;col--;
        }
        return ans;
    }
};