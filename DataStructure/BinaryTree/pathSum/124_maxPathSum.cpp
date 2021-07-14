// 4-16
#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 一次遍历 这个跟110判断平衡树很像
class Solution {
public:
    int ans = INT_MIN;
    int maxSingleside(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxSingleside(root->left);
        int right = maxSingleside(root->right);

        // 在这里到达每个结点的时候 更新一下最大值
        ans = max(ans, root->val + left + right);

        int maxValue = root->val + max(left, right);
        return maxValue > 0 ? maxValue : 0;
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        maxSingleside(root);
        return ans;
    }
};
// 通过了 时间效率高了一点点


class Solution {
public:
    int ans = INT_MIN;
    int maxSingleside(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxSingleside(root->left);
        int right = maxSingleside(root->right);
        int maxValue = root->val + max(left, right);
        return maxValue > 0 ? maxValue : 0;
    }
    int maxPathSum(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = maxSingleside(root->left);
        int right = maxSingleside(root->right);
        ans = max(ans, root->val + left + right);
        if (root->left != NULL)
            ans = max(ans, maxPathSum(root->left));
        if (root->right != NULL)
            ans = max(ans, maxPathSum(root->right));
        return ans;
    }
};
// 通过了 效率很低 最好一次遍历
// 判断是否为平衡二叉树也需要每个节点遍历一次


