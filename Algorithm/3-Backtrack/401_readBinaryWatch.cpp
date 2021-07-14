#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

// 6-21
// 回溯 就是排列组合 这可不像是简单题
// hour 8 4 2 1
// minute 
class Solution {
public:
    vector<int> v = {480, 240, 120, 60, 32, 16, 8, 4, 2, 1};
    int On = 0;
    vector<string> ans;
    void backtrack(int start, int k, int hour, int min) {
        if (k == On) {
            string h = to_string(hour);
            string m = to_string(min);
            if (min < 10)
                m = "0" + m;
            ans.push_back(h + ":" + m);
            return;
        }
        for (int i = start; i < v.size(); i++) {
            if (v[i] >= 60) {
                hour += v[i] / 60;
                if (hour < 12)
                    backtrack(i + 1, k + 1, hour, min);
                hour -= v[i] / 60;
            } else {
                min += v[i];
                if (min < 60)
                    backtrack(i + 1, k + 1, hour, min);
                min -= v[i];
            }
        }
    }
    vector<string> readBinaryWatch(int turnedOn) {
        On = turnedOn;
        backtrack(0, 0, 0, 0);
        return ans;
    }
};
// 通过了

// __builtin_popcount(h) 计算二进制中有多少个1
class Solution {
public:
    vector<string> readBinaryWatch(int turnedOn) {
        vector<string> ans;
        for (int h = 0; h < 12; ++h) {
            for (int m = 0; m < 60; ++m) {
                if (__builtin_popcount(h) + __builtin_popcount(m) == turnedOn) {
                    ans.push_back(to_string(h) + ":" + (m < 10 ? "0" : "") + to_string(m));
                }
            }
        }
        return ans;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/binary-watch/solution/er-jin-zhi-shou-biao-by-leetcode-solutio-3559/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。
