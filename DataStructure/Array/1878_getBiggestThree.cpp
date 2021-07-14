#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <set>
#include <vector>
using namespace std;

// set 直接就是没有重复的 排完序的 就不用vector再排序 再去重了
class Solution {
public:
    vector<int> getRec(vector<vector<int>>& grid, int m, int n, int k) {
        vector<int> ans;
        vector<pair<int, int>> d;
        d.insert(d.end(), {{0, k}, {0, -k}, {k, 0}, {-k, 0}});
        for (int i = 1; i < k; i++) {
                d.insert(d.end(), {{i, k - i}, {i, -(k - i)}, {-i, k - i}, {-i, -(k - i)}});
        }
        for (int i = k; i + k < m; i++) {
            for (int j = k; j + k < n; j++) {
                if (k == 0)
                    ans.push_back(grid[i][j]);
                else {
                    int tmp = 0;
                    for (auto it : d)
                        tmp += grid[i + it.first][j + it.second];
                    ans.push_back(tmp);
                }
            }
        }
        return ans;
    }
    vector<int> getBiggestThree(vector<vector<int>>& grid) {
        vector<int> ans;
        int m = grid.size(), n = grid[0].size();
        int len = (min(m, n) + 1) / 2;
        for (int i = 0; i < len; i++) {
            vector<int> tmp = getRec(grid, m, n, i);
            ans.insert(ans.begin(), tmp.begin(), tmp.end());
        }
        sort(ans.begin(), ans.end(), greater<int>());
        vector<int> v;
        for (int i = 0; i < ans.size(); i++) {
            if (i != 0 && ans[i] == ans[i - 1])
                continue;
            v.push_back(ans[i]);
            if (v.size() == 3)
                break;
        }
        return v;
    }
};
// 通过了 感觉可以考虑一下 堆 官方题解就是暴力枚举

int main() {
    Solution sol;
    vector<vector<int>> v = {{3, 4, 5, 1, 3}, {3, 3, 4, 2, 3}, {20, 30, 200, 40, 10}, {1, 5, 5, 4, 1}, {4, 3, 2, 2, 5}};
    sol.getBiggestThree(v);
}


// 这还用前缀和呢
const int N = 110;
int s1[N][N], s2[N][N];
class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& g) {
        memset(s1, 0, sizeof s1);
        memset(s2, 0, sizeof s2);
        int n = g.size(), m = g[0].size();
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                s1[i][j] = s1[i - 1][j - 1] + g[i - 1][j - 1];
                s2[i][j] = s2[i - 1][j + 1] + g[i - 1][j - 1];
            }
        
        set<int> S;
        for (int i = 1; i <= n; i ++ )
            for (int j = 1; j <= m; j ++ ) {
                S.insert(g[i - 1][j - 1]);
                for (int k = 1; i - k >= 1 && i + k <= n && j - k >= 1 && j + k <= m; k ++ ) {
                    int a = s2[i][j - k] - s2[i - k][j];
                    int b = s1[i - 1][j + k - 1] - s1[i - k - 1][j - 1];
                    int c = s2[i + k - 1][j + 1] - s2[i - 1][j + k + 1];
                    int d = s1[i + k][j] - s1[i][j - k];
                    S.insert(a + b + c + d);
                }
                while (S.size() > 3) S.erase(S.begin());
            }
        return vector<int>(S.rbegin(), S.rend());
    }
};

class Solution {
public:
    vector<int> getBiggestThree(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        set<int> st;
        for(int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                // 边长从1到min(a, b) / 2 
                for(int len = 1; i + len <= n && j + len <= m; len += 2) {
                    int sum = 0;
                    for(int k = 0; k < len / 2; k++) {
                        sum += a[i + len / 2 - k][j + k];
                        sum += a[i + k][j + len / 2 + k];
                        sum += a[i + len / 2 + k][j + len - k - 1];
                        sum += a[i + len - k - 1][j + len / 2 - k];
                    }
                    if(len == 1) sum = a[i][j];
                    st.insert(sum);
                }
            }
        }
        vector<int> vec(st.begin(), st.end());
        vector<int> v = vec.size() >= 3 ? vector<int>(vec.end() - 3, vec.end()) : vec;
        reverse(v.begin(), v.end());
        return v;
    }
};