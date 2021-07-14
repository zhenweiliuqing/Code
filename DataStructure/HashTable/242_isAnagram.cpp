#include <iostream>
#include <unordered_map>
using namespace std;

// 5-12
class Solution {
public:
    bool isAnagram(string s, string t) {
        unordered_map<char, int> ms, mt;
        for (char c : s)
            ms[c]++;
        for (char c : t)
            mt[c]++;
        // 这里是有重载的
        return ms == mt;
    }
};