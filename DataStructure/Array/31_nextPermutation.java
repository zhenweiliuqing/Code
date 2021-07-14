// 一遍扫描
public class Answer {
    public void nextPermutation(int[] nums) {
        int i = nums.length - 2;
        while (i >= 0 && nums[i + 1] <= nums[i]) // 找到第一个下降的位置
            i--;
        if (i >= 0) {
            int j = nums.length - 1;
            while (j >= 0 && nums[j] <= nums[i])
                j--;
            swap(nums, i, j);
        }
        reverse(nums, i + 1);
    }

    private void reverse(int[] nums, int start) {
        int i = start, j = nums.length - 1;
        while (i < j) {
            swap(nums, i, j);
            i++;
            j--;
        }
    }

    private void swap(int[] nums, int i, int j) {
        int temp = nums[i];
        nums[i] = nums[j];
        nums[j] = temp;
    }
}

class Solution {
    public void nextPermutation(int[] nums) {
        int n = nums.length;

        int peek = 0;
        for (int i = n - 2; i >= 0; i--) {
            if (nums[i] < nums[i + 1]) {
                peek = i + 1;
                break;
            }
        }
        if (peek == 0) {
            reverse(nums, peek, n - 1);
            return;
        }
        int cur = peek - 1, next = 0;
        for (int i = n - 1; i >= peek; i--) {
            if (nums[i] > nums[cur]) {
                next = i;
                break;
            }
        }
        swap(nums, cur, next);
        reverse(nums, peek, n - 1);
    }

    public void reverse(int[] nums, int peek, int end) {
        while (peek < end) {
            swap(nums, peek, end);
            peek++;
            end--;
        }
    }
    public void swap(int[] nums, int cur, int next) {
        int temp = nums[cur];
        nums[cur] = nums[next];
        nums[next] = temp;
    }
}
// 通过了