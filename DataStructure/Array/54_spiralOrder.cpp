// 2-19
#include <iostream>
#include <vector>
using namespace std;

// 顺时针打印矩阵
// 这个最好记忆 就用这个
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

// 3-15
// 模拟题
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        vector<int> ans;
        for (int k = 0; k <= m / 2 && k <= n / 2; k++ ) {
            for (int i = k; i <= n - k; i++)
                ans.push_back(matrix[k][i]);
            for (int i = k + 1; i <= m - k; i++)
                ans.push_back(matrix[i][n - k]);
            if (m - k > k) {
                for (int i = n - k - 1; i >= k; i--)
                    ans.push_back(matrix[m - k][i]);
            }
            if (k < n - k) {
                for (int i = m - k - 1; i >= k + 1; i--) 
                    ans.push_back(matrix[i][k]);
            }
        }
        return ans;
    }
};