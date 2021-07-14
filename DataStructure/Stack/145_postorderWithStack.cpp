// 二叉树的后序遍历 非递归
// 官方题解
// 3-11
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
    stack<TreeNode *> s;
    TreeNode *pre = NULL;
    while (root != NULL || !s.empty()) {
        while (root != NULL) {
            s.emplace(root);
            root = root->left;
        }
        root = s.top();
        s.pop();
        
        if (root->right == NULL || root->right == pre) {
            ans.emplace_back(root->val);
            pre = root;
            root = NULL;
        } else {
            s.emplace(root);
            root = root->right;
        }
    }
    return ans;
}


vector<int> postorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
 
    stack<TreeNode *> s;
    TreeNode *pre = NULL, *cur = root;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            s.emplace(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();

        // 没有右子树 或者 右子树已经访问过 最后遍历根节点
        if (cur->right == NULL || cur->right == pre) {
            ans.emplace_back(cur->val);
            pre = cur;
            cur = NULL;
        } else { // 否则就切换到右子树
            s.emplace(cur);
            cur = cur->right;
        }
    }
    return ans;
}
