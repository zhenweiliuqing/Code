// 2-20
#include <iostream>
#include <stack>
using namespace std;

// 有一个辅助栈 当最小时就push进去
class MinStack {
public:
    /** initialize your data structure here. */
    stack<int> s, h;
    int minnum = INT_MAX;
    MinStack() {

    }
    
    void push(int x) {
        s.push(x);
        if (h.empty() || x < h.top())
            h.push(x);
        else
            h.push(h.top());
    }
    
    void pop() {
        s.pop();
        h.pop();
    }
    
    int top() {
        return s.top();
    }
    
    int min() {
        return h.top();
    }
};
// 一次通过了 
