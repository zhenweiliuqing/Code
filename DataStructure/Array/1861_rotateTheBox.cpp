#include <vector>
using namespace std;

// 5-26
// 双指针那块跟快速排序很像
class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m = box.size(), n = box[0].size();
        vector<vector<char>> ans(n, vector<char>(m));
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                ans[j][m - i - 1] = box[i][j];
            }
        }
        for (int i = 0; i < m; i++) {
            int start = 0, end = 0;
            for (int j = 0; j < n; j++) {
                if (ans[j][i] == '*')
                    end = j - 1;
                else if (j == n - 1)
                    end = j;
                
                // while (start < end) {
                //     while (start <= end && ans[start][i] == '.')
                //         start++;
                //     while (start <= end && ans[end][i] == '#')
                //         end--;
                //     if (start < end)
                //         swap(ans[start][i], ans[end][i]);
                // }
            
                // 不加 = 也可以
                while (start < end) {
                    while (start < end && ans[start][i] == '.')
                        start++;
                    while (start < end && ans[end][i] == '#')
                        end--;
                    if (start < end)
                        swap(ans[start][i], ans[end][i]);
                }

                if (start > end || (start == end && ans[j][i] == '*')) {
                    start = j + 1;
                    end = start;
                }
            }
        }
        return ans;
    }
};
// 通过了 这个思路有一点乱
