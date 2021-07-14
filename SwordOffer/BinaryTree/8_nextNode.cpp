// 3-18
// 寻找中序遍历root的下一个节点
// root有右子树 那么就是右子树的最左节点
// root 没有右子树 
// 1.root为左子节点 下一个节点就是父节点
// 2.往上一直找到root的祖先节点是左子节点 返回其祖先节点的父节点 
TreeNode* nextNode(TreeNode* root) {
    if (root == NULL)
        return root;
    TreeNode *ans = NULL;
    TreeNode *cur = root, *par = cur->parent;
    
    if (cur->right != NULL) {
        ans = cur->right;
        while (ans->left != NULL)
            ans = ans->left;
    } else if (cur->right == NULL) {
        while (par != NULL && cur == par->right) {
            cur = par;
            par = cur->parent;
        }
        ans = par;
    }
    return ans;
}