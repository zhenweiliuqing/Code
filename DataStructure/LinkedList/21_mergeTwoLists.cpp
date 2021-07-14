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
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode();
        ListNode* head = pre; // 有这么赋值的吗
        ListNode* temp1; 
        ListNode* temp2; // 这俩还得分开定义？
        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                temp1 = l1;
                l1 = l1->next;
                temp1->next = NULL;
                head->next = temp1;
            } else {
                temp2 = l2;
                l2 = l2->next;
                temp2->next = NULL;
                head->next = temp2;
            }
            head = head->next; // 这等于null了还能连上吗 
        }
        if (l1 == NULL)
            head->next = l2; 
        if (l2 == NULL)
            head->next = l1;
        return pre;
    }
};
// 回过头来看当时写的代码 真的是基础薄弱啊

// 迭代的方法我基本会了 递归的方法还是可以思考一下
class Solution1 {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        ListNode* pre = new ListNode();
        ListNode* head = pre; // 有这么赋值的吗

        while (l1 != NULL && l2 != NULL) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next; // 这等于null了还能连上吗 
        }
        if (l1 == NULL)
            head->next = l2; 
        if (l2 == NULL)
            head->next = l1;
        return pre->next;
    }
}; //这样一点也不影响 