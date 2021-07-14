// 4-5
class Solution {
public:
//     int binarySearch(vector<int> nums, int start, int end, int target) {
//         int left = start;
//         int right = end;
//         while (left <= right) {
//             int mid = left + ((right - left) >> 1);
//             if (nums[mid] == target)
//                 left = mid + 1;
//             else if (nums[mid] > target)
//                 right = mid - 1;
//             else if (nums[mid] < target)
//                 left = mid + 1;
//         }
//         return right > start ? right : start;
//     }
    
//     int purchasePlans(vector<int>& nums, int target) {
//         sort(nums.begin(), nums.end());
//         long long ans = 0;
        
//         for (int i = 0; i < nums.size(); i++) {
//             if (nums[i] > (target + 1) / 2)
//                 break;
//             int idx = binarySearch(nums, i, nums.size() - 1, target - nums[i]);
//             ans = (ans + idx - i) % 1000000007;
//         }
//         return ans;
//     }
//     int dp[100001];
//     int purchasePlans(vector<int>& nums, int target) {
//         // sort(nums.begin(), nums.end());
//         long long ans = 0;
//         for (int i = 0; i < nums.size(); i++)
//             dp[nums[i]]++;
//         for (int i = 1; i <= 100000; i++) {
//             dp[i] += dp[i - 1];
//         }
//         for (int i = 0; i < nums.size(); i++) {
//             if (target - nums[i] >= 0)
//                 ans  = (ans + dp[target - nums[i]] - 1) % 1000000007;
//         }
//         return ans;
//     }
    int purchasePlans(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int left = 0, right = nums.size() - 1;
        long ans = 0;
        while (left <= right) {
            int sum = nums[left] + nums[right];
            if (sum <= target) {
                ans += right - left;
                left++;
            } else {
                right--;
            }
        }
        return ans % 1000000007;
    }
    // 通过
};