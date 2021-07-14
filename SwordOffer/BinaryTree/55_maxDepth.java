package LeetCode.SwordOffer.BinaryTree;

// 3-18
class Solution {
    int ans = 0;
    public int maxDepth(TreeNode root) {
        dfs(root, 0);
        return ans;
    }
    public void dfs(TreeNode root, int depth) {
        if (root == null) {
            ans = Math.max(ans, depth);
            return;
        }
        dfs(root.left, depth + 1);
        dfs(root.right, depth + 1);
    }
}

