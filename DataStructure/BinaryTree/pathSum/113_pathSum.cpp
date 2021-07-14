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

// 4-23 统一模板
class Solution {
public:
    vector<vector<int>> ans;

    void dfs(TreeNode* root, int targetSum, vector<int> tmp, int tmpSum) {
        if (root == nullptr)
            return;

        tmpSum += root->val;
        tmp.push_back(root->val);
        if (tmpSum == targetSum && root->left == NULL && root->right == NULL) {
            ans.push_back(tmp);
            return;
        }

        dfs(root->left, targetSum, tmp, tmpSum);    
        dfs(root->right, targetSum, tmp, tmpSum);
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return ans;
        vector<int> tmp;
        dfs(root, targetSum, tmp, 0);
        return ans;
    }
};
// 通过


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

        if (root->left != NULL)
            backtrack(root->left, targetSum, tmp, tmpSum);    
        if (root->right != NULL)
            backtrack(root->right, targetSum, tmp, tmpSum);
    }
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
 
// 另一种经典回溯的解法 
class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        if (root == NULL)
            return ans;
        vector<int> tmp;
        tmp.push_back(root->val);
        backtrack(root, targetSum, tmp, root->val);
        return ans;
    }
    void backtrack(TreeNode* root, int targetSum, vector<int>& tmp, int tmpSum) {
        // tmpSum += root->val;
        // tmp.push_back(root->val);
        if (root->left == NULL && root->right == NULL) {
            if (tmpSum == targetSum)
                ans.push_back(tmp);
            return;
        }

        if (root->left != NULL) {
            tmp.push_back(root->left->val);
            backtrack(root->left, targetSum, tmp, tmpSum + root->left->val);    
            tmp.pop_back();
        }
        if (root->right != NULL) {
            tmp.push_back(root->right->val);
            backtrack(root->right, targetSum, tmp, tmpSum + root->right->val);
            tmp.pop_back();
        }
    }
};


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

