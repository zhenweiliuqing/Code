#include <iostream>
#include <vector>
#include <queue>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 4-27
// 这个也是得遍历 关键是如何处理遍历结果
// 这个函数本身有好几种情况
// 1. root是祖先 那就最后返回root
// 2. root不是祖先 返回nullptr
// 3. root是其中一个节点 返回那个节点
class Solution {
public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        // 到了nullptr 返回nullptr
        if (root == nullptr)
            return nullptr;

        // 假如找到了其中一个值 就返回这个root
        if (root->val == p->val || root->val == q->val)
            return root;

        // 遍历左右子树
        TreeNode* left = lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        
        if (left == nullptr)
            return right;
        if (right == nullptr)
            return left;
        return root;
    }
};
// 通过了

class Solution {
public:
    TreeNode* ans;
    bool dfs(TreeNode* root, TreeNode* p, TreeNode* q) {
        if (root == NULL)
            return false;
        bool lson = dfs(root->left, p, q);
        bool rson = dfs(root->right, p, q);
        // 两个孩子均为真 || 一个孩子为真 自己等于其中一个值
        if ((lson && rson) || ((root->val == p->val || root->val == q->val) && (lson || rson))) {
            ans = root;
        }
        // 如果自己的值等于p q任意一个的话 返回true
        return lson || rson || (root->val == p->val || root->val == q->val);
    }

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root, p, q);
        return ans;
    }
};
