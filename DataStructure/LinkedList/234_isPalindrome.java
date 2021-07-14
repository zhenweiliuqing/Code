package LeetCode.LinkedList;

public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

// 反转一条链表 跟现在一比就可以 
class Solution {
    public ListNode reverse(ListNode head) {
        if (head.next == null)
            return head;
        ListNode newhead = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return newhead;
    }

    public boolean isPalindrome(ListNode head) {
        if (head == null)
            return true;
        ListNode cur = head;
        ListNode reverseList = reverse(cur);
        while (head != null) {
            if (head.val != reverseList.val)
                return false;
            head = head.next;
            reverseList = reverseList.next;
        }
        return true;
    }
}
// 感觉没有问题啊 
// 1 1 2 1 怎么出问题了？ 莫名其妙
// 发现问题了 head现在next就是null

// 反转半条链表
class Solution {
    public ListNode reverse(ListNode head) {
        if (head.next == null)
            return head;
        ListNode newhead = reverse(head.next);
        head.next.next = head;
        head.next = null;
        return newhead;
    }

    public boolean isPalindrome(ListNode head) {
        if (head == null || head.next == null)
            return true;
        
        ListNode slow = head;
        ListNode fast = head;
        // while (fast != null && fast.next != null)
        while (fast != null) {
            if (fast.next == null)
                break;
            fast = fast.next.next;
            slow = slow.next;
        }

        // slow应该就是中间
        ListNode mid = reverse(slow);
        while (mid != null) {
            if (mid.val != head.val)
                return false;
            mid = mid.next;
            head = head.next;
        }
        return true;
    }
}
// 终于通过了 崩溃了