// 4-23

class Solution {
public:
    vector<string> ans;
    void dfs(TreeNode* root, string s) {
        if (root == nullptr)
            return;
        s += (to_string(root->val) + "->");
        if (root->left == nullptr && root->right == nullptr) {
            s.erase(s.size() -2 , 2);
            ans.push_back(s);
        }
        dfs(root->left, s);
        dfs(root->right, s);
    }
    vector<string> binaryTreePaths(TreeNode* root) {
        string s;
        dfs(root, s);
        return ans;
    }
};