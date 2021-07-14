#include <iostream>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

// 5-4
class Solution {
public:
    Node *head = nullptr, *pre = nullptr;
    Node* treeToDoublyList(Node* root) {
        if (root == nullptr)
            return root;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    void dfs(Node* root) {
        if (root == nullptr)
            return;

        dfs(root->left);

        if (head == nullptr)
            head = root;
        root->left = pre;
        if (pre != nullptr)
            pre->right = root;
        pre = root;
        
        dfs(root->right);
        return;
    }
};
// 通过了