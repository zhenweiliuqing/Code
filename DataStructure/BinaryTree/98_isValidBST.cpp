#include <iostream>
#include <vector>
#include <algorithm>
#include <stack>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 中序遍历就可以了
class Solution {
public:
    bool isValidBST(TreeNode* root) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        long pre = LONG_MIN; // leetcode long是8位的
        // long long inorder = (long long)INT_MIN - 1;
        while (!s.empty() || cur != nullptr) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            if (cur->val <= pre)
                return false;
            pre = cur->val;
            cur = cur->right;
        }
        return true;
    }
};

// 每一个节点要进行个比较
class Solution1 {
public:
    bool helper(TreeNode* root, TreeNode* min, TreeNode* max) {
        if (root == NULL)
            return true;
        if (min != NULL && root->val <= min->val)
            return false;
        if (max != NULL && root->val >= max->val)
            return false;
        // 主要是这里
        // root->left 最小值就是root的最小值 最大值就是root本身
        return helper(root->left, min, root) && helper(root->right, root, max);
    }

    bool isValidBST(TreeNode* root) {
        if (root == NULL)
            return true;
        return helper(root, NULL, NULL);
    }
};
// 通过了 

int main() {
    Solution sol;
    TreeNode *tree = new TreeNode(INT_MIN);
    sol.isValidBST(tree);
    return 0;
}

