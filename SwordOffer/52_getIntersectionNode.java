// 3-3
// Definition for singly-linked list.
public class ListNode {
    int val;
    ListNode next;
    ListNode(int x) {
        val = x;
        next = null;
    }
}
 
public class Solution {
    public ListNode getIntersectionNode(ListNode headA, ListNode headB) {
        if (headA == null || headB == null)
            return null;
        
        int lengthA = 0, lengthB = 0;
        ListNode listA = headA, listB = headB;
        while (listA != null) {
            lengthA++;
            listA = listA.next;
        }
        while (listB != null) {
            lengthB++;
            listB = listB.next;
        }
        
        listA = headA;
        listB = headB;
        if (lengthA < lengthB) {
            for (int i = 0; i < lengthB - lengthA; i++)
                listB = listB.next;
        } else if (lengthA > lengthB) {
            for (int i = 0; i < lengthA - lengthB; i++)
                listA = listA.next;                
        }

        while (listA != null && listB != null && listA != listB) {
            listA = listA.next;
            listB = listB.next;
        }
        if (listA == listB)
            return listA;
        return null;
    }
}
// 一次通过