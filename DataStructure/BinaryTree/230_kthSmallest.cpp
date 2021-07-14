// 2020-11-22
#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <stack>
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

// 4-27 用迭代的方法可以提前退出
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        stack<TreeNode*> s;
        TreeNode* cur = root;
        int ans;
        while (!s.empty() || cur != nullptr) {
            while (cur != nullptr) {
                s.push(cur);
                cur = cur->left;
            }
            cur = s.top();
            s.pop();
            k--;
            if (k == 0) {
                ans = cur->val;
                break;
            }
            cur = cur->right;
        }
        return ans;
    }
};

// 中序遍历就得到有顺序的数组了
class Solution {
public:
    vector<int> ans;
    void helper(TreeNode* root) {
        if (root == NULL)
            return;
        helper(root->left);
        ans.push_back(root->val);
        helper(root->right);
    }

    int kthSmallest(TreeNode* root, int k) {
        helper(root);
        return ans[k - 1];
    }
};
// 通过了

// 剪枝
class Solution {
public:
    int cnt = 0, ans;
    void inorder(TreeNode* root, int k) {
        if (root == NULL || cnt > k)
            return;
        inorder(root->left, k);
        cnt++;
        if (cnt == k)
            ans = root->val;
        inorder(root->right, k);
    }
    int kthSmallest(TreeNode* root, int k) {
        inorder(root, k);
        return ans;
    }
};
