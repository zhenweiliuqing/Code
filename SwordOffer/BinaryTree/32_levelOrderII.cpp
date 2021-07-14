// 2-18
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 这个是一行一行打印
// 两种方法 一种是在每一行后边加个null作为分隔
// 一种是用一个标志位 但是这个好像得用java 能把queue转为arraylist 记错了 没有标志位 就是得用queue.size()
// 还有一种是剑指Offer的方法

// 方法1 用null分隔 
// 之前的方法就是 q.size() 记住上一层的个数就可以了
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
        return ans;
    }
};
// 通过了 可以