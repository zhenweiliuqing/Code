// 4-25
#include <iostream>
#include <vector>
using namespace std;

//   Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// 用归并排序比较好弄
class Solution {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        ListNode* slow = head;
        ListNode* fast = head->next; // 让slow停在靠前的位置
        // slow停在中间或靠后位置上不行 如果是两个数会卡死 得停在靠前的位置上
        while (fast != nullptr && fast->next != nullptr) {
            slow = slow->next;
            fast = fast->next->next;
        }

        ListNode* mid = slow->next;
        slow->next = nullptr;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(mid);
        
        ListNode* dummy = new ListNode(0);
        ListNode* cur = dummy;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                cur->next = l1;
                l1 = l1->next;
            } else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }

        if (l1 != nullptr)
            cur->next = l1;
        else if (l2 != nullptr)
            cur->next = l2;
        return dummy->next;
    }
};
// 通过了

// 不让值交换
class Solution2 {
public:
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr)
            return head;
        int pivot = head->val;
        ListNode *leftdummy = new ListNode(-1), *rightdummy = new ListNode(-1);
        ListNode *left = leftdummy, *right = rightdummy;
        // 这里得是head->next 不然[1,2]这种会死循环
        ListNode *cur = head->next;
        while (cur != nullptr) {
            if (cur->val < pivot) {
                left->next = cur;
                left = left->next;
            } else {
                right->next = cur;
                right = right->next;
            }
            cur = cur->next;
        }
        left->next = nullptr;
        right->next = nullptr;

        left = sortList(leftdummy->next);
        right = sortList(rightdummy->next);

        if (left == nullptr) {
            head->next = right;
            return head;
        }
        cur = left;
        while (cur->next != nullptr)
            cur = cur->next;
        cur->next = head;
        head->next = right;
        return left;
    }
};
// 在有序的时候超时了

int main() {
    Solution2 sol;
    ListNode *a = new ListNode(4);
    ListNode *b = new ListNode(2);
    ListNode *c = new ListNode(1);
    ListNode *d = new ListNode(3);
    a->next = b;
    b->next = c;
    c->next = d;
    sol.sortList(a);
}