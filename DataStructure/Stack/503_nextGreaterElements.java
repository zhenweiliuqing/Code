package LeetCode.Array;
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

// 循环找最大的
// 正着就是不好弄 最后一个不好处理
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Stack<Integer> s = new Stack<>();
        for (int i = 0; i < 2 * n; i++) {
            while (!s.empty() && nums[i % n] > nums[s.peek()])
                ans[s.pop()] = nums[i % n];
            s.push(i % n);
        }
        while (!s.empty())
            ans[s.pop()] = -1;
        return ans;

    }
}

// 那还是倒着找吧
class Solution {
    public int[] nextGreaterElements(int[] nums) {
        int n = nums.length;
        int[] ans = new int[n];
        Stack<Integer> s = new Stack<>();
        for (int i = 2 * n - 1; i >= 0; i--) {
            // 主要是会有两次机会 第一次没找到 第二次会更新
            while (!s.empty() && nums[i % n] >= s.peek()) // 把小的都pop出去
                s.pop();
            if (s.empty())
                ans[i % n] = -1;
            else
                ans[i % n] = s.peek();
            s.push(nums[i % n]);
        }
        return ans;
    }
}
// 通过了 还得在理解一下