#include <iostream>
#include <vector>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 看了提示 就是用两个指针 两个指针保持n的距离
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode *fast = head;
        ListNode *slow = new ListNode(0);
        slow->next = head;
        while (fast != NULL) {
            fast = fast->next;
            if (n != 0)
                n--;
            else
                slow = slow->next;
        }
        // slow就是要删掉的那个节点
        if (slow->next == head)
            return head->next;
        else 
            slow->next = slow->next->next;
        return head;
    }
};
// 通过了 
