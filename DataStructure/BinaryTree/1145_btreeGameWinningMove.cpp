#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 关键是思路 
// 当玩家一选择了一个结点之后 玩家二有三种选择
// 1. 选择左子树 > 一半节点 直接获胜
// 2. 选择右子树 > 一半节点 直接获胜
// 3. 选择其他节点 看玩家一一共有多少 玩家一大于一半 玩家一获胜 否则就是玩家二获胜

// 实施过程中 有两块 
// 找到玩家一的节点 统计节点的数量
class Solution {
public:
    TreeNode* rootX;
    void dfs(TreeNode* root, int x) {
        if (root == nullptr)
            return;
        if (root->val == x) {
            rootX = root;
            return;
        }
        dfs(root->left, x);
        dfs(root->right, x);
    }

    // 这个如果是完全二叉树怎么做
    // int getnodeNum(TreeNode* root) {
    //     if (root == nullptr)
    //         return 0;
    //     TreeNode* left = root;
    //     TreeNode* right = root;
    //     int leftdepth = 0, rightdepth = 0;
    //     while (left != nullptr) {
    //         left = left->left;
    //         leftdepth++;
    //     }
    //     while (right != nullptr) {
    //         right = right->right;
    //         rightdepth++;
    //     }
    //     if (leftdepth == rightdepth)
    //         return pow(2, leftdepth) - 1;
    //     return getnodeNum(root->left) + getnodeNum(root->right) + 1;
    // }

    int getnodeNum(TreeNode* root) {
        if (root == nullptr)
            return 0;
        return getnodeNum(root->left) + getnodeNum(root->right) + 1;
    }

    bool btreeGameWinningMove(TreeNode* root, int n, int x) {
        dfs(root, x);
        int left = getnodeNum(rootX->left);
        int right = getnodeNum(rootX->right);
        if (left > (n / 2) || right > (n / 2))
            return true;
        if ((left + right + 1) > (n / 2))
            return false;
        return true;
    }
};
// 通过了