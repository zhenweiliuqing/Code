// 2-8
public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

// 思路: 先让第一个指针走k步 第二个指针跟着走
class Solution {
    public ListNode getKthFromEnd(ListNode head, int k) {
        // head为null k为0
        if (head == null || k == 0)
            return null;
        ListNode first = head;
        for (int i = 0; i < k; i++) {
            if (first == null)
                return null;
            first = first.next;
        }
        ListNode second = head;
        while (first != null) {
            first = first.next;
            second = second.next;
        }
        return second;
    }
}
// 通过了