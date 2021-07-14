// 1-31
#include <iostream>
#include <vector>
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
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return buildATree(preorder, inorder, 0, preorder.size() - 1, 0, inorder.size() - 1);
    }
    TreeNode* buildATree(vector<int>& preorder, vector<int>& inorder, int pStart, int pEnd, int iStart, int iEnd) {
        if (pStart > pEnd)
            return NULL;
        TreeNode *tree = new TreeNode(preorder[pStart]);
        int iRoot;
        for (int i = iStart; i <= iEnd; i++) {
            if (preorder[pStart] == inorder[i]) {
                iRoot = i;
                break;
            }
        }
        int leftLen = iRoot - iStart;
        tree->left = buildATree(preorder, inorder, pStart + 1, pStart + leftLen, iStart, iRoot - 1);
        tree->right = buildATree(preorder, inorder, pStart + leftLen + 1, pEnd, iRoot + 1, iEnd);
        return tree;
    }
};
// 通过了 可以的