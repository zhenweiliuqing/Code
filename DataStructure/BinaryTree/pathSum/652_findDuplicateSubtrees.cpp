// 2020-11-21
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

// 这不就是pathsum的变体 只不过不是计算pathsum 还是遍历每个节点 然后做一些操作
class Solution {
public:
    map<string, int> mmap;
    vector<TreeNode *> ans;
    string getsubtree(TreeNode* root) {
        if (root == NULL)
            return "#";
        string left = getsubtree(root->left);
        string right = getsubtree(root->right);
        // string subtree = left + ',' + to_string(root->val) + ',' + right; [0,0,0,0,null,null,0,null,null,null,0] 通过不了 为什么呢？？
        string subtree = left + ',' +   right + ',' + to_string(root->val);
        mmap[subtree]++;
        if (mmap[subtree] == 2)
            ans.push_back(root);

        return subtree;
    }

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        // 遍历每一个节点找到子树
        getsubtree(root);
        return ans;
    }
};

int main() {
    Solution a;

}
