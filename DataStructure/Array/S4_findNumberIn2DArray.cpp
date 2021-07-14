// 1-29
#include <iostream>
#include <vector>
using namespace std;

// 思路：就是卡右上角那个点 往坐下搜索
class Solution1 {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) // 关键
            return false;
        int m = 0, n = matrix[0].size() - 1;
        while (m < matrix.size() && n >= 0) {
            if (matrix[m][n] > target)
                n--;
            else if (matrix[m][n] < target)
                m++;
            else if (matrix[m][n] == target)
                return true;
        }
        return false;
    }
};
// 通过了
// 为什么这个比二分搜索还快

// 可以用二分搜索优化一下
class Solution {
public:
    bool findNumberIn2DArray(vector<vector<int>>& matrix, int target) {
        if (matrix.size() == 0) // 关键
            return false;
        int m = 0, n = matrix[0].size() - 1;
        while (m <= matrix.size() - 1  && n >= 0) {
            if (matrix[m][n] > target)
                n = binarySearchCol(matrix, target, 0, n, m);
            else if (matrix[m][n] < target)
                m = binarySearchRow(matrix, target, m, matrix.size() - 1, n);
            else if (matrix[m][n] == target)
                return true;
        }
        return false;
    }

    int binarySearchCol(vector<vector<int>>& matrix, int target, int i, int j, int m) {
        int left = i, right = j;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (matrix[m][mid] > target)
                right = mid - 1;
            else if (matrix[m][mid] <= target)
                left = mid + 1;
        }
        return right;
    }

    int binarySearchRow(vector<vector<int>>& matrix, int target, int i, int j, int n) {
        int left = i, right = j;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (matrix[mid][n] >= target)
                right = mid - 1;
            else if (matrix[mid][n] < target)
                left = mid + 1;
        }
        return left;
    }
};
// 通过了 注意边界情况 
// 可能没有target 返回-1 这里不用特殊处理 不过要记得

int main() {
    Solution sol;
    vector<vector<int>> v = {{1, 4, 7, 11, 15}, {2, 5, 8, 12, 19}, {3, 6, 9, 16, 22}, {10, 13, 14, 17, 24}, {18, 21, 23, 26, 30}};
    sol.findNumberIn2DArray(v, 5);
}