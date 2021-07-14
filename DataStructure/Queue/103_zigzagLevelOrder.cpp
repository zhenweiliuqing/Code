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

// 抄leetcode
// 这个就是最简洁的方案
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;

        queue<TreeNode *> q;
        q.push(root);
        bool left2right = true;
        while (!q.empty()) {
            int size = q.size();
            deque<int> dq;
            for (int i = 0; i < size; i++) {
                TreeNode *tmp = q.front();
                q.pop();
                if (!left2right)
                    dq.push_front(tmp->val);
                else
                    dq.push_back(tmp->val);
                if (tmp->left != NULL)
                    q.push(tmp->left);
                if (tmp->right != NULL)
                    q.push(tmp->right);
            }
            ans.emplace_back(vector<int>(dq.begin(), dq.end()));
            left2right = !left2right;
        }
        return ans;
    }
};
// 一次通过


// 3-16 写的乱七八糟的
class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        deque<TreeNode*> dq;
        dq.push_back(root);
        bool isleft = false;
        while (!dq.empty()) {
            vector<int> tmp = vector<int>(dq.begin(), dq.end());
            ans.push_back(tmp);
            int n = dq.size();
            for (int i = 0; i < n; i++) {
                TreeNode* tmp = dq.front();
                dq.pop_back();
                if (!isleft) {
                    if (tmp->left != NULL)
                        dq.push_back(tmp->left); 
                    if (tmp->right != NULL)
                        dq.push_back(tmp->right); 
                } else {
                    if (tmp->right != NULL)
                        dq.push_front(tmp->right); 
                    if (tmp->left != NULL)
                        dq.push_front(tmp->left); 
                }
                isleft = !isleft;
            }
        }
        return ans;
    }
};