import java.security.acl.LastOwnerException;

import org.graalvm.compiler.graph.Node;

// 2-17
class Node {
    public int val;
    public Node left;
    public Node right;

    public Node() {}

    public Node(int _val) {
        val = _val;
    }

    public Node(int _val,Node _left,Node _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 参考答案
class Solution {
    Node pre, head;

    public Node treeToDoublyList(Node root) {
        if (root == null)
            return null;
        dfs(root);
        head.left = pre;
        pre.right = head;
        return head;
    }

    void dfs(Node cur) {
        if (cur == null)
            return;
        dfs(cur.left);

        if (pre != null)
            pre.right = cur;
        else
            head = cur;
        cur.left = pre;
        pre = cur;

        dfs(cur.right);
    }
}

// 2-18
class Solution {
    Node pre, head;
    public Node treeToDoublyList(Node root) {
        if (root == null)
            return null;
        dfs(root);
        pre.right = head;
        head.left = pre;
        return head;
    }
    public void dfs(Node root) {
        if (root == null)
            return;
        dfs(root.left);

        if (pre == null)
            head = root;
        else
            pre.right = root;
        root.left = pre;
        pre = root;

        dfs(root.right);
    }
}
// 通过了


// 二叉搜索树转换成双向链表 要用到递归
// 先把左子树给转换完成 然后接上root 然后再去转换右子树 
// 这个函数的作用就是将一棵树转化成一个双向链表 返回的是头节点
// 我需要一个函数可以得到上一次最后一个Node
class Solution {
    public Node treeToDoublyList(Node root) {
        Node lastNode = new Node();
        lastNode = treeToDoublyList(root, null);
        while (lastNode.left != null)
            lastNode = lastNode.left;
        return lastNode;
    }

    // 这个返回上次最后一个节点
    public Node treeToDoublyList(Node root, Node lastNode) {
        // 假如root是一个叶子节点
        if (root.left == null && root.right == null) {
            if (lastNode != null) {
                root.left = lastNode;
                lastNode.right = root;
            }
            lastNode = root;
            return lastNode;
        }

        // 左子树
        if (root.left != null)
            lastNode = treeToDoublyList(root.left, lastNode);

        // 进行root的连接
        if (lastNode != null)
            lastNode.right = root;
        root.left = lastNode;
        lastNode = root;

        // 右子树连接
        if (root.right != null)
            lastNode = treeToDoublyList(root.right, lastNode);
        return lastNode;
    }
}
// 没通过

