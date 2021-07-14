// 2-14
import java.util.LinkedList;
import java.util.ArrayList;
import java.util.HashMap;
import java.util.Queue;

class Node {
    int val;
    Node next;
    Node random;

    public Node(int val) {
        this.val = val;
        this.next = null;
        this.random = null;
    }
}

// 这个题和克隆图很像
// Queue用来遍历每个节点 HashTable用原节点对应克隆的节点
// 先建成一个链表 同时建成一个hashtable

// 测试用例：1 2
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;
        HashMap<Node, Node> map = new HashMap<>();
        // 建立一个克隆head
        // Node clonedHead = new Node(head.val);
        // Node clonedNode = clonedHead;
        Node node = head;
        map.put(node, new Node(node.val));

        // 先形成一条链表
        while (node.next != null) {
            Node clonedNext = new Node(node.next.val);
            clonedNode.next = clonedNext;
            clonedNode = clonedNode.next;
            node = node.next;
            map.put(node, new Node(node.random.val));
        }
        // 再去连接random
        node = head;
        while (node != null) {

        }
        return;
    }
}

// 2-16
class Solution {
    public Node copyRandomList(Node head) {
        if (head == null)
            return null;
        HashMap<Node, Node> map = new HashMap<>();

        Node node = head;
        map.put(node, new Node(node.val));

        while (node != null) {
            if (node.next != null) {
                if (!map.containsKey(node.next))
                    map.put(node.next, new Node(node.next.val));
                map.get(node).next = map.get(node.next);
            }
            
            
            if (node.random != null) {
                if (!map.containsKey(node.random))
                    map.put(node.random, new Node(node.random.val));
                map.get(node).random = map.get(node.random);
            }
            node = node.next;
        }
        return map.get(head);
    }
}
// 通过了 照着克隆图抄的