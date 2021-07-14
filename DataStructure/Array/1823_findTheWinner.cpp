#include <vector>
#include <iostream>
#include <list>
#include <forward_list>
using namespace std;

// 6-11
// 这不就是约瑟夫环 先用一下list双向链表模拟一下
class Solution {
public:
    int findTheWinner(int n, int k) {
        list<int> l;
        for (int i = 0; i < n; i++)
            l.push_back(i + 1);
        auto cur = l.begin();
        while (l.size() != 1) {
            int tmp = k;
            while (--tmp) {
                cur++;
                if (cur == l.end())
                    cur = l.begin();
            }
            auto t = cur;
            cur++;
            if (cur == l.end())
                cur = l.begin();
            l.erase(t);
        }
        return *cur;
    }
};
// list不会自动循环到头啊 这是双向链表 不是循环链表