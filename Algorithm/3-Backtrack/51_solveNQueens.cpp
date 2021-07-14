#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isValid(const vector<string>& temp, int n) {
        // 一行是否有两个Q
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (flag && temp[i][j] == 'Q')
                    flag = false;
                else if (!flag && temp[i][j] == 'Q')
                    return false;
            }
        }

        // 一列是否有两个Q
        for (int i = 0; i < n; i++) {
            bool flag = true;
            for (int j = 0; j < n; j++) {
                if (flag && temp[j][i] == 'Q')
                    flag = false;
                else if (!flag && temp[j][i] == 'Q')
                    return false;
            }
        }

        // 斜着是否有两个Q
        // 左上右下
        for (int i = 0; i < n; i++) {
            int j = 0;
            bool flag = true;
            for (int k = 0; (i + k) < n && (j + k) < n; k++) {
                if (flag && temp[i + k][j + k] == 'Q')
                    flag = false;
                else if (!flag && temp[i + k][j + k] == 'Q')
                    return false;
            }
        }
        for (int i = 0; i < n; i++) {
            int j = 0;
            bool flag = true;
            for (int k = 0; (i + k) < n && (j + k) < n; k++) {
                if (flag && temp[j + k][i + k] == 'Q')
                    flag = false;
                else if (!flag && temp[j + k][i + k] == 'Q')
                    return false;
            }
        }

        // 右上左下
        for (int i = 0; i < n; i++) {
            int j =  n - 1; // 最后一列
            bool flag = true;
            for (int k = 0; (i + k) < n && (j - k) >= 0; k++) {
                if (flag && temp[i + k][j - k] == 'Q')
                    flag = false;
                else if (!flag && temp[i + k][j - k] == 'Q')
                    return false;
            }
        }
        for (int i = 0; i < n; i++) {
            int j =  0; // 第一行
            bool flag = true;
            for (int k = 0; (j + k) < n && (i - k) >= 0; k++) {
                if (flag && temp[j + k][i - k] == 'Q')
                    flag = false;
                else if (!flag && temp[j + k][i - k] == 'Q')
                    return false;
            }
        }
        return true;
    }
    void backtrack(vector<vector<string>>& ans, vector<string>& temp, int n, int i) {
        if (i == n && isValid(temp, n)) {
            ans.push_back(temp);
            return;
        }
        // i代表每一行 每一列的选择 从0开始
        for (int j = 0; j < n; j++) {
            if (!isValid(temp, n))
                continue;
            temp[i][j] = 'Q';
            backtrack(ans, temp, n, i + 1);
            temp[i][j] = '.';
        }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        // vector<string> temp(n);
        // for (int i = 0; i < n; i++) {
        //     //string str(n, '.'); // 这都可以？
        //     //temp[i] = str;
        //     temp[i] = string(n, '.');
        // }
        vector<string> temp(n, string(n, '.')); // 简洁写法
        backtrack(ans, temp, n, 0);
        return ans;
    }
};

// 通过了 这也太强了吧 虽然1096ms


// Fucking Algorithm
class Fucking {
public:
    vector<vector<string>> res;
    vector<vector<string>> solveNQueens(int n) {
        vector<string> board(n, string(n, '.'));
        backtrack(board, 0);
        return res;
    }
    void backtrack(vector<string>& board, int row) {
        if (row == board.size()) {
            res.push_back(board);
            return;
        }

        int n = board[row].size();
        for (int col = 0; col < n; col++) {
            if (!isValid(board, row, col))
                continue;
            board[row][col] = 'Q';
            backtrack(board, row + 1);
            board[row][col] = '.';
        }
    }
    bool isValid(vector<string>& board, int row, int col) {
        int n = board.size();
        for (int i = 0; i < n; i++) {
            if (board[i][col] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col + 1; i >= 0 && j < n; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        for (int i = row - 1, j = col - 1; i >= 0 && j >= 0; i--, j++) {
            if (board[i][j] == 'Q')
                return false;
        }
        return true;
    }
};