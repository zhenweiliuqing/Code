#include <iostream>
using namespace std;

// 7-11
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        for (int i = 0; i < n; ++i) {
            int h = i + 1;
            if (citations[i] >= h)
                ans = h;
            else 
                break;
        }
        return ans;
    }
};
// 通过 
// 3 3 3 3 只需要满足当前这个h 有h篇论文的引用因子是大于等于h的 后边的一定是小于等于h

class Solution {
public:
    // 6 5 3 1 0
    // 3 4 第一个值小于第二个值可以
    // 4 4 4 4 
    int hIndex(vector<int>& citations) {
        int ans = 0;
        sort(citations.begin(), citations.end(), greater<int>());
        int n = citations.size();
        citations.push_back(0);
        for (int i = 0; i < n; ++i) {
            int h = i + 1;
            if (citations[i] >= h && citations[i + 1] <= h)
                ans = max(h, ans);
        }
        return ans;
    }
};
// 通过了 不知道怎么用计数排序

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        int h = 0, i = citations.size() - 1;
        while (i >= 0 && citations[i] > h) {
            h++;
            i--;
        }
        return h;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/h-index/solution/h-zhi-shu-by-leetcode-solution-fnhl/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size(), tot = 0;
        vector<int> counter(n + 1);
        for (int i = 0; i < n; i++) {
            if (citations[i] >= n) {
                counter[n]++;
            } else {
                counter[citations[i]]++;
            }
        }
        for (int i = n; i >= 0; i--) {
            tot += counter[i];
            if (tot >= i) {
                return i;
            }
        }
        return 0;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/h-index/solution/h-zhi-shu-by-leetcode-solution-fnhl/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。