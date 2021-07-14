package LeetCode.Binary_Tree;

import java.util.LinkedList;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

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



// 前序遍历
public class Solution {
    String SEP = ",";
    String NULL = "#";

    String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }

    void serialize(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append(NULL).append(SEP);
            return;
        }
        sb.append(root.val).append(SEP);

        serialize(root.left, sb);
        serialize(root.right, sb);
    }

    TreeNode deserialize(String data) {
        LinkedList<String> nodes = new LinkedList<>();
        for (String s : data.split(SEP)) {
            nodes.addLast(s);
        }
        return deserialize(nodes);
    }

    TreeNode deserialize(LinkedList<String> nodes) {
        if (nodes.isEmpty())
            return null;

        String first = nodes.removeFirst(); // 其实就是queue
        if (first.equals(NULL))
            return null;

        TreeNode root = new TreeNode(Integer.parseInt(first));
        root.left = deserialize(nodes);
        root.right = deserialize(nodes);
        return root;
    }
}


// 后序遍历
public class Solution {
    String SEP = ",";
    String NULL = "#";

    String serialize(TreeNode root) {
        StringBuilder sb = new StringBuilder();
        serialize(root, sb);
        return sb.toString();
    }

    void serialize(TreeNode root, StringBuilder sb) {
        if (root == null) {
            sb.append(NULL).append(SEP);
            return;
        }

        serialize(root.left, sb);
        serialize(root.right, sb);
        sb.append(root.val).append(SEP);
    }

    TreeNode deserialize(String data) {
        LinkedList<String> nodes = new LinkedList<>();
        for (String s : data.split(SEP)) {
            nodes.addLast(s);
        }
        return deserialize(nodes);
    }

    TreeNode deserialize(LinkedList<String> nodes) {
        if (nodes.isEmpty()) 
            return null;
        
        String last = nodes.removeLast();
        if (last.equals(NULL))
            return null;

        TreeNode root = new TreeNode(Integer.parseInt(last));
        root.right = deserialize(nodes);
        root.left = deserialize(nodes);
        return root;
    }
}

public class Solution {
    String SEP = ",";
    String NULL = "#";

    String serialize(TreeNode root) {
        if (root == null)
            return "";
        StringBuilder sb = new StringBuilder();

        Queue<TreeNode> q = new LinkedList<>(); // LinkedList可以当queue用的
        q.offer(root);

        while (!q.isEmpty()) {
            TreeNode cur = q.poll();

            if (cur == null) {
                sb.append(NULL).append(SEP);
                continue;
            }
            sb.append(cur.val).append(SEP);
            q.offer(cur.left);
            q.offer(cur.right);
        }
        return sb.toString();
    }

    TreeNode deserialize(String data) {
        if (data.isEmpty())
            return null;
        String[] nodes = data.split(SEP);

        TreeNode root = new TreeNode(Integer.parseInt(nodes[0]));

        Queue<TreeNode> q = new LinkedList<>();
        q.offer(root);

        for (int i = 1; i < nodes.lenght;) {
            TreeNode parent = q.poll();
            String left = nodes[i++];

            if (!left.equals(NULL)) {
                parent.left = new TreeNode(Integer.parseInt(left));
                q.offer(parent.left);
            } else {
                parent.left = null;
            }

            String right = nodes[i++];
            if (!right.equals(NULL)) {
                parent.right = new TreeNode(Integer.parseInt(right));
                q.offer(parent.right);
            } else {
                parent.right = null;
            }
        }
        return root;
    }
} 
