// 2-8
public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

// 这次用递归的方式做一下
// 这个函数作用就是返回一条有序的新链表
class Solution {
    public ListNode mergeTwoLists(ListNode l1, ListNode l2) {
        if (l1 == null)
            return l2;
        else if (l2 == null)
            return l1;

        ListNode mergedHead = null;
        if (l1.val < l2.val) {
            mergedHead = l1;
            mergedHead.next = mergeTwoLists(l1.next, l2);
        } else {
            mergedHead = l2;
            mergedHead.next = mergeTwoLists(l1, l2.next);
        }
        return mergedHead;
    }
}
// 通过了
