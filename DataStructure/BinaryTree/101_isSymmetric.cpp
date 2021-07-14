#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
#include <queue>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 4-23
// 和100一样 
class Solution {
public:
    bool isSymmetric(TreeNode* root) {
        return isSymmetric(root, root);
    }

    bool isSymmetric(TreeNode* left, TreeNode *right) {
        if (left == nullptr && right == nullptr)
            return true;
        else if (left == nullptr || right == nullptr)
            return false;
        if (left->val != right->val)
            return false;
        return isSymmetric(left->left, right->right) && isSymmetric(left->right, right->left);
    }
};

class Solution {
public:
    bool check(TreeNode* left, TreeNode* right) {
        queue<TreeNode*> q;
        q.push(left); q.push(right);
        TreeNode* u; TreeNode* v; // 这俩可以直接用 left  right
        while (!q.empty()) {
            u = q.front(); q.pop();
            v = q.front(); q.pop();
            if (!u && !v) // 均为空 说明对称 看下两个
                continue;
            if ((!u || !v) || (u->val != v->val)) // 有一个不为空 || 值不相等
                return false;
            
            q.push(u->left);
            q.push(v->right);

            q.push(u->right);
            q.push(v->left);
        }
        return true;
    }

    bool isSymmetric(TreeNode* root) {
        return check(root, root);
    }
};
// 通过 其实是记住答案了