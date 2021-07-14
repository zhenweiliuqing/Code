#include <iostream>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 6-5
class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* pre = dummy;
        ListNode* cur = dummy->next;
        while (cur != nullptr) {
            if (cur->val == val) {
                pre->next = cur->next;
            } else {
                pre = pre->next;
            }
            cur = cur->next;
        }
        return dummy->next;
    }
};
// 通过了