// 2-6
#include <iostream>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

// 原题是给一个节点让你删除 并且需要在O(1)的时间内
// 思路是将next节点的内容覆盖到当前节点 然后删除next节点
// 需要注意的是头节点和尾节点 尾节点需要从头遍历
class Solution {
public:
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode *pNode = head;
        // 这里没有考虑head = NULL
        if (head == NULL)
            return head;
        // 删除的是头节点 不需要delete
        if (head->val == val)
            return head->next;

        // 删除的不是头节点
        ListNode *pPre = NULL;
        while (pNode != NULL && pNode->val != val) {
            pPre = pNode;
            pNode = pNode->next;
        }
        // 没找到 这个不需要也可以? 
        // 题目中没有给找不到的情况
        if (pNode == NULL)
            return head;
        pPre->next = pNode->next;
        return head;
    }
};
// 一次通过了 可以的

// 拓展: 删除重复节点
// 思路: 
// 测试用例:
// 1 2 2 3 4
// 1
// 1 2 2 3 3 4
// 2 2 3 4 5
// 自己思路有点乱 
ListNode* deleteDuplicateNode(ListNode* head) {
    if (head == NULL)
        return head;

    
    // 先找到重复的节点 不在头节点
    ListNode *pPre = NULL;
    ListNode *pNode = head;
    ListNode *pNext = pNode->next;
    while (pNode != NULL && pNext != NULL) {
        // 找到重复的节点
        while (pNext != NULL && pNode->val != pNext->val) {
            pPre = pNode;
            pNode = pNext;
            pNext = pNext->next;
        }
        if (pNext != NULL) {
            pNode = pNext->next;
            if (pNode != NULL)
                pNext = pNode->next;
            pPre->next = pNode;
        }
    }
    return head;
}

// 参考解法
ListNode* deleteDuplicateNode(ListNode* head) {
    if (head == NULL)
        return head;
    
    ListNode *pPre = NULL;
    ListNode *pNode = head;
    while (pNode != NULL) {
        ListNode *pNext = pNode->next;
        bool needDelete = false;
        // 头需要删除
        if (pNext != NULL && pNext->val == pNode->val)
            needDelete = true;
        
        if (!needDelete) {
            pPre = pNode;
            pNode = pNode->next;
        } else {
            int value = pNode->val;
            ListNode *pToDel = pNode;
            while (pToDel != NULL && pToDel->val == value) {
                pNext = pToDel->next;
                pToDel = pNext;
            }
            if (pPre == NULL)
                head = pNext;
            else
                pPre->next = pNext;
            pNode = pNext;
        }
    }
}
