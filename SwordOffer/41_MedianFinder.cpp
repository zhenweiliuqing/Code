// 2-26
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

// 思路：需要用到一个最大堆和一个最小堆 并动态维护这两个数据结构 他们的数量不能相差1
// 剑指offer是用max_heap 这些操作实现最大堆和最小堆的
// 用优先队列是不是也能够实现
class MedianFinder {
public:
    /** initialize your data structure here. */
    // 最大堆左半部分 最小堆右半部分
    priority_queue<int, vector<int>, less<int>> max_heap; // 降序队列
    priority_queue<int, vector<int>, greater<int>> min_heap; // 升序队列
    MedianFinder() {

    }
    
    void addNum(int num) {
        int allSize = max_heap.size() + min_heap.size();
        if (allSize % 2 == 0) {
            // num如果大于最小堆的top 就要进入最小堆 同时把最小堆的top移到最大堆中
            if (min_heap.size() != 0 && num > min_heap.top()) {
                min_heap.push(num);
                num = min_heap.top();
                min_heap.pop();
            }
            max_heap.push(num);
        } else {
            if (max_heap.size() != 0 && num < max_heap.top()) {
                max_heap.push(num);
                num = max_heap.top();
                max_heap.pop();
            }
            min_heap.push(num);
        }
    }
    
    double findMedian() {
        int allSize = max_heap.size() + min_heap.size();
        double ans = 0.0;
        if (allSize == 0)
            return ans;

        if (allSize % 2 == 0) {
            ans = (max_heap.top() + min_heap.top()) / 2.0;
        } else {
            if (max_heap.size() > min_heap.size())
                ans = max_heap.top();
            else
                ans = min_heap.top();
        }
        return ans;
    }
};
// 通过了 可以的
