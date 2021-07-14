import java.util.LinkedList;

import javax.swing.text.html.HTMLEditorKit.Parser;

// 2-22

// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode(int x) { val = x; }
}

public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder s = new StringBuilder();
        serialize(root, s);
        return s.toString();
    }

    public void serialize(TreeNode root, StringBuilder s) {
        if (root == null) {
            s.append("#,");
            return;
        }
        s.append(root.val).append(",");
        serialize(root.left, s);
        serialize(root.right, s);
    }
    // Decodes your encoded data to tree.
    // 解码如何返回一棵树
    public TreeNode deserialize(String data) {
        LinkedList<String> nodes = new LinkedList<>();
        for (String s : data.split(",")) {
            nodes.addLast(s); // 相当于是个queue啊
        }
        // TreeNode root = new TreeNode(x);
        return deserialize(nodes);
    }

    public TreeNode deserialize(LinkedList<String> nodes) {
        String node = nodes.removeFirst(); // 队列
        // 这里需要用equals
        if (node.equals("#"))
            return null;
        TreeNode cur = new TreeNode(Integer.parseInt(node));
        cur.left = deserialize(nodes);
        cur.right = deserialize(nodes);
        return cur;
    }
}
// 通过了 一些细节需要注意

// 1. StringBuilder
// 2. toString
// 3. append("#,")
// 4. LinkedList<String>
// 5. addLast removeFirst
// 6. equals("#")

public class Codec {
    // Encodes a tree to a single string.
    public String serialize(TreeNode root) {
        StringBuilder s = new StringBuilder();
        dfs(root, s);
        return s.toString();
    }
    public void dfs(TreeNode root, StringBuilder s) {
        if (root == null) {
            s.append("#,");
            return;
        }
        s.append(root.val).append(",");
        dfs(root.left, s);
        dfs(root.right, s);
    }

    // Decodes your encoded data to tree.
    public TreeNode deserialize(String data) {
        LinkedList<String> q = new LinkedList<>();
        for (String it : data.split(","))
            q.addLast(it);
        return buildtree(q);
    }
    public TreeNode buildtree(LinkedList<String> q) {
        String s = q.removeFirst();
        if (s.equals("#"))
            return null;
        TreeNode root = new TreeNode(Integer.parseInt(s));
        root.left = buildtree(q);
        root.right = buildtree(q);
        return root;
    }
}
