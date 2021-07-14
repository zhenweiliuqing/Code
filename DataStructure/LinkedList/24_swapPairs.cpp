#include <iostream>
#include <vector>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};


// 这个思路应该是跟反转链表差不多
class Solution {
public:
    ListNode* reverseLinkList(ListNode* head) {
        ListNode* pre = NULL;
        ListNode* next;
        while (head) {
            next = head->next;
            head->next = pre;
            pre = head;
            head = next;
        }
        head = pre;
        return head;
    }
};

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode* pre = NULL;
        ListNode* temp = head;
        ListNode* next = temp->next;
        head = head->next;
        // 这样就可以解决奇数个的问题了
        while (temp && next) {
            temp->next = next->next;
            next->next = temp;
            if (pre != NULL)
                pre->next = next;
            pre = temp;
            temp = temp->next;
            if (temp != NULL)
                next = temp->next;
        }
        return head;
    }
};
// 通过！！！

class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == NULL || head->next == NULL)
            return head;
        ListNode *next = head->next;
        head->next = swapPairs(next->next);
        next->next = head;
        return next;
    }
};
// 一次通过