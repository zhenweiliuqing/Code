#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret;
        if (numRows == 0)
            return ret;
        ret.resize(numRows); // 这样也是可以的
        ret[0].resize(1);
        ret[0][0] = 1;
        for (int i = 1; i < numRows; i++) {
            int size = i + 1;
            ret[i].resize(size);
            for (int j = 0; j < size; j++) {
                if (j == 0 || j == size - 1)
                    ret[i][j] = 1;
                else 
                    ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        return ret;
    }
};

// 返回杨辉三角的第k行
class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> ret1(1,1);
        vector<vector<int>> ret;
        if (rowIndex == 0)
            return ret1; // 0的话是返回 [1]
        ret.resize(rowIndex + 1);
        ret[0].resize(1);
        ret[0][0] = 1;
        for (int i = 1; i <= rowIndex; i++) {
            int size = i + 1;
            ret[i].resize(size);
            for (int j = 0; j < size; j++) {
                if (j == 0 || j == size - 1)
                    ret[i][j] = 1;
                else 
                    ret[i][j] = ret[i - 1][j - 1] + ret[i - 1][j];
            }
        }
        return ret[rowIndex];
    }
};
// 通过了 但是不知道这是不是空间复杂度为O(k) 