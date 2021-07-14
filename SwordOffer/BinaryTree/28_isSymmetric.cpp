// 2-9
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        if (root == NULL)
            return true;
        return isSymmetric(root->left, root->right);
    }
    bool isSymmetric(TreeNode* left, TreeNode* right) {
        if (left == NULL && right == NULL)
            return true;
        if (left == NULL && right != NULL)
            return false;
        if (left != NULL && right == NULL)
            return false;
        return left->val == right->val && isSymmetric(left->right, right->left) && isSymmetric(left->left, right->right);
    }
};
// 一次通过了 可以啊

// 27 28 对比着看

// 3-17
// class Solution {
//     public boolean isSymmetric(TreeNode root) {
//         if (root == null)
//             return true;
//         return isSymmetric(root.left, root.right);
//     }
//     public boolean isSymmetric(TreeNode left, TreeNode right) {
//         if (left == null && right == null)
//             return true;
//         if (left == null || right == null)
//             return false;
//         return left.val == right.val && isSymmetric(left.left, right.right) && isSymmetric(left.right, right.left);
//     }
// }
 