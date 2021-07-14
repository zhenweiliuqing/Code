#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 6-10
// 先排个序
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const int mod = 1e9 + 7;
        sort(packages.begin(), packages.end());
        // 不是对供应商排序 而是对供应商内部的箱子排序
        for (auto& it : boxes)
            sort(it.begin(), it.end());
        int ans = INT_MAX;
        for (auto box : boxes) {
            int sum = 0, idx = 0;
            for (int i = 0; i < packages.size(); i++) {
                while (idx < box.size() && packages[i] > box[idx])
                    idx++;
                if (idx == box.size()) {
                    sum = INT_MAX;
                    break;
                }
                sum += (box[idx] - packages[i]);
            }
            ans = min(ans, sum);
        }
        return ans == INT_MAX ? -1 : ans % mod;
    }
};
// 超出时间限制 35/42

class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const int mod = 1e9 + 7;
        sort(packages.begin(), packages.end());
        // 不是对供应商排序 而是对供应商内部的箱子排序
        for (auto& it : boxes)
            sort(it.begin(), it.end());
        int ans = INT_MAX;
        for (auto box : boxes) {
            int sum = 0, idx = 0;
            for (int i = 0; i < packages.size(); i++) {
                // 这里可以直接用二分法查找合适的箱子
                if (packages[i] > box[idx])
                    idx = lower_bound(box.begin(), box.end(), packages[i]) - box.begin();
                if (idx == box.size()) {
                    sum = INT_MAX;
                    break;
                }
                sum += (box[idx] - packages[i]);
            }
            ans = min(ans, sum);
        }
        return ans == INT_MAX ? -1 : ans % mod;
    }
}; 
// 超出时间限制 35/42 还是超出时间限制

// 逆向思维 我是遍历每一个包裹选一个合适的箱子 
// 另一种思路是遍历每一个箱子并匹配包裹 用二分查找查到能装入箱子的最大包裹的位置 这就是需要用这么多的箱子 然后把包裹移出去
// 这样就快了吗? 假如包裹和箱子一样多 
class Solution {
public:
    int minWastedSpace(vector<int>& packages, vector<vector<int>>& boxes) {
        const int mod = 1e9 + 7;
        long packageSum = accumulate(packages.begin(), packages.end(), 0l);
        sort(packages.begin(), packages.end());
        // 不是对供应商排序 而是对供应商内部的箱子排序
        for (auto& it : boxes)
            sort(it.begin(), it.end());
        long ans = LONG_MAX;
        for (auto box : boxes) {
            long sum = 0, idx = 0, start = 0;
            for (int i = 0; i < box.size(); i++) {
                idx = upper_bound(packages.begin() + start, packages.end(), box[i]) - packages.begin();
                sum += (idx - start) * long(box[i]);
                start = idx;
                if (start == packages.size())
                    break;
            }
            sum -= packageSum;
            if (start != packages.size())
                sum = LONG_MAX;
            ans = min(ans, sum);
        }
        return ans == LONG_MAX ? -1 : ans % mod;
    }
}; 
// 通过了 这为什么快呢?