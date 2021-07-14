#include <vector>
using namespace std;

// 5-12
// 暴力解法 
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto q : queries) {
            int tmp = 0;
            for (int i = q[0]; i <= q[1]; i++)
                tmp ^= arr[i];
            ans.push_back(tmp);
        }
        return ans;
    }
};

// 可以利用前缀和
class Solution {
public:
    vector<int> xorQueries(vector<int>& arr, vector<vector<int>>& queries) {
        vector<int> pre(arr);
        for (int i = 1; i < pre.size(); i++)
            pre[i] ^= pre[i - 1];
        vector<int> ans;
        for (auto q : queries) {
            int a = q[0] - 1 >= 0 ? pre[q[0] - 1] : 0;
            int b = pre[q[1]];
            ans.push_back(a ^ b);
        }
        return ans;
    }
};
// 通过