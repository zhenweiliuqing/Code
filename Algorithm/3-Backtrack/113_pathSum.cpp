#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 一条路径最后两个叶子是NULL 所有会有一个结果重复
class Solution {
public:
    vector<vector<int>> ans;
    void dfs(TreeNode* root, int target, int sum, vector<int> path) {
        path.push_back(root->val);
        sum += root->val;

        if (root->left == NULL && root->right == NULL) {
            if (sum == target)
                ans.push_back(path);
            return;
        }

        // path.push_back(root->val);
        if (root->left != NULL)
            dfs(root->left, target, sum, path);
        if (root->right != NULL)
            dfs(root->right, target, sum, path);
    }

    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return ans;
        vector<int> path;
        dfs(root, sum, 0, path);
        return ans;
    }
};
// 通过了 就是不太优雅

class Solution {
public:
    vector<vector<int>> ret;
    vector<int> path;

    void dfs(TreeNode* root, int sum) {
        if (root == NULL)
            return;
        path.emplace_back(root->val);
        sum -= root->val;

        if (root->left == NULL && root->right == NULL && sum == 0)
            ret.emplace_back(path);

        dfs(root->left, sum);
        dfs(root->right, sum);
        path.pop_back(); // 这个不能省 因为是全局
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        dfs(root, sum);
        return ret;
    }
}; 

// 3-20
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return ans;
        vector<int> tmp;
        backtrack(root, targetSum, tmp, 0);
        return ans;
    }
    void backtrack(TreeNode* root, int targetSum, vector<int> tmp, int tmpSum) {
        tmpSum += root->val;
        tmp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (tmpSum == targetSum)
                ans.push_back(tmp);
            return;
        }

        // 本来进backtrack是要做选择 出backtrack要撤销选择 
        // 但是这里root->left 和 root->right的选择是一样的就不用撤销了
        // 至于最后right出来之后直接函数就结束了 也不用撤销了
        if (root->left != NULL)
            backtrack(root->left, targetSum, tmp, tmpSum);    
        if (root->right != NULL)
            backtrack(root->right, targetSum, tmp, tmpSum);
    }
};