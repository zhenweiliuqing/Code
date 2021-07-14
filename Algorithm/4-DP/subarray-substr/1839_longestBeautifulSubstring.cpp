#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <iostream>
using namespace std;

// 感觉用滑动窗口好一点
class Solution {
public:
    int longestBeautifulSubstring(string word) {
        word.push_back(' ');
        int n = word.size();
        int right = 0;
        unordered_map<char, pair<char, char>> mmap{{'a', {'a', 'e'}}, {'e', {'e', 'i'}}, {'i', {'i', 'o'}},{'o', {'o', 'u'}}, {'u', {'u', 'u'}}};
        string ans;
        int maxlen = 0;
        for (char a : word) {
            if (ans == "") { 
                if (a == 'a')
                    ans.push_back(a);
                continue;
            } 
            if (a == mmap[ans.back()].first || a == mmap[ans.back()].second) {
                ans.push_back(a);
            } else {
                if (ans.back() == 'u') {
                    // int x = ans.size();
                    // maxlen = max(x, maxlen);
                    maxlen = max(int(ans.size()), maxlen);
                }
                ans = a == 'a' ? "a" : "";
            }
        }
        return maxlen;
    }
};
// 通过了

int main() {
    Solution sol;
    sol.longestBeautifulSubstring("aeiaaioaaaaeiiiiouuuooaauuaeiu");
}