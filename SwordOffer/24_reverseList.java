// 2-7
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}

// 之前通过的思路
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

class Solution1 {
    public ListNode reverseList(ListNode head) {
        if (head == null && head.next == null)
            return head;
        ListNode pPrev = null;
        ListNode pNode = head;
        ListNode pNext = pNode.next;
        while (pNext != null) {
            pNode.next = pPrev;
            pPrev = pNode;
            pNode = pNext;
            pNext = pNext.next;
        }
        return pNode;
    }
}
// 这种思路不能把最后一个节点给串上

class Solution2 {
    public ListNode reverseList(ListNode head) {
        ListNode pReverseHead = null;
        ListNode pNode = head;
        ListNode pPrev = null;
        while (pNode != null) {
            ListNode pNext = pNode.next;
            if (pNext == null)
                pReverseHead = pNode;
            pNode.next = pPrev;
            pPrev = pNode;
            pNode = pNext;
        }
        return pReverseHead;
    }
}