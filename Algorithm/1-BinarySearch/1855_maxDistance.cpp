#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 5-28
class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            for (int j = i; j < n; j++) {
                if (nums1[i] <= nums2[j])
                    ans = max(ans, j - i);
            }
        }
        return ans;
    }
};
// 肯定超时 得用二分 20/32

class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        int ans = 0;
        for (int i = 0; i < m; i++) {
            // 查找第一个小于nums[i]的位置 -1就是最后一个>=的位置
            int j = upper_bound(nums2.begin() + i, nums2.end(), nums1[i], greater<int>()) - nums2.begin();
            ans = max(ans, j - i - 1);
        }
        return ans;
    }
};
// 通过了