// 2-8
#include <iostream>
#include <stack>
using namespace std;
// 用两个栈实现队列
// 思路: 压入就压入第一个栈 当要弹出时把第一个栈中的数据压入第二个栈
// 第二个栈就是可以弹出的 弹完了再把第一个栈的内容弹进来
class CQueue {
public:
    stack<int> stack1, stack2;
    CQueue() {

    }
    
    void appendTail(int value) {
        stack1.push(value);
    }
    
    int deleteHead() {
        if (stack2.empty()) {
            while (!stack1.empty()) {
                stack2.push(stack1.top());
                stack1.pop();
            }
        }
        if (!stack2.empty()) {
            int ans = stack2.top();
            stack2.pop();
            return ans;
        }
        return -1;
    }
};
// 通过了

/**
 * Your CQueue object will be instantiated and called as such:
 * CQueue* obj = new CQueue();
 * obj->appendTail(value);
 * int param_2 = obj->deleteHead();
 */