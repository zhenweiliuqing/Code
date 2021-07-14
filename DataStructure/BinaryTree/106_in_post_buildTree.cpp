#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    TreeNode* helper(const vector<int>& inorder, const vector<int>& postorder, int in_st, int in_end, int post_st, int post_end) {
        if (post_st > post_end)
            return nullptr;
        // if (in_st > in_end)
        //   return nullptr; 都是可以的
        TreeNode *root = new TreeNode(postorder[post_end]);
        int idx = in_st;
        for (int i = in_st; i <= in_end; i++) {
            if (postorder[post_end] == inorder[i]) {
                idx = i;
                break;
            }
        }

        int leftlength = idx - in_st;
        root->left = helper(inorder, postorder, in_st, idx - 1, post_st, post_st + leftlength - 1);
        root->right = helper(inorder, postorder, idx + 1, in_end, post_st + leftlength, post_end - 1);
        return root;
    }

    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        return helper(inorder, postorder, 0, inorder.size() - 1, 0, postorder.size() - 1);
    }
};

int main() {
    Solution s;
    // vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    vector<int> post = {9, 15, 7, 20, 3};
    s.buildTree(in, post);
}