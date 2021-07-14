#include <string>
#include <vector>
using namespace std;

// 6-17
class Solution {
public:
    bool isValid(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        int pi = 0;
        for (int i = 0; i < n1; ++i) {
            if (s[i] == ' ')
                continue;
            if (s[i] == p[pi])
                ++pi;
            if (pi == n2)
                break;
        }
        return pi == n2;
    }
    // 每次折半查找是否合法 但是怎么才能快速得到erase后的结果呢 
    // 之前是每次判断浪费时间了吗 我先试试每次重新置空这个是否浪费时间
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int left = 0, right = removable.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            string tmp = s;
            for (int i = 0; i <= mid; ++i)
                tmp[removable[i]] = ' ';
            if (isValid(tmp, p))
                left = mid + 1;
            else
                right = mid - 1;
        }
        return right + 1;
    }
};
// 通过了

// 6-17
class Solution {
public:
    bool isValid(string s, string p) {
        int n1 = s.size(), n2 = p.size();
        int pi = 0;
        for (int i = 0; i < n1; ++i) {
            if (s[i] == ' ')
                continue;
            if (s[i] == p[pi])
                ++pi;
            if (pi == n2)
                break;
        }
        return pi == n2;
    }
    int maximumRemovals(string s, string p, vector<int>& removable) {
        int ans = 0;
        for (int i : removable) {
            // 不能erase 可以把这个位置换成空
            s[i] = ' ';
            if (!isValid(s, p))
                break;
            ++ans;
        }
        return ans;
    }
};
// 超时了 得用二分搜索



int main() {
    Solution sol;
    sol.maximumRemovals("abcacb", "ab", {3, 1, 0});
}
