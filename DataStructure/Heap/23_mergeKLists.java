import LeetCode.Algorithm.PriorityQueue;

// 3-18


//  Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode() {}
    ListNode(int val) { this.val = val; }
    ListNode(int val, ListNode next) { this.val = val; this.next = next; }
}

class Solution {
    public ListNode mergeKLists(ListNode[] lists) {
        PriorityQueue<ListNode> q = new PriorityQueue<>((x, y) -> x.val - y.val);
        for (ListNode node : lists) {
            if (node != null)
                q.add(node);
        }
        ListNode dummy = new ListNode(-1);
        ListNode cur = dummy;
        while (!q.isEmpty()) {
            cur.next = q.poll();
            cur = cur.next;
            if (cur.next != null)
                q.add(cur.next);
        }
        return dummy.next;
    }
}