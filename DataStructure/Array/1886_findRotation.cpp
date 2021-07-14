#include <vector>
#include <string>
using namespace std;

// 6-7
// 看看顺时针打印那个题
// 还是直接旋转吧 好像也有一个题
class Solution {
public:
    void rotate(vector<vector<int>>& mat, int n) {
        for (int i = 0; i < n / 2; i++) {
            for (int j = 0; j < (n + 1) / 2; j++) {
                int tmp = mat[i][j];
                mat[i][j] = mat[n - 1 - j][i];
                mat[n - 1 - j][i] = mat[n - 1 - i][n - 1 - j];
                mat[n - 1 - i][n - 1 - j] = mat[j][n - 1 - i];
                mat[j][n - 1 - i] = tmp;
            }
        }
    }
    bool findRotation(vector<vector<int>>& mat, vector<vector<int>>& target) {
        int n = mat.size();
        for (int i = 0; i < 3; i++) {
            if (mat == target)
                return true;
            rotate(mat, n);
        }
        return mat == target;
    }
};

int main() {
    vector<vector<int>> mat = {{0, 0, 0}, {0, 1, 0}, {1, 1, 1}};
    vector<vector<int>> target = {{1, 1, 1}, {0, 1, 0}, {0, 0, 0}};
    Solution sol;
    sol.findRotation(mat, target);
}