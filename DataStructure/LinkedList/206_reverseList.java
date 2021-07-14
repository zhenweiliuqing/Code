package LeetCode.Binary_Tree;
package LeetCode.Binary_Tree;
import java.util.LinkedList;
import java.util.List;

public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

// 反转链表
class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode newhead = reverseList(head.next);
        head.next.next = head; // 返回的是以head.next 逆序的链表 原来指向是null
        head.next = null;
        return newhead;
    }
}


class Solution {
    public ListNode reverseList(ListNode head) {
        if (head == null || head.next == null)
            return head;
        ListNode pre = null;
        ListNode cur = head;
        ListNode nxt = head;
        while (cur != null) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
        }
        return pre;
    }
}
// 通过了
