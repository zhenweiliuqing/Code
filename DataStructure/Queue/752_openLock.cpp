#include <vector>
#include <string>
#include <iostream>
#include <queue>
#include <set>
using namespace std;

class Solution {
public:
    string codeplus(string str, int i) {
        str[i] = str[i] == '9' ? '0' : str[i] + 1;
        return str;
    }

    string codeminus(string str, int i) {
        str[i] = str[i] == '0' ? '9' : str[i] - 1;
        return str;
    }

    int openLock(vector<string> &deadends, string target)
    {
        set<string> s;
        for (string it : deadends)
            s.insert(it);
        queue<string> q;
        q.push("0000");
        int step = 0;

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string temp = q.front();
                q.pop();
                if (s.count(temp) != 0)
                    continue;
                if (temp == target)
                    return step;
                s.insert(temp);
                
                for (int j = 0; j < 4; j++) {
                    string tempplus = codeplus(temp, j);
                    if (s.count(tempplus) == 0) {
                        q.push(tempplus);
                    }
                    string tempminus = codeminus(temp, j);
                    if (s.count(tempminus) == 0) {
                        q.push(tempminus);
                    }
                }
            }
            step++;
        }
        return -1;
    }
};
// 终于通过了 
// str[] 里边是ascii值 这个得记住