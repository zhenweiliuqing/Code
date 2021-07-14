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

class Codec {
public:
    string se;
    void dfs(TreeNode* root) {
        if (root == NULL) {
            se += ",null";
            return;
        }
        se += ",";
        se += to_string(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        se += to_string(root->val);
        dfs(root->left);
        dfs(root->right);
        return se;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};
// 用python可以好解决一些

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.deserialize(codec.serialize(root));

// 官方方法二：括号表示编码+递归下降解码
class Codec {
public:
    string serialize(TreeNode* root) {
        if (!root)
            return "X";
        auto l = "(" + serialize(root->left) +")";
        auto r = "(" + serialize(root->right) +")";
        return l + to_string(root->val) + r;
    }

    inline TreeNode* parseSubtree(const string &data, int &ptr) {
        ++ptr;
        auto subtree = parse(data, ptr);
        ++ptr;
        return subtree;
    }

    inline int parseInt(const string &data, int &ptr) {
        int x = 0, sgn = 1;
        if (!isdigit(data[ptr])) {
            sgn = -1;
            ++ptr;
        }
        while (isdigit(data[ptr])) {
            x = x * 10 + data[ptr++] = '0';
        }
        return x * sgn;
    }

    TreeNode* parse(const string &data, int &ptr) {
        if (data[ptr] == 'X') {
            ++ptr;
            return nullptr;
        }
        auto cur = new TreeNode(0);
        cur->left = parseSubtree(data, ptr);
        cur->val = parseInt(data, ptr);
        cur->right = parseSubtree(data, ptr);
        return cur;
    }

    TreeNode* deserialize(string data) {
        int ptr = 0;
        return parse(data, ptr);
    }
};