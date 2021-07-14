// 填充每个节点的下一个右侧节点指针
// Definition for a Node.
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

// 4-27 用层序遍历不是更直观
class Solution {
public:
    Node* connect(Node* root) {
        if (root == nullptr)
            return nullptr;
        queue<Node*> q;
        q.push(root);
        q.push(nullptr);
        while (q.front() != nullptr) {
            Node* pre = q.front();
            q.pop();
            if (pre->left != nullptr)
                q.push(pre->left);
            if (pre->right != nullptr)
                q.push(pre->right);
            Node* cur = q.front();
            pre->next = cur;
            if (cur == nullptr) {
                q.pop();
                q.push(nullptr);
            }
        }
        return root;
    }
};

class Answer {
public:
    Node* connect(Node* root) {
        if (root == NULL) // 这个是个例外 不能丢
            return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()) {
            int size = q.size();
            Node* temp;
            for (int i = 0; i < size; i++) {
                temp = q.front();
                q.pop();
                if (i < size - 1) 
                    temp->next = q.front(); // 这竟然可以？？

                if (temp->left != NULL)
                    q.push(temp->left);
                if (temp->right != NULL)
                    q.push(temp->right);
            }
        }
        return root;        
    }
};

