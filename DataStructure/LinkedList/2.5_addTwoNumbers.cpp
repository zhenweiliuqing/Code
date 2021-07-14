// 3-16
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* head = new ListNode(0);
        ListNode* ans = head;
        int carry = 0;
        while (l1 != NULL && l2 != NULL) {
            int sum = l1->val + l2->val + carry;
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            l1 = l1->next;
            l2 = l2->next;
        }
        while (l1 != NULL) {
            int sum = l1->val + carry;
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            l1 = l1->next;
        }
        while (l2 != NULL) {
            int sum = l2->val + carry;
            carry = sum / 10;
            ans->next = new ListNode(sum % 10);
            ans = ans->next;
            l2 = l2->next;
        }
        if (carry == 1)
            ans->next =  new ListNode(1);
        return head->next;
    }
};
// 一次通过