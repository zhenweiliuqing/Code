#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 暴力法求解 O(n2)
class Solution {
public:
    int minSubArrayLen(int s, vector<int>& nums) {
        int n = nums.size(), min = 99999999;
        for (int i = 0; i < n; i++) {
            int sum = 0, cnt = 0;
            for (int j = i; sum < s; j++) {
                sum += nums[j];
                cnt++;
            }
            if (cnt < min)
                min = cnt;
        }
        return min;
    }
};

// 双指针法 已经想到要把start给减掉 但是没想到循环减
class Answer {
public:
    int minSubArrayLen(int s, vector<int> &nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int ans = INT_MAX;
        int start = 0, end = 0;
        int sum = 0;
        while (end < n) {
            sum += nums[end];
            while (sum > s) {
                ans = min(ans, end - start);
                sum -= nums[start];
                start++;
            }
            end++;
        }
        return ans == INT_MAX ? 0 : ans;
    }
};