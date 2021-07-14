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

// 4-30
// 就是在求最大深度的基础上 在每个节点做了一个判断 
// 跟110很像 这个不是求pathsum 就是求一下路径的长度
class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == nullptr)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        ans = max(ans, left + right);
        return max(left, right) + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};

// 应该就是计算每一个节点的左子树和右子树的深度
class Solution {
public:
    int ans = 0;
    int dfs(TreeNode* root) {
        if (root == NULL)
            return 0;
        int left = dfs(root->left);
        int right = dfs(root->right);
        if (ans < left + right)
            ans = left + right;
        return left > right ? left + 1 : right + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        dfs(root);
        return ans;
    }
};
// 这道题挺简单的 就是自己基础感觉太差了

class Solution {
public:
    int dfs(TreeNode* root, int& ans) {
        if (root == NULL)
            return 0;
        int left = dfs(root->left, ans);
        int right = dfs(root->right, ans);
        if (ans < left + right)
            ans = left + right;
        return left > right ? left + 1 : right + 1;
    }

    int diameterOfBinaryTree(TreeNode* root) {
        int ans = 0;
        dfs(root, ans);
        return ans;
    }
};
// 也是可以的

class Solution {
    int ans;
    int depth(TreeNode* root){
        if (root == NULL) return 0;
        int L = depth(root->left);
        int R = depth(root->right);
        ans = max(ans, L + R + 1);
        return max(L, R) + 1;
    }
public:
    int diameterOfBinaryTree(TreeNode* root) {
        ans = 1;
        depth(root);
        return ans - 1;
    }
};
