#include <vector>
#include <unordered_map>
using namespace std;

// 6-17
class Solution {
public:
    bool makeEqual(vector<string>& words) {
        int n = words.size();
        unordered_map<char, int> mmap;
        for (string s : words) {
            for (char c : s) {
                mmap[c]++;
            }
        }
        for (auto it : mmap) {
            if (it.second % n != 0)
                return false;
        }
        return true;
    }
};
