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
    // Encodes a tree to a single string.
    string seria_helper(TreeNode* root, string& str) {
        if (root == NULL) {
            str += "#,"; // 多个逗号应该无所谓  最后反序列化时会去掉逗号
            return str;
        }
        seria_helper(root->left, str);
        seria_helper(root->right, str);
        str += to_string(root->val);
        str += ",";
        return str;
    }
    
    string serialize(TreeNode* root) {
        string str = "";
        seria_helper(root, str);
        str.pop_back();
        return str;
    }

    TreeNode* deseria_helper(string str) {

    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        
    }
};
