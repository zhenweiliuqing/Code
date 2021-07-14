#include <vector>
using namespace std;

// 5-11 
// 关键就是求出第一位的值 
// 利用两个信息 一个是1-n求得total 一个是利用encoded求得 除了first的even
class Solution {
public:
    vector<int> decode(vector<int>& encoded) {
        int n = encoded.size();
        int total = 0;
        for (int i = 1; i <= n + 1; i++)
            total ^= i;
        int even = 0;
        for (int i = 1; i < n; i+=2)
            even ^= encoded[i];
        int first = total ^ even;

        vector<int> ans(n + 1);
        ans[0] = first;
        for (int i = 1; i <= n; i++)
            ans[i] = ans[i - 1] ^ encoded[i - 1];
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> v = {3, 1};
    sol.decode(v);
}