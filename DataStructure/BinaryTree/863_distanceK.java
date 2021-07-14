package LeetCode.Binary_Tree;
import java.util.LinkedList;
import java.util.List;
import java.util.Queue;
import java.util.Map;
import java.util.Set;
import jdk.nashorn.api.tree.Tree;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;

public class TreeNode {
    int val;
    TreeNode left;
    TreeNode right;

    TreeNode(int x) {
        val = x;
    }
}

// 怎么弄一个hashtabel 存一下父节点
class Solution {
    HashMap<Integer, TreeNode> par = new HashMap<Integer, TreeNode>();
    HashMap<Integer, Boolean> isVisited = new HashMap<Integer, Boolean>();

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        // 先遍历一下建立一个hashtable
        List<Integer> ans = new LinkedList<Integer>();
        createHashMap(root);
        Queue<TreeNode> q = new LinkedList<TreeNode>();
        q.offer(target);
        isVisited.put(target.val, true);
        
        int level = 0;
        while (!q.isEmpty()) {
            if (level == K) {
                for (TreeNode node : q) {
                    ans.add(node.val);
                }
                return ans;
            }
            
            List<TreeNode> temp = new LinkedList<TreeNode>(q);
            q.clear();
            for (TreeNode node : temp) {
                if (node.left != null && !isVisited.get(node.left.val)) {
                    q.offer(node.left);
                    isVisited.put(node.left.val, true);
                }
                if (node.right != null && !isVisited.get(node.right.val)) {
                    q.offer(node.right);
                    isVisited.put(node.right.val, true);
                }
                if (node.val != root.val) {
                    if (!isVisited.get(par.get(node.val).val)) {
                        q.offer(par.get(node.val));
                        isVisited.put(par.get(node.val).val, true);           
                    }
                }
            }
            level++;
        }
        return ans;
    }

    public void createHashMap(TreeNode root) {
        if (root == null)   
            return;
        isVisited.put(root.val, false);
        if (root.left != null) {
            par.put(root.left.val, root);
            createHashMap(root.left);
        }
        if (root.right != null) {
            par.put(root.right.val, root);
            createHashMap(root.right);                
        }
    }
}
// 通过了

class Answer {
    Map<TreeNode, TreeNode> parent;

    public List<Integer> distanceK(TreeNode root, TreeNode target, int K) {
        parent = new HashMap<>();
        dfs(root, null);

        Queue<TreeNode> queue = new LinkedList<>();
        queue.add(null); // 用个 null 分层
        queue.add(target);

        Set<TreeNode> seen = new HashSet<>();
        seen.add(target);
        seen.add(null);

        int dist = 0;
        while (!queue.isEmpty()) {
            TreeNode node = queue.poll();
            if (node == null) {
                if (dist == K) {
                    List<Integer> ans = new ArrayList<>();
                    for (TreeNode n : queue)
                        ans.add(n.val);
                    return ans;
                }
                queue.offer(null);
                dist++;
            } else {
                if (!seen.contains(node.left)) {
                    seen.add(node.left);
                    queue.offer(node.left);
                }
                if (!seen.contains(node.right)) {
                    seen.add(node.right);
                    queue.offer(node.right);
                }
                TreeNode par = parent.get(node);
                if (!seen.contains(par)) {
                    seen.add(par);
                    queue.offer(par);
                }
            }
        }
        return new ArrayList<Integer>();
    }

    public void dfs(TreeNode node, TreeNode par) {
        if (node != null) {
            parent.put(node, par);
            dfs(node.left, node);
            dfs(node.right, node);
        }
    }
}