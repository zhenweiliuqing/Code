package LeetCode.Algorithm.1-TwoPointers;
// 12-31
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) { val = x; }
}
class Solution {
    public ListNode partition(ListNode head, int x) {
        ListNode dummyS = new ListNode(0);
        ListNode dummyL = new ListNode(0);
        ListNode headS = dummyS, headL = dummyL;

        while (head != null) {
            if (head.val < x) {
                headS.next = head;
                headS = headS.next;
            } else {
                headL.next = head;
                headL = headL.next;
            }
            head = head.next;
        }
        headL.next = null;
        headS.next = dummyL.next;
        return dummyS.next;
    }
}
// 通过了