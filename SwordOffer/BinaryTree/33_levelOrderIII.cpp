// 2-18
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode *> q;
        q.push(root);
        q.push(NULL);
        while (q.front() != NULL) {
            vector<int> tmp;
            while (q.front() != NULL) {
                TreeNode *tmpRoot = q.front();
                q.pop();
                tmp.push_back(tmpRoot->val);
                if (tmpRoot->left != NULL)
                    q.push(tmpRoot->left);
                if (tmpRoot->right != NULL)
                    q.push(tmpRoot->right);
            }
            ans.push_back(tmp);
            q.pop();
            q.push(NULL);
        }
        // 最后加上一个转换的操作
        for (int i = 0; i < ans.size(); i++) {
            if (i % 2 == 1)
                reverse(ans[i].begin(), ans[i].end());
        }
        return ans;
    }
};
// 通过了

// 3-17
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == NULL)
            return ans;
        queue<TreeNode*> q;
        q.push(root);
        bool isleft = true;
        while (!q.empty()) {
            int s = q.size();
            deque<int> dq;
            for (int i = 0; i < s; i++) {
                TreeNode* node = q.front();
                q.pop();
                if (isleft)
                    dq.push_back(node->val);
                else 
                    dq.push_front(node->val);
                if (node->left != NULL)
                    q.push(node->left);
                if (node->right != NULL)
                    q.push(node->right);
                    
            }
            ans.push_back(vector<int>(dq.begin(), dq.end()));
            isleft = !isleft;
        }
        return ans;
    }
};