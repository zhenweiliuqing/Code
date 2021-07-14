#include <iostream>
#include <vector>
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

// 4-26
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool left2right = true;
        while (!q.empty()) {
            int n = q.size();
            deque<int> dq;
            for (int i = 0; i < n; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (left2right)
                    dq.push_back(tmp->val);
                else 
                    dq.push_front(tmp->val);
                if (tmp->left != nullptr)
                    q.push(tmp->left);
                if (tmp->right != nullptr)
                    q.push(tmp->right);
            }
            left2right = !left2right;
            ans.push_back(vector<int>(dq.begin(), dq.end()));
        }
        return ans;
    }
};
// 通过了