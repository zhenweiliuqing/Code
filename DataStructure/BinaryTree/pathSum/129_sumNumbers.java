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

// 就是深度优先遍历每一条路径
class Solution {
    int ans = 0;

    public int sumNumbers(TreeNode root) {
        dfs(root, 0);
        return ans;
    }
    
    public void dfs(TreeNode root, int sum) {
        if (root == null) {
            return;
        }
        sum = sum * 10 + root.val;
        if (root.left == null && root.right == null) {
            ans += sum;
            return;
        }

        //if (root.left != null) 这判断没用
        dfs(root.left, sum);
        //if (root.right != null)
        dfs(root.right, sum);
    }
}
// 通过了 一定要注意递归时不要用脑子压栈
// 我这是preorder postorder也是可以的