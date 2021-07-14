#include <iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};
 
class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        if (head->next == NULL)
            return head;
        ListNode* newhead = reverseList(head->next);
        head->next->next = head;
        head->next = NULL;
        return newhead;
    }

    bool isPalindrome(ListNode* head) {
        if (head == NULL)
            return true;
        ListNode *rList = reverseList(head);
        while (head != NULL) {
            if (head->val != rList->val)
                return false;
            head = head->next;
            rList = rList->next;
        }
        return true;
    }
};

int main() {
    Solution A;
    ListNode *head = new ListNode(1);
    head->next = new ListNode(1);
    head->next->next = new ListNode(2);
    head->next->next->next = new ListNode(1);
    A.isPalindrome(head);
}