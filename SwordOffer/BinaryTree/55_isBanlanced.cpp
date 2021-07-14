#include <iostream>
using namespace std;
// 5-4
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution {
public:
    bool ans = true;
    bool isBalanced(TreeNode* root) {
        getHeight(root);
        return ans;
    }
    int getHeight(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = getHeight(root->left);
        int right = getHeight(root->right);
        if (abs(left - right) > 1)
            ans = false;
        return max(left, right) + 1;
    }
};