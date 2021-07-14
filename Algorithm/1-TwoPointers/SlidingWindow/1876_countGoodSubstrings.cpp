#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <unordered_set>
#include <vector>
using namespace std;

// 5-31
// 这个其实很简单 想复杂了
class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int left = 0, right = 0;
        unordered_map<char, int> mmap;
        int ans = 0;
        while (right < n) {
            char c = s[right];
            mmap[c]++;
            right++;
            if (right - left == 3) {
                if (mmap[s[left]] == 1 && mmap[s[left + 1]] == 1 && mmap[s[left + 2]] == 1)
                    ans++;
                mmap[s[left]]--;
                left++;
            }
        }
        return ans;
    }
};
// 通过

class Solution {
public:
    int countGoodSubstrings(string s) {
        int n = s.size();
        int ans = 0;
        for(int i = 0; i + 3 <= n; i++) {
            if(s[i] != s[i + 1] && s[i + 1] != s[i + 2] && s[i + 2] != s[i]) {
                ans++;
            }
        }
        return ans;
    }
};
