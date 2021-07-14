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
    // rob的定义就是在当前节点能抢到的最大值 
    // 当前这个节点可以抢 也可以不抢
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

// 4-30
// 这种思路跟122股票无限次交易很像
// dp[0] 不选择这家最大值
// dp[1] 选择这家最大值
class Solution {
public:
    int rob(TreeNode* root) {
        vector<int> dp = dfs(root);
        return max(dp[0], dp[1]);
    }

    vector<int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        vector<int> left = dfs(root->left);
        vector<int> right = dfs(root->right);
        
        vector<int> dp(2);
        // 不选择当前这家 那我就从左右里选个大的加起来
        dp[0] = max(left[0], left[1]) + max(right[0], right[1]);
        // 选择当前这家 左右就只能不抢了
        dp[1] = root->val + left[0] + right[0];
        return dp;
    }
};
// 通过了

// 还可以用其他的数据结构 struct pair
class Solution {
public:
    struct status {
        int y, n;
    };
    int rob(TreeNode* root) {
        status ans = dfs(root);
        return max(ans.y, ans.n);
    }

    status dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        status left = dfs(root->left);
        status right = dfs(root->right);
        
        status ans;
        ans.n = max(left.n, left.y) + max(right.n, right.y);
        ans.y = root->val + left.n + right.n;
        return ans;
    }
};
// 这个好快啊

class Solution {
public:
    int rob(TreeNode* root) {
        pair<int, int> ans = dfs(root);
        return max(ans.first, ans.second);
    }

    pair<int, int> dfs(TreeNode* root) {
        if (root == nullptr)
            return {0, 0};
        pair<int, int> left = dfs(root->left);
        pair<int, int> right = dfs(root->right);
        
        pair<int, int> ans;
        ans.first = max(left.first, left.second) + max(right.first, right.second);
        ans.second = root->val + left.first + right.first;
        return ans;
    }
};
// 这个没有struct快