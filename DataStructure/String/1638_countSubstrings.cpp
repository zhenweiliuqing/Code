#include <string>
#include <unordered_map>
using namespace std;

// 6-15
// 暴力枚举 怎么实现
class Solution {
public:
    int ans = 0;
    bool isValid(string s, string t) {
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == t[i])
                continue;
            cnt++;
        }
        return cnt == 1;
    }

    int countSubstrings(string s, string t) {
        int n1 = s.size(), n2 = t.size();
        int minlen = min(n1, n2);
        for (int len = 1; len <= minlen; len++) {
            for (int i = 0; i + len <= n1; i++) {
                string ss = s.substr(i, len);
                for (int j = 0; j + len <= n2; j++) {
                    string tt = t.substr(j, len);
                    if (isValid(ss, tt))
                        ans++;
                }
            }
        }
        return ans;
    }
};
// 通过了
int main() {
    Solution sol;
    sol.countSubstrings("aba", "baba");
}