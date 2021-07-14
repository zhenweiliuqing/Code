#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 4-22
// 这个还是每个点要遍历多次 能不能遍历一次 再遍历的过程中加一个条件
class Solution {
public:
    int ans = 0;
    void dfs(TreeNode* root, int targetSum, int sum) {
        if (root == NULL)
            return;
        sum += root->val;
        if (sum == targetSum)
            ans++;
        // 如果要是用sum + root->left->val的话 就得加一个判断条件保证root->left != NULL
        dfs(root->left, targetSum, sum); 
        dfs(root->right, targetSum, sum);
    }

    int pathSum(TreeNode* root, int targetSum) {
        if (root == nullptr)
            return 0;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            TreeNode* tmp = q.front();
            q.pop();
            dfs(tmp, targetSum, 0);
            if (tmp->left != NULL)
                q.push(tmp->left);
            if (tmp->right != NULL)
                q.push(tmp->right);
        }
        return ans;
    }
};

// 只想到了暴力解法
class Solution {
public:
    int cnt = 0;
    void helper(TreeNode* root, const int target, int s) {
        if (root == NULL)
            return;
        s += root->val;
        if (s == target)
            cnt++;
        helper(root->left, target, s);
        helper(root->right, target, s);
    }

    int pathSum(TreeNode* root, int sum) {
        queue<TreeNode *> q;
        q.push(root);
        while(!q.empty()) {
            TreeNode *temp = q.front();
            q.pop();
            int s = 0;
            helper(temp, sum, s);
            if (temp != NULL) {
                q.push(temp->left);
                q.push(temp->right);
            }
        }
        return cnt;
    }
};
// 通过了 
// 深度遍历 + 广度遍历