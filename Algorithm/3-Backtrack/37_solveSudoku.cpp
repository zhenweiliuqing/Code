// 1-8
#include <iostream>
#include <vector>
using namespace std;

// 4-28
class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[row / 3 * 3 + i][col / 3 * 3 + j] == c)
                    return false;
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;
        if (col == 9)
            return backtrack(board, row + 1, 0);
        // 一大圈循环可以去掉
        if (board[row][col] != '.')
            return backtrack(board, row, col + 1);
        for (char c = '1'; c <= '9'; c++) {
            if (isValid(board, row, col, c)) {
                board[row][col] = c;
                if (backtrack(board, row, col + 1))
                    return true;
                board[row][col] = '.';
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};


class Solution {
public:
    bool isValid(vector<vector<char>>& board, int row, int col, char c) {
        for (int i = 0; i < 9; i++) {
            if (board[row][i] == c)
                return false;
            if (board[i][col] == c)
                return false;
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (board[row / 3 * 3 + i][col / 3 * 3 + j] == c)
                    return false;
            }
        }
        return true;
    }
    bool backtrack(vector<vector<char>>& board, int row, int col) {
        if (row == 9)
            return true;
        if (col == 9)
            return backtrack(board, row + 1, 0);

        for (int i = row; i < 9; i++) {
            for (int j = col; j < 9; j++) {
                // 不明白这里为什么不能continue
                // 假如最后一个位置有数 会return false
                if (board[i][j] != '.')
                    return backtrack(board, i, j + 1);
                for (char c = '1'; c <= '9'; c++) {
                    if (isValid(board, i, j, c)) {
                        board[i][j] = c;
                        if (backtrack(board, i, j + 1))
                            return true;
                        board[i][j] = '.';
                    }
                }
                // 1-9都不合适 所以就是false
                return false; // 不能省略
            }
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        backtrack(board, 0, 0);
    }
};
// 通过了 必须return 不能continue

int main() {
    Solution sol;
    vector<vector<char>> v =
        {{'5', '3', '.', '.', '7', '.', '.', '.', '.'},
         {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
         {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
         {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
         {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
         {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
         {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
         {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
         {'.', '.', '.', '.', '8', '.', '.', '7', '9'}};
    sol.solveSudoku(v);
    return 0;
}