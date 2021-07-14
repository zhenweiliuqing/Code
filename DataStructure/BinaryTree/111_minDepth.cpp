// 4-16
#include <iostream>
#include <algorithm>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 深度优先遍历
// 还是用这个把 这个简单些
class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = minDepth(root->left);
        int right = minDepth(root->right);
        if (left == 0)
            return right + 1;
        else if (right == 0)
            return left + 1;
        return min(left, right) + 1;
    }
};
// 通过了

class Solution {
public:
    int minDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (root->left == NULL && root->right == NULL)
            return 1;

        int left = 0, right = 0;
        if (root->left != NULL)
            left = minDepth(root->left);
        if (root->right != NULL)
            right = minDepth(root->right);

        if (left == 0)
            return right + 1;
        else if (right == 0)
            return left + 1;
        return min(left, right) + 1;
    }
};
// 通过了 