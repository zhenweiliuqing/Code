// 2-7
// Definition for singly-linked list.
class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
        next = null;
    }
}

// 思路: 先通过快慢指针找到相交点 再从头开始再次相遇就是环的入口
public class Solution {
    public ListNode detectCycle(ListNode head) {
        if (head == null)
            return head;
        ListNode fast = head;
        ListNode slow = head;
        while (fast != null && fast.next != null) {
            fast = fast.next.next;
            slow = slow.next;
            if (fast == slow)
                break;
        }
        // 如果fast为null 说明没有环
        if (fast == null || fast.next == null)
            return null;
        fast = head;
        while (fast != slow) {
            fast = fast.next;
            slow = slow.next;
        }
        return fast;
    }
}
// 通过了