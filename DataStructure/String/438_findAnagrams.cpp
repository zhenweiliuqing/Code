#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> ans;
        unordered_map<char, int> target, win;
        for (int i = 0; i < p.size(); i++)
            target[p[i]]++;

        int left = 0, right = 0, valid = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            if (target.count(c) != 0) {
                win[c]++;
                if (win[c] == target[c])
                    valid++;
            }

            if ((right - left) == p.size()) {
                if (valid == target.size())
                    ans.push_back(left);

                char c = s[left];
                left++;
                if (target.count(c) != 0) {
                    if (win[c] == target[c])
                        valid--;
                    win[c]--;
                }
            }
        }
        return ans;
    }
};
// 这就是框架的力量