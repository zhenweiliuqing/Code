#include <vector>
#include <algorithm>
using namespace std;

// 6-5
// 这个应该就是个背包问题
// 可以用贪心解决吗?
class Solution {
public:
    int maxIceCream(vector<int>& costs, int coins) {
        sort(costs.begin(), costs.end());
        int ans = 0;
        for (int i : costs) {
            coins -= i;
            if (coins < 0)
                break;
            ans++;
        }
        return ans;
    }
};
// 通过了 看看01背包有什么不同
