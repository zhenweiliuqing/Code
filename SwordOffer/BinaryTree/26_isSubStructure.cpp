#include <iostream>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 5-4
// 双递归
class Solution {
public:
    // 遍历A这棵树 进行一一对比
    bool isSubStructure(TreeNode* A, TreeNode* B) {
        if (A == nullptr || B == nullptr)
            return false;
        if (TreeAhasTreeB(A, B))
            return true;
        return isSubStructure(A->left, B) || isSubStructure(A->right, B);
    }
    // 遍历B这棵树 与A的节点值进行一一对比
    bool TreeAhasTreeB(TreeNode* A, TreeNode* B) {
        if (B == nullptr)
            return true;
        if (A == nullptr)
            return false;
        if (A->val != B->val)
            return false;
        return TreeAhasTreeB(A->left, B->left) && TreeAhasTreeB(A->right, B->right);
    }
};
