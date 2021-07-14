// 3-11
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 左 根 右
// 首先还是把左子树一路推进去 
// 然后弹出top 进行访问 然后切换到右子节点
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (!s.empty() || cur != NULL) {
            // 切换到右子树就不用担心这里会重复push了
            while (cur != NULL) {
                s.emplace(cur);
                cur = cur->left;
            }
            // 这里只是把root的值给赋了一下 左右子树都是空
            // TreeNode* cur = s.top(); 为什么切换不到右子树了呢 这是重新声明了一下？ 到上边cur是NULL了 这里虽然是正常的 但是出了循环作用域就消失了   
            cur = s.top();
            s.pop();
            ans.emplace_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};
// 通过！ 和先序遍历是差不多的

class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> ans;
        if (root == NULL)
            return ans;

        stack<TreeNode *> s;
        TreeNode *cur = root;
        while (!s.empty() || cur != NULL) {
            while (cur != NULL) {
                s.emplace(cur);
                cur = cur->left;
            }
            // 这里如果重新定义cur 也没有报错 会发生什么？
            // TreeNode* cur = s.top(); 
            cur = s.top();
            s.pop();
            ans.emplace_back(cur->val);
            cur = cur->right;
        }
        return ans;
    }
};