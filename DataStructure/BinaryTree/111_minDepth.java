import java.util.LinkedList;
import java.util.Queue;

import jdk.nashorn.api.tree.Tree;

// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode() {
    }

    TreeNode(int val) {
        this.val = val;
    }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

// 用层序遍历就行 while里边得有个循环 记录的是这一层的节点
class Solution {
    public int minDepth(TreeNode root) {
        if (root == null)
            return 0;
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(root);
        int step = 1;
        while (!q.isEmpty()) {
            int size = q.size();
            for (int i = 0; i < size; i++) {
                TreeNode cur = q.poll();
                if (cur.left == null && cur.right == null)
                    return step;
                if (cur.left != null)    
                    q.offer(cur.left);
                if (cur.right != null)
                    q.offer(cur.right);
            }
            step++;
        }
        return step;
    }
}
// 为什么有时候出错 有时候通过