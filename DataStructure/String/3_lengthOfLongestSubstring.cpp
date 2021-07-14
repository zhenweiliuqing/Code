#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.size() == 0)
            return 0;
        int ans = 1;
        unordered_map<char, int> win;

        int left = 0, right = 0;
        while (right < s.size()) {
            char c = s[right];
            right++;
            
            while(win[c] != 0) {
                char d = s[left];
                left++;
                win[d]--;
                if (right - left > ans)
                    ans = right - left;
            }
            win[c]++;
        }
        if (right - left > ans)
            ans = right - left;
        return ans;
    }
};
// 通过了 

// labuladong
int length(string s) {
    unordered_map<char, int> window;

    int left = 0, right = 0;
    int res = 0;
    while (right < s.size()) {
        char c = s[right];
        right++;
        window[c]++;

        while (window[c] > 1) {
            char d = s[left];
            left++;
            window[d]--;
        }
        res = max(res, right - left);
    }
    return res;
}

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if(s.size() == 0) return 0;
        unordered_set<char> lookup;
        int maxStr = 0;
        int left = 0;
        for(int i = 0; i < s.size(); i++){
            while (lookup.find(s[i]) != lookup.end()){
                lookup.erase(s[left]);
                left ++;
            }
            maxStr = max(maxStr,i-left+1);
            lookup.insert(s[i]);
        }
        return maxStr; 
    }
};

