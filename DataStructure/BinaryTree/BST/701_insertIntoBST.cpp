#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 插入二叉树节点 没有涉及到调整的操作 就是在合适位置插入一个叶子节点就可以
class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        if (root == NULL)
            return new TreeNode(val);
        if (root->val < val)
            root->right = insertIntoBST(root->right, val);
        else if (root->val > val)
            root->left = insertIntoBST(root->left, val);
        return root;
    }
};
// 通过了