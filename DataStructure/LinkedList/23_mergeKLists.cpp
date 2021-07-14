// 4-25
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    static bool cmp(ListNode* a, ListNode* b) {
        return a->val > b->val;
    }

    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* dummy = new ListNode(0);
        if (lists.size() == 0)
            return nullptr;
        priority_queue<ListNode*, vector<ListNode*>, decltype(&cmp)> q(cmp);
        for (auto list : lists) {
            if (list != nullptr)
                q.push(list);
        }

        ListNode* cur = dummy;
        while (!q.empty()) {
            ListNode* tmp = q.top();
            q.pop();
            cur->next = tmp;
            cur = cur->next;
            if (tmp->next != nullptr)
                q.push(tmp->next);
        }
        return dummy->next;
    }
};