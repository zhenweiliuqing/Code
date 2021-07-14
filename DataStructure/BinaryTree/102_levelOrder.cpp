#include <iostream>
#include <vector>
#include <queue>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};
// 可以把上一级的pop出去 只留下这一级的数据
// 层序遍历 BFS 迭代
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) { 
        vector<vector<int>> ret;
        if (root == NULL)
            return ret;
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size(); // 关键就是一层一清空 就不用考虑满二叉树那种花里胡哨的操作了
            vector<int> data;
            for (int i = 0; i < size; i++) {
                TreeNode* temp = q.front();
                q.pop();
                data.push_back(temp->val);
                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);    
            }
            ret.push_back(data);
        }
        return ret;
    }
}; // 通过了 可以的