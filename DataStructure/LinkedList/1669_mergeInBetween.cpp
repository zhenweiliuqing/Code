// 3-24
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeInBetween(ListNode* list1, int a, int b, ListNode* list2) {
        ListNode* list2head = list2, *list2tail = list2;
        while (list2tail->next != NULL)
            list2tail = list2tail->next;

        ListNode* pre = list1, *cur = list1->next;
        int len = b - a + 1; // 删除节点数
        while (a > 1) {
            cur = cur->next;
            pre = pre->next;
            a--;
        }

        while (len > 0) {
            cur = cur->next;
            len--;
        }

        pre->next = list2head;
        list2tail->next = cur;
        return list1;
    }
};
// 一次通过