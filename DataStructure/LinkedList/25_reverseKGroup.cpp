// 3-8
//  Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};
 
class Solution {
public:
    ListNode* successor;
    ListNode* reverseK(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        if (k == 1) {
            successor = head->next;
            return head;
        }
        ListNode* newhead = reverseK(head->next, k - 1);
        head->next->next = head;
        head->next = successor;
        return newhead;
    }    
    ListNode* reverseKGroup(ListNode* head, int k) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* cur = head;
        for (int i = 0; i < k; i++) {
            if (cur == NULL)
                return head;
            cur = cur->next;
        }

        ListNode* newhead = reverseK(head, k);
        head->next = reverseKGroup(cur, k);
        return newhead;
    }
};
