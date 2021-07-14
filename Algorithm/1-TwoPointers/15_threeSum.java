package LeetCode.TwoPointers;

import java.sql.Array;
import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

// 需要利用双指针
class Solution {
    public int[] twoSum(int[] numbers, int target, int start) {
        int left = start, right = numbers.length - 1;
        while (left < right) {
            if (numbers[left] + numbers[right] == target)
                return new int[] { left + 1, right + 1 };
            else if (numbers[left] + numbers[right] > target)
                right--;
            else
                left++;
        }
        return new int[] { -1, -1 };
    }

    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> ans = new ArrayList<>();
        for (int i = 0; i < nums.length; i++) {
            int target = -nums[i];
            int[] tsum = twoSum(nums, target, i + 1);
            if (tsum[0] != -1) {

            }
        }
    }
}
