package LeetCode.Array;

import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Stack;
import java.util.List;
import java.util.ArrayList;
import java.util.HashMap;

class Solution {
    public int[] nextGreaterElement(int[] nums1, int[] nums2) {
        // 找到nums2的全部结果 建立一个map
        Stack<Integer> s = new Stack<Integer>();
        HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
        List<Integer> array = new ArrayList<>();
        for (int num : nums2) {
            array.add(num);
        }
        int n = array.size();
        
        for (int i = n - 1; i >= 0; i--) {
            while (!s.empty() && array.get(i) > s.peek()) {
                s.pop();
            }

            if (s.empty())
                map.put(array.get(i), -1);
            else
                map.put(array.get(i), s.peek());
            s.push(array.get(i));
        }
        
        List<Integer> ans = new ArrayList<>();
        for (int num : nums1) {
            ans.add(map.get(num));
        }
        for (int i = 0; i < ans.size(); i++)
            nums1[i] = ans.get(i);
        return nums1;
    }
}
// 通过了 就是不会处理int[] 弄得有点复杂了 

public class Solution {
    public int[] nextGreaterElement(int[] findNums, int[] nums) {
        Stack<Integer> stack = new Stack<>();
        HashMap<Integer, Integer> map = new HashMap<>();
        int[] res = new int[findNums.length];
        // 从前往后啊
        for (int i = 0; i < nums.length; i++) {
            while (!stack.empty() && nums[i] > stack.peek()) // 最大栈 是递减的
                map.put(stack.pop(), nums[i]);
            stack.push(nums[i]);
        }
        while (!stack.empty())
            map.put(stack.pop(), -1);
        for (int i = 0; i < findNums.length; i++) {
            res[i] = map.get(findNums[i]);
        }
        return res;
    }
}