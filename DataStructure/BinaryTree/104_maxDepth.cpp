#include <iostream>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 3-29
class Solution {
public:
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        return max(maxDepth(root->left), maxDepth(root->right)) + 1;
    }
};

class Solution {
public:
    int ret = 1;
    void dfs(TreeNode* root, int depth) {
        if (root == NULL)
            return;
        if (ret < depth)
            ret = depth;
        dfs(root->left, depth + 1);
        dfs(root->right, depth + 1);
    }
    int maxDepth(TreeNode* root) {
        if (root == NULL)
            return 0;
        dfs(root, 1);
        return ret;
    }
};

// 官方给的一种思路 自顶向下
int answer;		       // don't forget to initialize answer before call maximum_depth
void maximum_depth(TreeNode* root, int depth) {
    if (!root) {
        return;
    }
    if (!root->left && !root->right) { // 如果均为NULL 这个好 只用到最后才判断一下
        answer = max(answer, depth);
    }
    maximum_depth(root->left, depth + 1);
    maximum_depth(root->right, depth + 1);
}

// 自下向上
int maximum_depth(TreeNode* root) { 
	if (!root) {
		return 0;                                 // return 0 for null node
	}
	int left_depth = maximum_depth(root->left);
	int right_depth = maximum_depth(root->right);
	return max(left_depth, right_depth) + 1;	  // return depth of the subtree rooted at root
}