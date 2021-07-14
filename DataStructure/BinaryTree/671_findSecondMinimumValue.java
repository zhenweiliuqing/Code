
// Definition for a binary tree node.
public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;
    TreeNode() {}
    TreeNode(int val) { this.val = val; }

    TreeNode(int val, TreeNode left, TreeNode right) {
        this.val = val;
        this.left = left;
        this.right = right;
    }
}

class Solution {
    int first = Integer.MAX_VALUE, second = Integer.MAX_VALUE;
    boolean flag = false; // 得需要个标志位判断一下
    public void dfs(TreeNode root) {
        if (root == null)
            return;
        if (root.val < first) {
            second = first;
            first = root.val;
        } else if (root.val <= second && root.val != first) {
            flag = true;
            second = root.val;
        }
        dfs(root.left);
        dfs(root.right);
    }
    public int findSecondMinimumValue(TreeNode root) {
        if (root == null)
            return -1;
        dfs(root);
        return !flag ? -1 : second;
    }
}
// 可真够坏的啊 second等于INT_MAX
// 用minheap 是不是就好一点
// 不知道该如何使用这道题信息
// 通过了

