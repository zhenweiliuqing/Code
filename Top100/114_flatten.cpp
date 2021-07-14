// 11-16
#include <iostream>
#include <vector>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        flatten(root->left);
        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        // 这块得循环起来 得接到最后一个上去 怎么得到root->left的最后一个
        TreeNode *node = root->right;
        while (node->right != NULL)
            node = node->right;
        node->right = temp;
    }
};

class Solution {
public:
    void flatten(TreeNode* root) {
        if (root == NULL)
            return;
        flatten(root->right);
        if (root->left == NULL)
            return;
        flatten(root->left);

        TreeNode *temp = root->right;
        root->right = root->left;
        root->left = NULL;
        
        TreeNode *node = root->right;
        while (node->right != NULL)
            node = node->right;
        node->right = temp;
        
    }
};
// 通过了 可以啊

// labuladong
void flatten(TreeNode* root) {
    if (root == NULL)
        return;
    flatten(root->left);
    flatten(root->right);

    TreeNode *left = root->left;
    TreeNode *right = root->right;

    root->left = NULL;
    root->right = left;

    TreeNode *p = root; // 这就可以避免root->right是NULL的问题了
    while (p->right != NULL)
        p = p->right;
    p->right = right;
}