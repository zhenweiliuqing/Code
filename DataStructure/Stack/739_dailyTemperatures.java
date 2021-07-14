import java.util.LinkedList;
import java.util.ArrayList;
import java.util.Stack;
import java.util.List;

class Solution {
    public int[] dailyTemperatures(int[] T) {
        int n = T.length;
        int[] ans = new int[n];
        Stack<Integer> s = new Stack<>();

        for (int i = n - 1; i >= 0; i--) {
            while (!s.isEmpty() && T[i] >= T[s.peek()]) {
                s.pop();
            }
            if (s.isEmpty())
                ans[i] = 0;
            else
                ans[i] = s.peek() - i;
            s.push(i);
        }
        return ans;
    }
}
// 跟之前是一样的 这种题就没意思了
