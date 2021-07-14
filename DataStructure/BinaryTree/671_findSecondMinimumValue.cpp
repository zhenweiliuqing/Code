#include <iostream>
#include <queue>
#include <algorithm>
#include <vector>
using namespace std;
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 5-2 用最小堆的方式实现
class Solution {
public:
    // priority_queue<int, vector<int>, greater<int>> q;
    priority_queue<int> q; // 默认就是最大堆 可以求得最小的k个值
    bool isValid(int val) {
        vector<int> v;
        while (!q.empty()) {
            v.push_back(q.top());
            q.pop();
        }
        for (int i = 0; i < v.size(); i++)
            q.push(v[i]);
        if (find(v.begin(), v.end(), val) != v.end())
            return false;
        return true;
    }
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        // 关键是不能有重复的值 再加个isValid判断一下
        if (q.size() < 2 && isValid(root->val))
            q.push(root->val);
        else if (q.size() == 2) {
            if (root->val < q.top() && isValid(root->val)) {
                q.pop();
                q.push(root->val);
            }
        }
        dfs(root->left);
        dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        if (q.size() != 2)
            return -1;
        return q.top();
    }
};

// 5-2 用两个值记录最小和第二小 但是在第二小等于INT_MAX时过不去
class Solution {
public:
    int firstmin = INT_MAX, secondmin = INT_MAX;
    void dfs(TreeNode* root) {
        if (root == nullptr)
            return;
        if (root->val < firstmin) {
            secondmin = firstmin;
            firstmin = root->val;
        } else if (root->val < secondmin && root->val != firstmin) {
            secondmin = root->val;
        }
        dfs(root->left);
        dfs(root->right);
    }
    int findSecondMinimumValue(TreeNode* root) {
        dfs(root);
        return secondmin == INT_MAX ? -1 : secondmin;
    }
};
// 思路可以 37/39

// 参考答案 利用题目的信息
// 最小值肯定是root->val
// 这个跟寻找两个节点公共祖先很像
// dfs返回的是root中第二小的值 根节点是最小的值
// 1. 如果root->val > min 就返回
// 2. 寻找左右节点中第一个大于minV的值
// 3. 对返回的值进行一个处理
class Solution {
public:
    int dfs(TreeNode* root, int minV) {
        if (root == nullptr)
            return -1;
        if (root->val > minV)
            return root->val;
        int left = dfs(root->left, minV);
        int right = dfs(root->right, minV);
        if (left == -1)
            return right;
        if (right == -1)
            return left;
        return min(left, right);
    }

    int findSecondMinimumValue(TreeNode* root) {
        return dfs(root, root->val);
    }
};
