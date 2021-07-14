#include <iostream>
#include <vector>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
 
class Solution {
public:
    void dfs(TreeNode* root, TreeNode* ans) {
        if (root == NULL)
            return;
        if (ans->left == NULL && root->right != NULL)
            ans->left = new TreeNode(0);
        if (ans->right == NULL && root->left != NULL)
            ans->right = new TreeNode(0);
        ans->val = root->val;
        dfs(root->left, ans->right);
        dfs(root->right, ans->left);
    }
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return root;
        TreeNode *ans = new TreeNode(0);
        dfs(root, ans);
        return ans;
    }
};// 通过

// void dfs(TreeNode* root, int[] list) {
//     if (root == NULL)
//         root = 
// }

// int main() {
//     Solution A;
//     int list[] = {4, 2, 7};
//     TreeNode *root = new TreeNode(4);
//     dfs(root, list)
// }

class Answer {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        
        TreeNode *left = invertTree(root->left);
        TreeNode *right = invertTree(root->right);
        
        root->left = right;
        root->right = left;
        
        return root;
    }
};
// 递归思想 自下而上

// labuladong 自上而下
// 搞清楚每个节点该做什么 
class Answer {
public:
    TreeNode* invertTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        
        TreeNode *temp = root->left;
        root->left = root->right;
        root->right = temp;

        invertTree(root->left);
        invertTree(root->right);
        
        return root;
    }
};