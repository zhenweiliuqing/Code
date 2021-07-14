#include <string>
#include <stack>
using namespace std;

// 6-24
class Solution {
public:
    string simplifyPath(string path) {
        stack<string> stk;
        string tmp;
        path += '/';
        for (int i = 0; i < path.size() - 1; ++i) {
            if (path[i] == '/')
                continue;
            tmp += path[i];
            if (path[i + 1] == '/') {
                if (!stk.empty() && tmp == "..")
                    stk.pop();
                else if (tmp != "." && tmp != "..")
                    stk.push(tmp);
                tmp = "";
            }
        }
        if (stk.empty())
            return "/";
        string ans;
        while (!stk.empty()) {
            ans = "/" + stk.top() + ans;
            stk.pop();
        }
        return ans;
    }
};
// 通过了
