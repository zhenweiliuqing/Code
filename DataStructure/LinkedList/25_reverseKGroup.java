package LeetCode.Binary_Tree;
import java.util.LinkedList;
import java.util.List;

public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    ListNode nxt = null;

    public ListNode reverseK(ListNode head, int n) {
        if (n == 1) {
            nxt = head.next;
            return head;
        }
        ListNode last = reverseK(head.next, n - 1);
        head.next.next = head;
        head.next = nxt;
        return last;
    }

    public ListNode reverseKGroup(ListNode head, int k) {
        if (k == 1 || head == null)
            return head;

        ListNode cur = head;
        for (int i = 0; i < k; i++) {
            if (cur == null) // 这个要在前面
                return head;
            cur = cur.next;
        }

        // int cnt = k;
        // while (cnt != 0) {
        //     if (cur == NULL)    
        //         return head;
        //     cur = cur->next;
        //     cnt--;
        // }

        ListNode newhead = reverseK(head, k);
        ListNode last = reverseKGroup(cur, k); // 递归一定要明白 当前函数的定义是什么
        head.next = last;
        return newhead;
    }
}
// 可以的 学会了一点
