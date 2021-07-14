// 1-8
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    // 用vector应该也行
    vector<pair<int, int>> order = {{0, 1}, {1, 0}, {-1, 0}, {0, -1}};
    bool backtrack(vector<vector<char>>& board, string word, int index, vector<vector<bool>> used, int i, int j) {

        for (int k = 0; k < 4; k++) {
            if (i + order[k].first < 0 || i + order[k].first >= board.size() || j + order[k].second < 0 || j + order[k].second >= board[0].size())
                continue;
            if (used[i + order[k].first][j + order[k].second])
                continue;
            if (word[index] != board[i + order[k].first][j + order[k].second])
                continue;
            
            if (word.size() == index + 1)
                return true;
            used[i + order[k].first][j + order[k].second] = true;
            if (backtrack(board, word, index + 1, used, i + order[k].first, j + order[k].second))
                return true;
            used[i + order[k].first][j + order[k].second] = false;
        }
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> used(board.size(), vector<bool>(board[0].size()));
        for (int i = 0; i < board.size(); i++) {
            for (int j = 0; j < board[0].size(); j++) {
                if (board[i][j] != word[0])
                    continue;
                used[i][j] = true;
                if (word.size() == 1)
                    return true;
                if (backtrack(board, word, 1, used, i, j))
                    return true;
                used[i][j] = false;
            }
        }
        return false;
    }
};
// 通过了 不过时间是1176ms

int main() {
    Solution sol;
    // vector<vector<char>> v = {{'F', 'Y', 'C'}};
    // vector<vector<char>> v = {{'F','Y','C','E','N','R','D'},
    //                           {'K','L','N','F','I','N','U'},
    //                           {'A','A','A','R','A','H','R'},
    //                           {'N','D','K','L','P','N','E'},
    //                           {'A','L','A','N','S','A','P'},
    //                           {'O','O','G','O','T','P','N'},
    //                           {'H','P','O','L','A','N','O'}};
    // string word = 'POLAND';

    vector<vector<char>> v = {{'A', 'B', 'C', 'E'}, 
                              {'S', 'F', 'C', 'S'}, 
                              {'A', 'D', 'E', 'E'}};
    string word = "ABCCED";
    sol.exist(v, word);
}


class Solution {
public:
    bool check(vector<vector<char>>& board, vector<vector<int>>& visited, int i, int j, string& s, int k) {
        if (board[i][j] != s[k]) {
            return false;
        } else if (k == s.length() - 1) {
            return true;
        }
        visited[i][j] = true;
        vector<pair<int, int>> directions{{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
        bool result = false;
        for (const auto& dir: directions) {
            int newi = i + dir.first, newj = j + dir.second;
            if (newi >= 0 && newi < board.size() && newj >= 0 && newj < board[0].size()) {
                if (!visited[newi][newj]) {
                    bool flag = check(board, visited, newi, newj, s, k + 1);
                    if (flag) {
                        result = true;
                        break;
                    }
                }
            }
        }
        visited[i][j] = false;
        return result;
    }

    bool exist(vector<vector<char>>& board, string word) {
        int h = board.size(), w = board[0].size();
        vector<vector<int>> visited(h, vector<int>(w));
        for (int i = 0; i < h; i++) {
            for (int j = 0; j < w; j++) {
                bool flag = check(board, visited, i, j, word, 0);
                if (flag) {
                    return true;
                }
            }
        }
        return false;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/word-search/solution/dan-ci-sou-suo-by-leetcode-solution/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
