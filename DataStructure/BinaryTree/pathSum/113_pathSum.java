package LeetCode.Binary_Tree;
import java.util.LinkedList;
import java.util.List;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// 这不就遍历每一条路径 然后算算是否等于sum
class Solution {
    List<List<Integer>> ans = new LinkedList<>();
    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        if (root == null)
            return ans;

        dfs(root, sum);
    }

    public void dfs(TreeNode root, int target, int sum, List<Integer> path) {
        if (root == null) {
            if (sum == target)
                ans.add(path);
            return;
        }

        path.add(root.val);
        dfs(root.left, target, sum + root.val, path);
        path.remove; // 思路有 但是不太会具体细节
        dfs(root.right)
    }
}

class Solution {
    List<List<Integer>> ret = new LinkedList<List<Integer>>();
    Deque<Integer> path = new LinkedList<Integer>();

    public List<List<Integer>> pathSum(TreeNode root, int sum) {
        dfs(root, sum);
        return ret;
    }

    public void dfs(TreeNode root, int sum) {
        if (root == null)   
            return;
        path.offerLast(root.val);
        sum -= root.val;
        if (root.left == null && root.right == null && num == 0) {
            ret.add(new LinkedList<Integer>(path));
        }
        dfs(root.left, sum);
        dfs(root.right, sum);
        path.pollLast();
    }
}