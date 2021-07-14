// 3-29
#include <iostream>
#include <vector>
using namespace std;

// 和岛屿数量是一样的  有一点像回溯
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j, vector<vector<bool>>& isVisted) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.' || isVisted[i][j])
            return;
        isVisted[i][j] = true;
        dfs(board, i + 1, j, isVisted);
        dfs(board, i - 1, j, isVisted);
        dfs(board, i, j + 1, isVisted);
        dfs(board, i, j - 1, isVisted);
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        vector<vector<bool>> isVisted(m, vector<bool>(n));
        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.' || isVisted[i][j])
                    continue;
                num++;
                dfs(board, i, j, isVisted);
            }
        }
        return num;
    }
};

// 直接用200的解法没问题
class Solution {
public:
    void dfs(vector<vector<char>>& board, int i, int j) {
        if (i < 0 || j < 0 || i >= board.size() || j >= board[0].size() || board[i][j] == '.')
            return;
        board[i][j] = '.';
        dfs(board, i + 1, j);
        dfs(board, i - 1, j);
        dfs(board, i, j + 1);
        dfs(board, i, j - 1);
    }

    int countBattleships(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();
        int num = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == '.')
                    continue;
                num++;
                dfs(board, i, j);
            }
        }
        return num;
    }
};

// 理解题意后 还有个很好的方法
// 战舰只能横着或竖着放置 来查找一下战舰头 战舰头的左侧或上侧一定是.


