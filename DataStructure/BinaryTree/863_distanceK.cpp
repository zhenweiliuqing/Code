#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

//  Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, TreeNode*> mmap;
    unordered_map<TreeNode*, bool> isVisited;
    void createHashMap(TreeNode* root) {
        if (root == nullptr)
            return;
        isVisited[root] = false;
        if (root->left != nullptr)
            mmap[root->left] = root;
        if (root->right != nullptr)
            mmap[root->right] = root;
        createHashMap(root->left);
        createHashMap(root->right);
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int K) {
        createHashMap(root);
        vector<int> ans;
        queue<TreeNode*> q;
        q.push(target);
        isVisited[target] = true;
        int level = 0;
        while (!q.empty()) {
            int n = q.size();
            if (level == K) {
                for (int i = 0; i < n; i++) {
                    TreeNode* tmp = q.front();
                    q.pop();
                    ans.push_back(tmp->val);
                }
                break;
            }
            for (int i = 0; i < n; i++) {
                TreeNode* tmp = q.front();
                q.pop();
                if (mmap.count(tmp) != 0 && !isVisited[mmap[tmp]]) {
                    q.push(mmap[tmp]);
                    isVisited[mmap[tmp]] = true;
                }
                if (tmp->left != nullptr && !isVisited[tmp->left]) {
                    q.push(tmp->left);
                    isVisited[tmp->left] = true;
                }
                if (tmp->right != nullptr && !isVisited[tmp->right]) {
                    q.push(tmp->right);
                    isVisited[tmp->right] = true;
                }
            }
            level++;
        }
        return ans;
    }
};