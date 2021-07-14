#include <iostream>
#include <vector>
using namespace std;

// 6-3
class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> z(numRows);
        int n = s.size();
        if(n == 1 || numRows == 1)
            return s;
        int i = 0, row = 0, col = 0;
        while (i < n) {
            while (row < numRows && i < n) {
                z[row].push_back(s[i]);
                row++, i++;
            }
            col++;
            row--;
            while (row >= 0) {
                z[row].insert(z[row].end(), numRows - 2, ' ');
                row--;
            }
            row++;
            for (int j = numRows - 2; j >= 1 && i < n; j--) {
                z[j][col] = s[i];
                i++;
                col++;
            }
        }
        string ans;
        for (auto t : z) {
            for (auto c : t) {
                if (c == ' ')
                    continue;
                ans.push_back(c);
            }
        }
        return ans;
    }
};
// 通过了

int main() {
    Solution sol;
    sol.convert("A", 1);
}