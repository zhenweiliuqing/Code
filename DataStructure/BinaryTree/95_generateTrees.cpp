#include <iostream>
#include <vector>
#include <unordered_map>
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

// 4-23
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int start, int end) {
        if (start > end) {
            return {nullptr};
        }
        
        vector<TreeNode*> tmp;
        for (int i = start; i <= end; i++) {
            vector<TreeNode*> left = generateTrees(start, i - 1);
            vector<TreeNode*> right = generateTrees(i + 1, end);

            for (auto l : left) {
                for (auto r : right) {
                    TreeNode* root = new TreeNode(i);
                    root->left = l;
                    root->right = r;
                    tmp.push_back(root);
                }
            }
        }
        return tmp;
    }
};
// 通过了

// 3-29
class Solution {
public:
    vector<TreeNode*> generateTrees(int n) {
        if (n == 0)
            return {NULL};
        return generateTrees(1, n);
    }
    vector<TreeNode*> generateTrees(int start, int end) {
        vector<TreeNode*> tmp;
        if (start > end) {
            tmp.push_back(NULL);
            return tmp;
        }

        for (int i = start; i <= end; i++) {
            // 递归的妙处 就在于这里 这个函数的功能就是生成二叉搜索树 把左右的树生成完了 再与节点i进行组合即可
            vector<TreeNode*> leftTrees = generateTrees(start, i - 1);
            vector<TreeNode*> rightTrees = generateTrees(i + 1, end);
            // TreeNode* root = new TreeNode(i); 不能在外边 因为会被覆盖掉 地址是相同的
            for (auto left : leftTrees) {
                for (auto right : rightTrees) {
                    TreeNode* root = new TreeNode(i); // 要生成一个新的树
                    root->left = left;
                    root->right = right;
                    tmp.push_back(root);
                }
            }
        }
        return tmp;
    }
};
// 通过了

int main() {
    Solution sol;
    sol.generateTrees(3);
    return 0;
}


