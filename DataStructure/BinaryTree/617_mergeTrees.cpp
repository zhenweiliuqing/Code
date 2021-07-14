#include <iostream>
#include <queue>
#include <vector>
#include <string>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 4-30
// 可以更简洁一些
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr)
            return t2;
        if (t2 == nullptr)
            return t1;
        TreeNode* tree = new TreeNode(t1->val + t2->val);
        tree->left = mergeTrees(t1->left, t2->left);
        tree->right = mergeTrees(t1->right, t2->right);
        return tree;
    }
};

// 思路就是遍历
class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        TreeNode *tree = new TreeNode(0);
        if (t1 != NULL && t2 != NULL) {
            tree->val = t1->val + t2->val;
            tree->left = mergeTrees(t1->left, t2->left);
            tree->right = mergeTrees(t1->right, t2->right);
        }
        else if (t1 != NULL && t2 == NULL) {
            tree->val = t1->val;
            tree->left = mergeTrees(t1->left, NULL);
            tree->right = mergeTrees(t1->right, NULL);
        }
        else if (t1 == NULL && t2 != NULL) {
            tree->val = t2->val;
            tree->left = mergeTrees(NULL, t2->left);
            tree->right = mergeTrees(NULL, t2->right);
        }
        else
            return NULL;
        
        return tree;
    }
};
// 通过了 确实挺简单的 就是 t1 == NULL 的时候就没有 left 和 right了

class Solution {
public:
    TreeNode* mergeTrees(TreeNode* t1, TreeNode* t2) {
        if (t1 == nullptr) // 妙啊
            return t2;
        if (t2 == nullptr)
            return t1;
        auto merged = new TreeNode(t1->val + t2->val);
        merged->left = mergeTrees(t1->left, t2->left);
        merged->right = mergeTrees(t1->right, t2->right);
        return merged;
    }
}
// 这个和递归合并有序链表有点像

int main() {
    TreeNode *x = new TreeNode(2);
    TreeNode *y = new TreeNode(1);
    x->left = y;
    Solution a;
    TreeNode *tree = a.mergeTrees(x, y);
}



