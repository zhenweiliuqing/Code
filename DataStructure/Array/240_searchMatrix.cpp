// 3-15
// 已经是最优解了
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size() - 1, n = matrix[0].size() - 1;
        int row = 0, col = n;
        while (row <= m && col >= 0) {
            int tmp = matrix[row][col];
            if (tmp == target)
                return true;
            else if (tmp > target)
                col--;
            else if (tmp < target)
                row++;
        }
        return false;
    }
};
