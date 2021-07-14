#include <string>
#include <vector>
using namespace std;

// 6-14
class Solution {
public:
    int minOperations(vector<string>& logs) {
        string cur = "./", pre = "../";
        int ans = 0;
        for (string s : logs) {
            if (s == cur)
                continue;
            else if (s == pre)
                ans = ans == 0 ? 0 : ans - 1;
            else
                ans++;
        }
        return ans;
    }
};
// 通过