package LeetCode.Binary_Tree;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// 先用一下暴力算法求解
class Solution {
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
        
        int leftnodes = countNodes(root.left);
        int rightnodes = countNodes(root.right);
        return leftnodes + rightnodes + 1;    
    }
}
// 通过了 ？？ 竟然没超时？

class Solution {
    public int countNodes(TreeNode root) {
        if (root == null)
            return 0;
        
        int hl = 1, hr = 1;
        TreeNode leftNode = root.left, rightNode = root.right;
        while (leftNode != null) {
            hl++;
            leftNode = leftNode.left;
        }
        while (rightNode != null) {
            hr++;
            rightNode = rightNode.right;
        }
        if (hl == hr)
            return (int)Math.pow(2, hl) - 1;

        int leftnodes = countNodes(root.left);
        int rightnodes = countNodes(root.right);

        return leftnodes + rightnodes + 1;
    }
}

