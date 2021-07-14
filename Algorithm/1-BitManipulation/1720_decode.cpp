#include <iostream>
#include <vector>
using namespace std;

// 5-6
// 异或 ^ 三者之间可以互相转化
class Solution {
public:
    vector<int> decode(vector<int>& encoded, int first) {
        int n = encoded.size();
        vector<int> ans(n + 1);
        ans[0] = first;
        for (int i = 0; i < n; i++) {
            ans[i + 1] = encoded[i] ^ ans[i]; 
        }
        return ans;
    }
};
// 通过
