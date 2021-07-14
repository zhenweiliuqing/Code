# Definition for a binary tree node.
class TreeNode:
    def __init__(self, x):
        self.val = x
        self.left = None
        self.right = None

class Solution:
    def buildTree(self, inorder: List[int], postorder: List[int]) -> TreeNode:
        def helper(in_left, in_right):
            if in_left > in_right:
                return None
            
            val = postorder.pop()
            idx = idx_map[val]
            
            tree = TreeNode(val)
            # 右子树 左子树
            tree.right = helper(idx + 1, in_right)
            tree.left = helper(in_left, idx - 1)
            return tree

        # 前后名称要一样
        idx_map = {val:idx for idx, val in enumerate(inorder)}
        return helper(0, len(inorder) - 1)