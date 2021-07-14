// 3-11
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


vector<int> preorderTraversal(TreeNode* root) {
    vector<int> ans;
    if (root == NULL)
        return ans;
    
    stack<TreeNode *> s;
    TreeNode *cur = root;
    while (!s.empty() || cur != NULL) {
        while (cur != NULL) {
            ans.emplace_back(cur->val);
            s.emplace(cur);
            cur = cur->left;
        }
        cur = s.top();
        s.pop();
        cur = cur->right;
    }
    return ans;
}

// 迭代算法 我怎么没想到用stack呢
class Solution {
public:
    // 先序遍历 根 左 右
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> ret;
        stack<TreeNode*> s;
        s.push(root);
        while (!s.empty()) {
            TreeNode* temp = s.top();
            s.pop();
            if (temp != NULL) {
                ret.push_back(temp->val); // 这个位置放哪无所谓
                s.push(temp->right);
                s.push(temp->left);
            }
        }
        return ret;
    }
};