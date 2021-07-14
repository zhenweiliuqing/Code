#include <vector>

// 把行和列不为1的给排除掉
int numSpecial(vector<vector<int>>& mat) {
    int rows = mat.length();
    int cols = mat[0].length();
    vector<int> row_idx, col_idx;
    int sum = 0;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++)
            sum += mat[i][j];
        if (sum == 1)
            row_idx.push_back(i);
        sum = 0;
    }

    sum = 0;
    for (int i = 0; i < cols; i++) {
        for (int j = 0; j < rows; j++)
            sum += mat[j][i];
        if (sum == 1)
            col_idx.push_back(i);
        sum = 0;
    }

    int cnt = 0;
    for (int i = 0; i < row_idx.size(); i++) {
        for (int j = 0; j < col_idx.size(); j++) {
            if (mat[row_idx[i]][col_idx[j]] == 1)
                cnt++;
        }
    }
    return cnt;
}
// 通过 主要是算出和为1的行和列 记下idx 然后判断两个idx交点是否为1 感觉还是不够简洁

// 大佬的解法
int numSpecial_master(vector<vector<int>>& a) {
    int n = a.size(), m = a[0].size();
    int ans = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == 0)
                continue;
            int sum = 0;
            for (int k = 0; k < n; k++) // 第j列
                sum += a[k][j];
            for (int k = 0; k < m; k++) // 第i行
                sum += a[i][k];
            if (sum == 2)
                ans++;
        }
    }
    return ans;
}
// 计算第i行 第j列之和竟然不会？？