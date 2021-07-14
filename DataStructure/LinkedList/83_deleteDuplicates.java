package LeetCode.LinkedList;

public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
    
// 0 0 1 2 3 3 4 5 5 5
class Solution {
    public ListNode deleteDuplicates(ListNode head) {
        if (head == null)
            return head;
        ListNode slow = head, fast = head;
        while (fast.next != null) {
            if (fast.val != fast.next.val) {
                slow.val = fast.val;
                slow = slow.next;
            }
            fast = fast.next;
        }
        slow.val = fast.val;
        slow.next = null;
        return head;
    }
}
// 通过了

// 也可以直接指向下一个节点
// cur = cur.next.next;