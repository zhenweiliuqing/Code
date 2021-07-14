#include <string>
#include <vector>
using namespace std;

class Solution {
public:
    vector<string> ans;
    void backtrack(vector<char>& str, string tmp, vector<bool>& isVisited) {
        if (tmp.size() == str.size()) {
            ans.push_back(tmp);
            return;
        }
        // 1 1 1 2 2 3 4
        for (int i = 0; i < str.size(); i++) {
            if (isVisited[i])
                continue;
            if (i != 0 && str[i] == str[i - 1] && !isVisited[i - 1])
                continue;

            isVisited[i] = true;
            tmp += str[i];
            backtrack(str, tmp, isVisited);
            tmp.pop_back();
            isVisited[i] = false;
        }
    }

    vector<string> permutation(string s) {
        if (s.size() == 0)
            return ans;
        vector<char> str;
        for (int i = 0; i < s.size(); i++)
            str.push_back(s[i]);
        //sort(str.begin(), str.end());

        string tmp;
        vector<bool> isVisited(s.size(), false);
        backtrack(str, tmp, isVisited);
        return ans;
    }
};