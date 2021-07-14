// 2-21
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

// 思路：判断入栈顺序能不能按照出栈顺序被弹出
// push一个进去就用while对poped顺序做一个判断 如果不能pop 就push
// 测试用例
// 1 2 3 4 5 
// 3 2 4 1 5 / 3 1 2 4 5
class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        // 把pushed的元素一个个push进去
        int m = pushed.size(), n = popped.size();
        int k = 0;
        stack<int> s;
        for (int i = 0; i < m; i++) {
            s.push(pushed[i]);
            while (!s.empty() && k < n && s.top() == popped[k]) {
                s.pop();
                k++;
            }
        }
        return s.empty();
    }
};
// 一次通过 可以的