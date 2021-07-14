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

class Solution {
public:
    TreeNode* searchBST(TreeNode* root, int val) {
        if (root == NULL)
            return root;
        if (root->val == val)
            return root;
        else if (root->val > val)
            root = searchBST(root->left, val);
        else if (root->val < val)
            root = searchBST(root->right, val);
        return root;
    }
};
// 这就完了？