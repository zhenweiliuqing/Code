#include <iostream>
#include <stack>
using namespace std;

class MyQueue {
public:
    stack<int> s1, s2; 
    /** Initialize your data structure here. */
    MyQueue() {
               
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        s1.push(x);
        stack<int> temp = s1;
        while (!s2.empty())
            s2.pop();
        while (!temp.empty()) {
            int top = temp.top();
            s2.push(top);
            temp.pop();
        }
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int res = s2.top();
        s2.pop();
        stack<int> temp = s2;
        while (!s1.empty())
            s1.pop();
        while (!temp.empty()) {
            int top = temp.top();
            s1.push(top);
            temp.pop();
        }
        return res;
    }
    
    /** Get the front element. */
    int peek() {
        return s2.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return s1.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */