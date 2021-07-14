// 3-22
class Solution {
public:
    /**
     * 
     * @param root TreeNode类 the root
     * @return bool布尔型vector
     */
    vector<bool> judgeIt(TreeNode* root) {
        // write code here
        vector<bool> ans(2);
        ans[0] = isBST(root);
        ans[1] = isCompleteTree(root);
        return ans;
    }
    
    bool isBST(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left != NULL && root->left->val > root->val)
            return false;
        if (root->right != NULL && root->right->val < root->val)
            return false;
        return isBST(root->left) && isBST(root->right);
    }
    
    bool isCompleteTree(TreeNode* root) {
        if (root == NULL)
            return true;
        if (root->left == NULL && root->right == NULL)
            return true;
        if (root->left == NULL && root->right != NULL)
            return false;
        return isCompleteTree(root->left) && isCompleteTree(root->right);
    }
};
// 牛客 通过