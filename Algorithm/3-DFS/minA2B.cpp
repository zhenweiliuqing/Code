// 3-29
// 在牛客上看了一道题 求A-B最短路径 用非递归方式

#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> matrix = {
    {0, 0, 1, 0, 0},
    {0, 0, 0, 1, 1},
    {1, 0, 0, 0, 0},
    {0, 1, 0, 0, 1},
    {0, 1, 0, 1, 0}};

int ans = INT_MAX;
void dfs(int start, int end, vector<int>& path, vector<bool>& isVisted) {
    if (start == end) {
        if (path.size() < ans)
            ans = path.size();
        return;
    }
    for (int i = 0; i < matrix.size(); i++) {
        if (matrix[start][i] == 0 || isVisted[i])
            continue;
        isVisted[i] = true;
        path.push_back(i);
        dfs(i, end, path, isVisted);
        path.pop_back();
        isVisted[i] = false;
    }
}

// 转化成栈


int main() {
    int n = matrix.size();
    int start = 2, end = 3;
    vector<int> path;
    vector<bool> isVisted(n);
    path.push_back(start);
    isVisted[start] = true;
    dfs(start, end, path, isVisted);
    return ans;
}