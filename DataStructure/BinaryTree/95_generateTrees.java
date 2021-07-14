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

class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n == 0)
            return new LinkedList<>();
        return generateTrees(1, n);
    }

    public List<TreeNode> generateTrees(int start, int end) {
        List<TreeNode> allTrees = new LinkedList<TreeNode>();
        if (start > end) {
            allTrees.add(null);
            return allTrees;
        }

        for (int i = start; i <= end; i++) {
            List<TreeNode> leftTrees = generateTrees(start, i - 1);
            List<TreeNode> rightTrees = generateTrees(i + 1, end);

            for (TreeNode left : leftTrees) {
                for (TreeNode right : rightTrees) {
                    TreeNode currTree = new TreeNode(i);
                    currTree.left = left;
                    currTree.right = right;
                    allTrees.add(currTree);
                }
            }
        }
        return allTrees;
    }
}

class Solution {
    public List<TreeNode> generateTrees(int n) {
        if (n == 0)
            return new LinkedList<>(); // 不能是add 否则就是[[]]
        return helper(1, n);
    }
    
    // 基本情况是什么
    public List<TreeNode> helper(int st, int end) {
        List<TreeNode> temp = new LinkedList<TreeNode>();
        if (st > end) {
            temp.add(null);
            return temp;
        }

        for (int i = st; i <= end; i++) {
            List<TreeNode> left = helper(st, i - 1);
            List<TreeNode> right = helper(i + 1, end);

            for (TreeNode leftNode : left) {
                for (TreeNode rightNode : right) {
                    TreeNode root = new TreeNode(i); // 要放到里边 在外边不一定能被覆盖?? 还是不懂 为什么不会被覆盖
                    root.left = leftNode;
                    root.right = rightNode;
                    temp.add(root);
                }
            }
        }
        return temp;
    }
}
// 思路是正确的 但是有三个细节没有注意到
// 主函数里不需要再写一遍了 
// left那边应该是st 不是1
// root 应该定义在循环里

// 通过了 再好好体会一下 single single node