#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

// 6-21
// 这个就是求子集 求完之后需要判断一下这个字符串是否重复 
// 判断这个也好弄 总共就26个字母
class Solution {
public:
    int ans = 0;
    bool isValid(vector<string>& vs) {
        unordered_map<char, int> mmap;
        int len = 0;
        for (string s : vs) {
            len += s.size();
            for (char c : s) {
                if (mmap.find(c) != mmap.end())
                    return false;
                mmap[c]++;
            }
        }
        ans = max(ans, len);
        return true;
    }
    int maxLength(vector<string>& arr) {
        vector<vector<string>> subset;
        subset.push_back({""});
        for (string s : arr) {
            int n = subset.size();
            for (int i = 0; i < n; ++i) {
                vector<string> tmp = subset[i];
                tmp.push_back(s);
                if (isValid(tmp))
                    subset.push_back(tmp);
            }
        }
        return ans;
    }
};
// 通过了 但是效率不高啊