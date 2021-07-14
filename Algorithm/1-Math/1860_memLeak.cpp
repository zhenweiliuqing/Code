#include <vector>
using namespace std;

// 5-26
class Solution {
public:
    vector<int> memLeak(int memory1, int memory2) {
        int crashTime = 1, m1crash = memory1, m2crash = memory2;
        while (m1crash >= crashTime || m2crash >= crashTime) {
            if (m1crash >= crashTime && m1crash >= m2crash) {
                m1crash -= crashTime;
            } else if (m2crash >= crashTime) {
                m2crash -= crashTime;
            }
            crashTime++;
        }
        return {crashTime, m1crash, m2crash};
    }
};
// 通过了