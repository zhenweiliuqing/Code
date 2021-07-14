// 2-14
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
 
// 思路：其实就是回溯
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(TreeNode* root, int sum, vector<int> tmp, int tmpSum) {
        tmp.push_back(root->val);
        tmpSum += root->val;
        
        if (root->left == NULL && root->right == NULL) {
            if (tmpSum == sum)
                ans.push_back(tmp);
            return;
        }
        
        if (root->left != NULL)
            backtrack(root->left, sum, tmp, tmpSum);
        if (root->right != NULL)
            backtrack(root->right, sum, tmp, tmpSum);
        tmpSum -= root->val;
        tmp.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int sum) {
        if (root == NULL)
            return ans;
        vector<int> tmp;
        backtrack(root, sum, tmp, 0);
        return ans;
    }
};
// 通过了
