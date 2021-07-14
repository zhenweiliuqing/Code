package LeetCode.SwordOffer.BinaryTree;

// 之前写的好简洁
class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;
        int left = getHeight(root.left);
        int right = getHeight(root.right);
        if (Math.abs(left - right) <= 1 && isBalanced(root.left) && isBalanced(root.right))
            return true;
        return false;        
    }

    public int getHeight(TreeNode root) {
        if (root == null)
            return -1;
        int left = getHeight(root.left);
        int right = getHeight(root.right);
        return Math.max(left, right) + 1;
    }
}
// 通过了 针不戳


class Solution {
    public boolean isBalanced(TreeNode root) {
        if (root == null)
            return true;
        dfs(root);
        int left = 0, right = 0;
        if (root.left != null)
            left = root.left.val;
        if (root.right != null)
            right = root.right.val;
        return isBalanced(root.left) && isBalanced(root.right) && Math.abs(left - right) <= 1;
    }

    public void dfs(TreeNode root) {
        if (root == null)
            return;
        if (root.left == null && root.right == null) {
            root.val = 1;
            return;
        }
        dfs(root.left);
        dfs(root.right);
        if (root.left != null && root.right != null)
            root.val = Math.max(root.left.val, root.right.val) + 1;
        else if (root.left != null)
            root.val = root.left.val + 1;
        else
            root.val = root.right.val + 1;

    }
}
// 通过了  但是好麻烦
