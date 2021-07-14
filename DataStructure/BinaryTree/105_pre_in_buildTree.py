# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, preorder: List[int], inorder: List[int]) -> TreeNode:
        def helper(in_left, in_right):
            if in_left > in_right:
                return None
            
            val = preorder.pop()
            idx = idx_map[val]
            
            tree = TreeNode(val)
            # 左子树 右子树
            tree.left = helper(in_left, idx - 1)
            tree.right = helper(idx + 1, in_right)
            return tree
        preorder.reverse() # 这里反转一下就可以了 
        idx_map = {val : idx for idx, val in enumerate(inorder)}
        return helper(0, len(inorder) - 1)