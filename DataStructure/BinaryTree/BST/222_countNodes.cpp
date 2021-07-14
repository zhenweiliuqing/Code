// 4-27
#include <iostream>
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
    int countNodes(TreeNode* root) {
        if (root == nullptr)
            return 0;
        
        int leftdepth = 1, rightdepth = 1;
        TreeNode *left = root->left, *right = root->right;
        while (left != nullptr) {
            leftdepth++;
            left = left->left;
        }
        while (right != nullptr) {
            rightdepth++;
            right = right->right;
        }
        if (leftdepth == rightdepth)
            return pow(2, leftdepth) - 1;
        
        int leftnodes = countNodes(root->left);
        int rightnodes = countNodes(root->right);
        return leftnodes + rightnodes  +1;
    }
};
