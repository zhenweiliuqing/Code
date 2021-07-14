#include <vector>
#include <numeric>
using namespace std;

// 6-23
class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        long sum = accumulate(chalk.begin(), chalk.end(), 0l); // 这里0必须加个l 不能自动转换吗 不能 都是int
        long left = k % sum;
        for (int i = 0; i < chalk.size(); ++i) {
            left -= chalk[i];
            if (left < 0)
                return i;
        }
        return 0;
    }
};
// 通过
