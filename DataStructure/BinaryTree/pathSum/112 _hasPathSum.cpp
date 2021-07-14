#include <iostream>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    bool ans = false; // 这里设置个全局变量跟110是否为平衡树很像
    void dfs(TreeNode* root, int targetSum, int sum) {
        if (root == NULL)
            return;
        sum += root->val;
        if (targetSum == sum && root->left == NULL && root->right == NULL)
            ans = true;
        dfs(root->left, targetSum, sum);
        dfs(root->right, targetSum, sum);
    }

    bool hasPathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return false;
        dfs(root, targetSum, 0);
        return ans;
    }
};
// 通过了 这个跟路径和很像

class Solution {
public:
    bool flag = false;
    void calPathSum(TreeNode* root, int sum, int res) {
        // if (root == NULL) // 这个如果有另一个子树怎么办
        //     flag = true; // 一直都不满足 怎么办 return false 写在哪？
        
        res += root->val;
        if (res == sum && root->left == NULL && root->right == NULL) // 保证为子节点
            flag = true;
        if (root->left != NULL)
            calPathSum(root->left, sum ,res);
        if (root->right != NULL)
            calPathSum(root->right, sum ,res);
    }
    bool hasPathSum(TreeNode* root, int sum) {
        int res = 0;
        if (root == NULL)
            return false;
        calPathSum(root, sum, res);
        return flag;
    }
}; // 通过 可以的！