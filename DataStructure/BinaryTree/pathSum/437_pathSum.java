import java.util.Map;
import javax.swing.tree.TreeNode;

// 前缀和 不太懂
class Solution {
    public int pathSum(TreeNode root, int sum) {
        Map<Integer, Integer> prefixSumCount = new HashMap<>();
        prefixSumCount.put(0, 1);
        return recursionPathSum(root, prefixSumCount, sum, 0);
    }

    private int recursionPathSum(TreeNode node, Map<Integer, Integer> prefixSumCount, int target, int currSum) {
        if (node == null)
            return 0;
        
        int res = 0;
        currSum += node.val;
        res += prefixSumCount.getOrDefault(currSum - target, 0);
        prefixSumCount.put(currSum, prefixSumCount.getOrDefault(currSum, 0) + 1);
        
        res += recursionPathSum(node.left, prefixSumCount, target, currSum);
        res += recursionPathSum(node.right, prefixSumCount, target, currSum);

        prefixSumCount.put(currSum, prefixSumCount.get(currSum) - 1);
        return res;
    }
} 

// 双递归
class Solution2 {
    public int pathSum(TreeNode root, int sum) {
        if (root == null)
            return 0;
        int result = countPath(root, sum);
        int a = pathSum(root.left, sum);
        int b = pathSum(root.right, sum);
        return result + a + b;
    }

    public int countPath(TreeNode root, int sum) {
        if (root == null)
            return 0;
        sum = sum - root.val;
        int result = sum == 0 ? 1 : 0;
        return result + countPath(root.left, sum) + countPath(root.right, sum);
    }
}
// result 不是全局变量 返回的是cnt