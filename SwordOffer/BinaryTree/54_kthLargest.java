package LeetCode.SwordOffer.BinaryTree;

// 二叉搜索树的第k大节点 
// 二叉搜索树是有序的 正着遍历就是倒数第k个 倒着遍历就是第k个
class Solution {
    public int kthLargest(TreeNode root, int k) {
        ArrayList<Integer> data = new ArrayList<>();
        dfs(root, data);
        return data.get(k - 1);
    }

    public void dfs(TreeNode root, ArrayList<Integer> data) {
        if (root == null)
            return;
        dfs(root.right, data);
        data.add(root.val);
        dfs(root.left, data);
    }
}
// 通过


class Solution {
    public int kthLargest(TreeNode root, int k) {
        ArrayList<Integer> data = new ArrayList<>();
        dfs(root, data);
        int len = data.size();
        return data.get(len - k);
    }
    public void dfs(TreeNode root, ArrayList<Integer> data) {
        if (root == null)
            return;
        dfs(root.left, data);
        data.add(root.val);
        dfs(root.right, data);
        
    }
}
// 通过