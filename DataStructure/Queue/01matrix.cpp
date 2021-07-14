// 这个是把0作为起始点 然后进行广度优先搜索
// 思路： 把原先矩阵中的0设为0 然后对其他位置的元素进行广度优先搜索 
// 但是感觉要对每一个元素都作为起点 开始广搜一遍 进行修正 计算量有点大啊
// 还有一种思路就是对剩余的每一个元素向外搜索 就上下左右开始搜 搜到0为止

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
private:
    static constexpr int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> dist(m, vector<int>(n)); // 最后的结果
        vector<vector<int>> seen(m, vector<int>(n)); // 记录已经看过的
        queue<pair<int, int>> q;

        // 将所有的0添加到初始队列中
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    q.emplace(i, j);
                    seen[i][j] = 1;
                }
            }
        }

        while(!q.empty()) {
            auto [i, j] = q.front();
            q.pop();
            for (int d = 0; d < 4; d++) {
                int ni = i + dirs[d][0];
                int nj = j + dirs[d][1];
                if (ni >= 0 && ni < m && nj >= 0 && nj < n && !seen[ni][nj]) { // 不超过边界且没有看过
                    dist[ni][nj] = dist[i][j] + 1;
                    q.emplace(ni, nj);
                    seen[ni][nj] = 1;
                }
            }
        }
        return dist;
    }
};

// 竟然犯了越界的错误 之前就有一次 也是在m n边界上
class Solution {
private:
    int inf = 9999;
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        vector<vector<int>> res(m, vector<int>(n, inf));
        queue<pair<int, int>> q;
                
        // 把所有的0 push进队列里
        for (int i = 0; i < m; i++) { // 这就没必要进行循环了 用queue可以遍历
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0){
                    q.emplace(i, j); // emplace 和 push 有什么区别？ emplace效率高
                    visited[i][j] = true;
                    res[i][j] = 0;
                }
            }
        }

        while (!q.empty()) {
            // pair<int, int> temp = q.front();
            // int x = temp.first, y = temp.second;
            auto [x, y] = q.front(); // 这个看着6
            q.pop();
            
            // 四个是相对独立的
            if (x - 1 >= 0 && !visited[x - 1][y]) {
                q.emplace(x - 1, y);
                visited[x - 1][y] = true;
                res[x - 1][y] = res[x][y] + 1;
            } 
            if (x + 1 < m && !visited[x + 1][y]) {
                q.emplace(x + 1, y);
                visited[x + 1][y] = true;
                res[x + 1][y] = res[x][y] + 1;
            } 
            if (y - 1 >= 0 && !visited[x][y - 1]) {
                q.emplace(x, y - 1);
                visited[x][y - 1] = true;
                res[x][y - 1] = res[x][y] + 1;
            }
            if (y + 1 < n && !visited[x][y + 1]) {
                q.emplace(x, y + 1);
                visited[x][y + 1] = true;
                res[x][y + 1] = res[x][y] + 1;
            }
        }
        return res;
    }
};
// 终于通过了




int main() {
    vector<vector<int>> matrix;
}