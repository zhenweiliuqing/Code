#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};


// 返回必须要赋值
class Dong {
public:
    TreeNode* getMax(TreeNode* root) {
        while(root->right != NULL)
            root = root->right;
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (root->val == key) {
            if (root->left == NULL)
                return root->right;
            else if (root->right == NULL)
                return root->left;

            // 左子树的最大值 就是root的前一个值
            // 把这个值赋给root 转而去删除左子树的最大值 是在叶子节点上 比较好弄
            TreeNode *max = getMax(root->left);
            root->val = max->val;
            root->left = deleteNode(root->left, max->val); 

        } else if (root->val > key) {
            root->left = deleteNode(root->left, key);
        } else if (root->val < key) {
            root->right = deleteNode(root->right, key);
        }
        return root;
    }
};
// 通过了 


class Solution {
public:
    int getMaxNode(TreeNode* root) {
        while(root->right != NULL)
            root = root->right;
        int val = root->val;
        if (root->left == NULL && root->right == NULL)
            root = NULL;
        else if (root->left != NULL && root->right == NULL)
            root = root->left;
        return val;
    }

    TreeNode* helper(TreeNode* root) {
        if (root->left == NULL && root->right == NULL)
            root = NULL;
        else if (root->left != NULL && root->right == NULL)
            root = root->left;
        else if (root->right == NULL && root->left != NULL)
            root = root->left;
        else {
            root->val = getMaxNode(root->left);
        }
        return root;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if (root == NULL)
            return root;
        if (root->val == key)
            root = helper(root);
        if (root->val > key)
            root->left = deleteNode(root->left, key); // 返回值还是必要的 虽然root->left本身改了 但是连接关系没有改
        else if (root->val < key)
            root->right = deleteNode(root->right, key);
        return root;
    }
};

TreeNode* helper(TreeNode* root) {
    root = new TreeNode(3);
    return root;
}

int main() {
    TreeNode *tree = new TreeNode(1);
    tree->left = new TreeNode(2);
    tree->left = helper(tree->left); // 返回值必须要
    // TreeNode* x = new TreeNode(3);
    // tree->left = x;
    return 0;
}
