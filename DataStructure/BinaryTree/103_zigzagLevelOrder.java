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

// 这得用一个queue 还得要一个标志位
// 跟那个k级节点有点像 怎么区分k级呢 
class Solution {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        List<List<Integer>> ans = new LinkedList<List<Integer>>();
        if (root == null)
            return ans;
        q.offer(root);
        boolean direction = false;
        while (!q.isEmpty()) {
            direction = !direction;
            List<TreeNode> level = new LinkedList<TreeNode>(q);
            List<Integer> temp = new LinkedList<Integer>();
            q.clear();
            
            if (direction) {
                for (TreeNode node : level) {
                    temp.add(node.val);
                }
            } else {
                for (int i = level.size() - 1; i >= 0; i--) {
                    temp.add(level.get(i).val);
                }
            }
            ans.add(temp);

            for (TreeNode node : level) {
                if (node.left != null)
                    q.offer(node.left);
                if (node.right != null)
                    q.offer(node.right);
            }
        }
        return ans;
    }
}
// 终于通过了 快绕死我了 正正反反


class Answer {
    public List<List<Integer>> zigzagLevelOrder(TreeNode root) {
      if (root == null) {
        return new ArrayList<List<Integer>>();
      }
  
      List<List<Integer>> results = new ArrayList<List<Integer>>();
  
      // add the root element with a delimiter to kick off the BFS loop
      LinkedList<TreeNode> node_queue = new LinkedList<TreeNode>();
      node_queue.addLast(root);
      node_queue.addLast(null); // 用个null表示分层
  
      LinkedList<Integer> level_list = new LinkedList<Integer>();
      boolean is_order_left = true;
  
      while (node_queue.size() > 0) {
        TreeNode curr_node = node_queue.pollFirst();
        if (curr_node != null) {
            if (is_order_left)
                level_list.addLast(curr_node.val);
            else
                level_list.addFirst(curr_node.val);
            
            // 这里还是按照层序先左后右的add
            if (curr_node.left != null)
                node_queue.addLast(curr_node.left);
            if (curr_node.right != null)
                node_queue.addLast(curr_node.right);
    
        } else { // 换层了
            // we finish the scan of one level
            results.add(level_list);
            level_list = new LinkedList<Integer>();
            // prepare for the next level
            if (node_queue.size() > 0)
                node_queue.addLast(null);
            is_order_left = !is_order_left;
        }
      }
      return results;
    }
}
  