package LeetCode.Binary_Tree;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.ArrayList;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

class Solution {
    public boolean isSymmetric(TreeNode root) {
        if (root == null)
            return true;
        return isSymmetric(root.left, root.right);
    }
    
    public boolean isSymmetric(TreeNode left, TreeNode right) {
        if (left == null && right == null)
            return true;
        else if (left != null && right != null) {
            return left.val == right.val && isSymmetric(left.left,right.right) && isSymmetric(left.right,right.left);
        }
        return false;
    }
}
// 通过了 
// 好好理解一下 如何使用递归
// 看着简单其实挺妙的