#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 思路还是不是很清晰
// root这个节点要做什么 不要往脑子里压栈
// 剩下的交给递归
class Solution {
public:
    map<TreeNode *, int> memo;

    int rob(TreeNode* root) {
        if (root == NULL)
            return 0;
        if (memo.count(root) != 0)
            return memo[root];
        
        // 爷爷的钱 + 4个孙子的钱
        // 抢 再去抢下下家
        int rob_root = root->val +\
            (root->left == NULL ? 0 : rob(root->left->left) + rob(root->left->right))+\
            (root->right == NULL ? 0 : rob(root->right->left) + rob(root->right->right));

        // 2个儿子的钱
        int not_rob_root = rob(root->left) + rob(root->right);
        memo[root] = max(rob_root, not_rob_root);
        return max(rob_root, not_rob_root);
    }
};
// 通过了 抄的
// 好好理解一下

