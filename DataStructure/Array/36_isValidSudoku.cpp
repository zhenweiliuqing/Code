#include <vector>
#include <unordered_set>
using namespace std;

// 6-11
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        // 验证行
        for (int i = 0; i < 9; i++) {
            unordered_set<int> sset;
            for (int j = 0; j < 9; j++) {
                char c = board[i][j];
                if (sset.find(c) == sset.end())
                    sset.insert(c);
                else if (c != '.')
                    return false;
            }
        }
        for (int j = 0; j < 9; j++) {
            unordered_set<int> sset;
            for (int i = 0; i < 9; i++) {
                char c = board[i][j];
                if (sset.find(c) == sset.end())
                    sset.insert(c);
                else if (c != '.')
                    return false;
            }
        }
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                unordered_set<int> sset;
                char c = board[i][j];
                if (sset.find(c) == sset.end())
                    sset.insert(c);
                else if (c != '.')
                    return false;
            }
        }
    }
};