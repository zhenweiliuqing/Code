package LeetCode.Algorithm.1-TwoPointers;

// 12-30

class Solution {
    public int trap(int[] height) {
        int n = height.length;
        if (n == 0)
            return 0;
        int[] lmax = new int[n];
        int[] rmax = new int[n];
        lmax[0] = height[0];
        rmax[n - 1] = height[n - 1];

        for (int i = 1; i < n; i++)
            lmax[i] = Math.max(height[i], lmax[i - 1]);
        for (int i = n - 2; i >= 0; i--)
            rmax[i] = Math.max(height[i], rmax[i + 1]);

        int ans = 0;
        for (int i = 0; i < n; i++) {
            ans += Math.min(lmax[i], rmax[i]) - height[i];
        }
        return ans;
    }
}
// 通过了



class Solution {
    public int trap(int[] height) {
        if (height.length == 0)
            return 0;
        int left = 0;
        int right = height.length - 1;
        int lmax = height[left];
        int rmax = height[right];
        int ans = 0;
        while (left <= right) {
            lmax = Math.max(height[left], lmax);
            rmax = Math.max(height[right], rmax);

            if (lmax < rmax) {
                ans += lmax - height[left];
                left++;
            } else {
                ans += rmax - height[right];
                right--;
            }
        }
        return ans;
    }
}
// 双指针 通过
// 空间复杂度O(1)