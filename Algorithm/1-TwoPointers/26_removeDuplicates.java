package LeetCode.Array;

// 这用个双指针 把后边的往前移动
class Solution {
    public int removeDuplicates(int[] nums) {
        int i = 0, j = 0;
        for (j = 1; j < nums.length; j++) {
            if (nums[j] != nums[j - 1]) {
                i++;
                nums[i] = nums[j];
            }
        }
        return i + 1;
    }
}
// 通过了 1ms