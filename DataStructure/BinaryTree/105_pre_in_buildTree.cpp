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

// 4-27
class Solution {
public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder, int prestart, int preend, int instart, int inend) {
        if (prestart > preend)
            return nullptr;
        int rootval = preorder[prestart];
        TreeNode* root = new TreeNode(rootval);
        int inroot = instart;
        for (int i = instart; i <= inend; i++) {
            if (inorder[i] == rootval) {
                inroot = i;
                break;
            }
        }

        int len = inroot - instart;
        root->left = buildTree(preorder, inorder, prestart + 1, prestart + len, instart, inroot - 1);
        root->right = buildTree(preorder, inorder, prestart + len + 1, preend, inroot + 1, inend);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildTree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};

class Solution {
public:
    TreeNode* helper(const vector<int>& preorder, const vector<int>& inorder, int pre_st, int pre_end, int in_st, int in_end) {
        if (pre_st > pre_end)
            return nullptr;
        TreeNode *root = new TreeNode(preorder[pre_st]);
        int idx = in_st;
        // 找到中序root的下标
        for (int i = in_st; i <= in_end; i++) {
            if (preorder[pre_st] == inorder[i]) {
                idx = i;
                break;
            }
        }
        // idx是inorder的下标 idx - st就不对 所以必须要有inordr的下标
        // root->left = helper(preorder, inorder, st + 1, idx); st + idx - st
        // root->right = helper(preorder, inorder, idx + 1, end); st + idx - st + 1
        int leftlength = idx - in_st;
        root->left = helper(preorder, inorder, pre_st + 1, pre_st + leftlength, in_st, idx - 1);
        root->right = helper(preorder, inorder, pre_st + leftlength + 1, pre_end, idx + 1, in_end);
        return root;
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return helper(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
};
// 这个通过了 

int main() {
    Solution s;
    vector<int> pre = {3, 9, 20, 15, 7};
    vector<int> in = {9, 3, 15, 20, 7};
    s.buildTree(pre, in);
}