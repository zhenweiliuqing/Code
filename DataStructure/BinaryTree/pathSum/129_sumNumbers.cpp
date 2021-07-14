// 4-23
// 跟第一次思路一样 
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int sum) {
        if (root == nullptr)
            return;
        sum = sum * 10 + root->val;
        if (root->left == nullptr && root->right == nullptr) {
            ans += sum;
            return;
        }
        dfs(root->left, sum);
        dfs(root->right, sum);
    }
    int sumNumbers(TreeNode* root) {
        dfs(root, 0);
        return ans;
    }
};