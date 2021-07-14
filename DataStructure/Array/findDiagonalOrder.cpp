#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:

    vector<int> findDiagonalOrder(vector<vector<int>>& matrix) {
        vector<int> ret;
        int m = matrix.size(), n = matrix[0].size();
        int i = 0, j = 0;
        bool right_up = true, left_down = false;
        while (i < m && j < n && i >= 0 && j >= 0) { 
            ret.push_back(matrix[i][j]);
            if (right_up) { 
                if (i == 0 || j == n -1) {//上不了了
                    right_up = false;
                    left_down = true;
                    if (j == n - 1) // 一般只有一次相等 在顶点
                        i--; // 下移
                    else if (i == 0)
                        j++; // 右移
                    continue;
                }
                i++;j--;
            } else if (left_down) {
                if (i == n -1 || j == 0) {//下不了了
                    right_up = false;
                    left_down = true;
                    if (i == n - 1)
                        j++;
                    else if (j == 0)
                        i++;
                    continue;
                }
                i--;j++;
            }
        }
        return ret;
    }
};
// 条件不严谨啊  看着简单 实际漏洞百出啊