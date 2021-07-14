// 4-12
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> mmap;
        for (int i = 0; i < answers.size(); i++) {
            mmap[answers[i]]++;
        }
        int ans  = 0;
        for (auto it : mmap) {
            int cnt = it.second;
            int group = it.first;
            // 算出来有多少组 每一组加上自己是it.first + 1个小兔几
            ans += (cnt + group) / (group + 1) * (group + 1);
        }
        return ans;
    }
};
// 直接通过