#include <iostream>
#include <queue>
using namespace std;

class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    MyStack() {

    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        queue<int> temp;
        while (q1.size() > 1) { // 注意这是动态的 不能用固定的思维
            int front = q1.front();
            temp.push(front);
            q1.pop();
        }
        int res = q1.front();
        q1.pop();
        q1 = temp;
        return res;
    }
    
    /** Get the top element. */
    int top() {
        queue<int> temp = q1;
        while (!temp.empty()) {
            if (temp.size() == 1)
                return temp.front();
            temp.pop();
        }
        return 0;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */