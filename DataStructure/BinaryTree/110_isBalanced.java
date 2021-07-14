package LeetCode.Binary_Tree;
import java.util.LinkedList;
import java.util.List;

import jdk.nashorn.api.tree.Tree;

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


// 试一下一次遍历的解法 一次遍历跟124很相似
// 就是在得到树高度的同时 判断一下是否符合条件
class Solution {
    boolean isBalanced = true; // 这个操作跟112是否有这条路径很相似

    public boolean isBalanced(TreeNode root) {
        getHeight(root);
        return isBalanced;
    }
    
    public int getHeight(TreeNode root) {
        if (root == null)
            return 0;
        int left = getHeight(root.left);
        int right = getHeight(root.right);
        if (Math.abs(left - right) > 1) {
            isBalanced = false;
        }
        return Math.max(left, right) + 1;
    }
}
// 通过了

// 如何返回子树是不是对称的子树自身的高度
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

