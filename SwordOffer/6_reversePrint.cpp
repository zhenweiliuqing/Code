// 1-29
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 测试用例:
// 1.null
class Solution {
public:
    vector<int> reversePrint(ListNode* head) {
        vector<int> v;
        stack<int> s;
        ListNode *node = head;
        while (node != NULL) {
            s.push(node->val);
            node = node->next;
        }
        while (!s.empty()) {
            v.push_back(s.top());
            s.pop();
        }
        return v;
    }
};
// 通过了
