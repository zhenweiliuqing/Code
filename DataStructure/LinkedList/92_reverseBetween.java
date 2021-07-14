package LeetCode.Binary_Tree;
package LeetCode.Binary_Tree;
import java.util.LinkedList;
import java.util.List;

// 反转[m,n]内的链表
public class ListNode {
    int val;
    ListNode next;

    ListNode(int x) {
        val = x;
    }
}

// 第一步 先学会反转链表
// 第二步 学会反转前n个链表
class Solution {
    // 自己的思路是相当混乱 别看了
    
    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (head == null || head.next == null)
            return head;
        // 先找到m
        ListNode pre = head;
        ListNode cur = head.next;
        ListNode nxt = head.next;
        ListNode st = pre;
        int length = n - m;
        while (m != 1) {
            st = pre;
            pre = cur;
            nxt = cur.next;
            cur = nxt;
            m--;
        } // 这是啥玩意？

        ListNode end = pre;
        while (length != 0) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
            length--;
        }
        if (st != end) {
            end.next = nxt;
            st.next = pre;
        }

        return head;
    }
}
// 这个是相当不好理解 还是错的 还是需要一种简单易理解的方法
// 主要是边界问题处理的不好 m = 1 n = 1的时候一些连接不对



// Leetcode 答案
class Solution {
    public ListNode reverseBetween(ListNode head, int m, int n) {
        // Empty list
        if (head == null) {
            return null;
        }

        // Move the two pointers until they reach the proper starting point
        // in the list.
        ListNode cur = head, prev = null;
        while (m > 1) {
            prev = cur;
            cur = cur.next;
            m--;
            n--;
        }

        // The two pointers that will fix the final connections.
        ListNode con = prev, tail = cur;

        // Iteratively reverse the nodes until n becomes 0.
        ListNode third = null;
        while (n > 0) {
            third = cur.next;
            cur.next = prev;
            prev = cur;
            cur = third;
            n--;
        }

        // Adjust the final connections as explained in the algorithm
        if (con != null) {
            con.next = prev;
        } else {
            head = prev;// m = 1的操作
        }

        tail.next = cur;
        return head;
    }
}

// 最后我的这种思路还是不错的
class Solution {
    public ListNode reverseN(ListNode head, int n) {
        if (n == 1)
            return head;
        
        ListNode pre = head;
        ListNode cur = head.next, nxt = cur;
        while (n != 1) {
            nxt = cur.next;
            cur.next = pre;
            pre = cur;
            cur = nxt;
            n--;
        }
        head.next = nxt;
        return pre;
    }

    public ListNode reverseBetween(ListNode head, int m, int n) {
        if (m == 1) {
            return reverseN(head, n);
        }

        ListNode cur = head;
        ListNode pre = null;        
        while (m != 1) {
            pre = cur;
            cur = cur.next;
            m--;
            n--;
        }
  
        pre.next = reverseN(cur, n);
        return head;
    }
}
// 通过了

// labuladong 
class Solution {
    ListNode successor = null; // 后驱节点

    // 反转以 head 为起点的 n 个节点，返回新的头结点
    ListNode reverseN(ListNode head, int n) {
        if (n == 1) { 
            // 记录第 n + 1 个节点
            successor = head.next;
            return head;
        }
        // 以 head.next 为起点，需要反转前 n - 1 个节点
        ListNode last = reverseN(head.next, n - 1);
    
        head.next.next = head;
        // 让反转之后的 head 节点和后面的节点连起来
        head.next = successor;
        return last;
    }    

    ListNode reverseBetween(ListNode head, int m, int n) {
        // base case
        if (m == 1) {
            return reverseN(head, n);
        }
        // 前进到反转的起点触发 base case
        head.next = reverseBetween(head.next, m - 1, n - 1);
        return head;
    }
}