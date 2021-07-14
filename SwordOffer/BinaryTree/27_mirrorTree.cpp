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
    TreeNode* mirrorTree(TreeNode* root) {
        if (root == NULL)
            return NULL;
        if (root->left == NULL && root->right == NULL)
            return root;
        mirrorTree(root->left);
        mirrorTree(root->right);
        TreeNode* tmp = root->left;
        root->left = root->right;
        root->right = tmp;
        return root;
    }
};
// 通过了 和之前思路不一样 可以的

// 27 28 对比着看

// 3-17
// class Solution {
//     public TreeNode mirrorTree(TreeNode root) {
//         if (root == null)
//             return null;
//         if (root.left == null && root.right == null)
//             return root;

//         TreeNode tmp = root.left;
//         root.left = mirrorTree(root.right);
//         root.right = mirrorTree(tmp);

//         return root;
//     }
// }
