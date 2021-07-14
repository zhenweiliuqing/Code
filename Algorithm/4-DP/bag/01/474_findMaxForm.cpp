#include <vector>
#include <string>
using namespace std;

// 6-11
// 这个类似背包问题 strs就是所有的物品 有两个限制
// m是0的个数限制 n是1的个数限制 求最多放多少个物品
// 状态: dp[i][j][k] 前i个物品中不超过 j个0 k个1的最多物品数
// 转移: dp[i][j][k] = max(dp[i-1][j][k], dp[i-1][j-strs[i-1].zeros][k-strs[i-1].ones] + 1);
class Solution {
public:
    pair<int, int> count01(string s) {
        pair<int, int> t;
        for (char c : s) {
            if (c == '0')
                t.first++;
            else
                t.second++;
        }
        return t;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int num = strs.size();
        vector<pair<int, int>> v(num);
        for (int i = 0; i < num; i++) {
            v[i] = count01(strs[i]);
        }

        vector<vector<vector<int>>> dp(num + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= num; i++) {
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    if (j - v[i - 1].first < 0 || k - v[i - 1].second < 0)
                        dp[i][j][k] = dp[i - 1][j][k];
                    else 
                        dp[i][j][k] = max(dp[i - 1][j][k], dp[i - 1][j - v[i - 1].first][k - v[i - 1].second] + 1);
                }
            }
        }
        return dp[num][m][n];
    }
};
// 通过了 j k都得从0开始 你说神不神奇
// 这个为什么和879


// 脑子很混乱 看看答案
// 背包问题 两种容量 
// 状态 dp[i][j][k] 在前i个字符串中 用j个0和k个1最多得到的字符串数量
class Solution {
public:
    vector<int> getZerosOnes(string& str) {
        vector<int> zerosOnes(2);
        int length = str.length();
        for (int i = 0; i < length; i++) {
            zerosOnes[str[i] - '0']++;
        }
        return zerosOnes;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        int length = strs.size();
        vector<vector<vector<int>>> dp(length + 1, vector<vector<int>>(m + 1, vector<int>(n + 1)));
        for (int i = 1; i <= length; i++) {
            // && 右值引用
            // 直接使用临时对象已经申请的资源，既能节省资源，又能节省资源申请和释放的时间。
            // 返回非引用类型的函数生成右值
            vector<int>&& zerosOnes = getZerosOnes(strs[i - 1]);
            int zeros = zerosOnes[0], ones = zerosOnes[1];
            for (int j = 0; j <= m; j++) {
                for (int k = 0; k <= n; k++) {
                    dp[i][j][k] = dp[i - 1][j][k];
                    if (j >= zeros && k >= ones) {
                        dp[i][j][k] = max(dp[i][j][k], dp[i - 1][j - zeros][k - ones] + 1);
                    }
                }
            }
        }
        return dp[length][m][n];
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/ones-and-zeroes/solution/yi-he-ling-by-leetcode-solution-u2z2/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。


// 6-6
// m个0 n个1
// 一下子不知道怎么弄状态和转移
// 通过子集想到了回溯 for循环 + 递归
// for就是遍历整个数组 递归就是从数组的下一个位置开始
class Solution {
public:
    int ans = 0;
    void backtrack(vector<pair<int, int>>& v, int m, int n, int tmp0, int tmp1, int start, int cnt) {
        if (tmp0 > m || tmp1 > n) {
            ans = max(ans, cnt - 1);
            return;
        }
        if (start == v.size()) {
            ans = max(ans, cnt);
            return;
        }

        for (int i = start; i < v.size(); i++) {
            tmp0 += v[i].first;
            tmp1 += v[i].second;
            cnt++;
            backtrack(v, m, n, tmp0, tmp1, i + 1, cnt);
            tmp0 -= v[i].first;
            tmp1 -= v[i].second;
            cnt--;
        }
    }

    pair<int, int> count01(string s) {
        pair<int, int> t;
        for (char c : s) {
            if (c == '0')
                t.first++;
            else
                t.second++;
        }
        return t;
    }

    int findMaxForm(vector<string>& strs, int m, int n) {
        vector<pair<int, int>> v;
        for (auto s : strs) {
            v.emplace_back(count01(s));
        }
        backtrack(v, m, n, 0, 0, 0, 0);
        return ans;
    }
};
// 超出时间限制 22/70
// 用一个memo记录一下 怎么定义状态呢?
// 定义一个范围 [i,j] 固定的m, n 它的最大个数是多少

