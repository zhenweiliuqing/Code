#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 5-9 这个简洁
class Solution {
public:
    bool isValid(const vector<int>& bloomDay, int day, int m, int k) {
        int ans = 0, cnt = 0;
        // 这个求最长连续1 也是可以的 不用判断nums[i] == nums[i-1] 用这个多好
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day) {
                cnt++;
                if (cnt == k) {
                    ans++;
                    cnt = 0;
                }
            } else {
                cnt = 0;
            }
        }
        return ans >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n)
            return -1;
        // 这里也可不排序 找到bloomDay最大值 最小值会更快 logn 也就是一下的事
        vector<int> sorted(bloomDay);
        sort(sorted.begin(), sorted.end());

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(bloomDay, sorted[mid], m, k))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return sorted[left];
    }
};
// 快了一点点

class Solution {
public:
    void bloom(const vector<int>& bloomDay, int day, vector<bool>& isVisited) {
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] <= day)
                isVisited[i] = true;
            else 
                isVisited[i] = false;
        }
    }
    bool isValid(const vector<bool>& isVisited, int m, int k) {
        int ans = 0;
        int n = isVisited.size();
        for (int i = 0; i < n; i++) {
            if (!isVisited[i])
                continue;
            int j = i;
            for (j = i; j < i + k && j < n; j++) {
                if (!isVisited[j])
                    break;
            }
            if (j == i + k)
                ans++;
            i = j - 1;
        }
        return ans >= m;
    }

    // 主函数用下二分
    int minDays(vector<int>& bloomDay, int m, int k) {
        int n = bloomDay.size();
        if (m * k > n)
            return -1;
        vector<int> bloomDaySorted(bloomDay);
        sort(bloomDaySorted.begin(), bloomDaySorted.end());
        vector<bool> isVisited(n);

        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            bloom(bloomDay, bloomDaySorted[mid], isVisited);
            if (isValid(isVisited, m, k))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return bloomDaySorted[left];
    }
};
// 通过了

class Solution1 {
public:
    // 暴力解法 就是看看哪一天的花盛开的情况 判断一下是否符合要求 从第一天开始一直到最大那天
    // 把花开的天数都统计出来
    void bloom(const vector<int>& bloomDay, int day, vector<bool>& isVisited) {
        for (int i = 0; i < bloomDay.size(); i++) {
            if (bloomDay[i] == day)
                isVisited[i] = true;
        }
    }

    // 这个可以改进求一下最长连续1的个数 跟我那天做的阿里笔试题一样 
    // 经过了一些改动之后 能不能用之前统计好的信息
    bool isValid(const vector<bool>& isVisited, int m, int k) {
        int ans = 0;
        int n = isVisited.size();
        for (int i = 0; i < n; i++) {
            if (!isVisited[i])
                continue;
            int j = i;
            for (j = i; j < i + k && j < n; j++) {
                if (!isVisited[j])
                    break;
            }
            if (j == i + k)
                ans++;
            i = j - 1;
        }
        return ans >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {
        vector<int> bloomDaySorted(bloomDay);
        sort(bloomDaySorted.begin(), bloomDaySorted.end());
        int n = bloomDay.size();
        vector<bool> isVisited(n);
        for (int i = 0; i < bloomDaySorted.size(); i++) {
            if (i != 0 && bloomDaySorted[i] == bloomDaySorted[i - 1])
                continue;
            bloom(bloomDay, bloomDaySorted[i], isVisited);
            if (isValid(isVisited, m, k))
                return bloomDaySorted[i];
        }
        return -1;
    }
};
// 超出时间限制 83/91

int main() {
    Solution sol;
    vector<int> v = {59, 81, 16, 41, 42, 34, 18, 65, 31, 70, 22, 76, 14, 95, 88, 75, 9, 93, 71, 19, 86, 31, 56, 12, 4, 55, 58, 72, 82, 12, 29, 65, 25, 24, 24, 87, 5, 17, 29, 51, 93, 9, 23, 44, 80, 4, 61, 21, 77, 82, 28, 89, 81, 18, 79, 9, 58, 69, 33, 36, 11, 9, 54, 14};
    sol.minDays(v, 10, 6);
    return 0;
}