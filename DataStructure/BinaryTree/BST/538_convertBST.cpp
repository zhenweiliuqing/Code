#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 从最大的值开始遍历累加 右子树 根 左子树
class Solution {
public:
    int sum = 0;
    void helper(TreeNode* root) {
        if (root == NULL)
            return;
        helper(root->right);
        sum += root->val;
        root->val = sum;
        helper(root->left);
    }
    TreeNode* convertBST(TreeNode* root) {
        helper(root);
        return root;
    }
};
// 通过了