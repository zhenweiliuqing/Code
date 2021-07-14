#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

// 6-27
class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        unordered_set<string> sset;
        unordered_map<string, int> mmap;
        for (int i = 0; i + 9 < s.size(); ++i) {
            string tmp = s.substr(i, 10);
            mmap[tmp]++;
            if (mmap[tmp] > 1)
                sset.insert(tmp);
        }
        return vector<string>(sset.begin(), sset.end());
    }
};
// 通过了