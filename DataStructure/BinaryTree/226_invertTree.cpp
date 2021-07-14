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