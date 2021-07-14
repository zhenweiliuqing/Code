// 12-31

public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}


class Solution {
    public int getLength(ListNode head) {
        int length = 0;
        ListNode node = head;
        while (node != null) {
            node = node.next;
            length++;
        }
        return length;
    }

    public ListNode rotateRight(ListNode head, int k) {
        if (head == null)
            return head;
        int length = getLength(head);
        k = k % length;
        if (k == 0)
            return head;

        ListNode pre = head;
        ListNode end = head;
        while (end.next != null) {
            end = end.next;
            if (k == 0)
                pre = pre.next;
            else
                k--;
        }
        ListNode newHead = pre.next;
        end.next = head;
        pre.next = null;
        return newHead;
    }
}
// 通过了 
