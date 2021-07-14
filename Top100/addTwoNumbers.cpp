#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 这种方法会超过int范围
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode *ret = new ListNode(-1);
        int a = 0, b = 0;
        int i = 0;
        while (l1 != NULL) {
            a += l1->val * pow(10, i);
            l1 = l1->next;
            i++;
        }
        i = 0;
        while (l2 != NULL) {
            b += l2->val * pow(10, i);
            l2 = l2->next;
            i++;
        }
        int c = a + b;
        ListNode *head = ret;
        // ret->val = c % 10; // 这里为什么报错？？
        while (c != 0) {
            ListNode *next = new ListNode(c % 10);
            head->next = next;
            head = next;
            c /= 10;
        }
        return ret->next;
    }
};

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
        int carry = 0;
        int x, y, s;
        ListNode *ans = new ListNode(0);
        ListNode *head = ans;
        while (l1 != NULL || l2 != NULL) {
            if (l1 != NULL) {
                x = l1->val;
                l1 = l1->next;
            }
            else
                x = 0;
            if (l2 != NULL) {
                y = l2->val;
                l2 = l2->next;
            }
            else
                y = 0;
            
            s = x + y + carry;
            head->next = new ListNode(s % 10);
            head = head->next;
            carry = s / 10;
        }
        if (carry == 1)
            head->next = new ListNode(1);
        return ans->next;
    }
};
// 通过了 感觉也不是很难 主要就是每一位的相加 然后记得进位就可以

