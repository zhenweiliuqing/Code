#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 5-30
// nextPermutation + 贪心
class Solution {
public:
    int getMinSwaps(string num, int k) {
        string target = num;
        while (k--)
            target = nextPermutation(target);
        int ans = 0, n = num.size();
        for (int i = 0; i < n; i++) {
            if (num[i] != target[i]) {
                // 返回的是迭代器的位置
                int idx = find(num.begin() + i, num.end(), target[i]) - num.begin();
                ans += idx - i;
                // erase 后边跟着一个数字
                num.erase(idx, 1);
                // insert的位置就是现在的位置
                num.insert(num.begin() + i, target[i]);
            }
        }
        return ans;
    }

    string nextPermutation(string num) {
        int left = 0, right = num.size() - 1;
        for (int i = num.size() - 2; i >= 0; i--) {
            if (num[i] < num[i + 1]) {
                left = i;
                break;
            }
        }
        // 找到第一个大于nums[left]的
        for (int i = num.size() - 1; i >= left + 1; i--) {
            if (num[i] > num[left]) {
                right = i;
                break;
            }
        }
        swap(num[left], num[right]);
        reverse(num.begin() + left + 1, num.end());
        return num;
    }
};
// 通过了

int main() {
    Solution sol;
    sol.getMinSwaps("142", 4);
}
