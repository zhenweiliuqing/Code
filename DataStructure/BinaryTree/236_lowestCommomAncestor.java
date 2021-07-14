package LeetCode.Binary_Tree;

import jdk.nashorn.api.tree.Tree;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// 需要理解一点 如果p q在root的两边 则root就是lca
class Solution {
    public TreeNode lowestCommonAncestor(TreeNode root, TreeNode p, TreeNode q) {
        if (root == null)
            return null;
        if (root.val == p.val ||
            root.val == q.val)
            return root;
        
        // 返回lca
        TreeNode leftResult = lowestCommonAncestor(root.left, p, q);
        TreeNode rightResult = lowestCommonAncestor(root.right, p, q);

        if (leftResult == null)
            return rightResult;
        if (rightResult == null)
            return leftResult;
        return root;
    }
}
// 通过了 这个还得再理解一下