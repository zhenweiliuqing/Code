package LeetCode;

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

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] height = { 0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1 };
        solution.trap(height);
    }
}