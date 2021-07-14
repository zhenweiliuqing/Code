#include <vector>
#include <queue>
using namespace std;

// 6-1
// 这是个模拟题
// 第j项任务可以在第j秒开始处理 
// 找权重最小的 空闲服务器 先遍历一遍吧 暴力解法

// 答案上是优先队列
// class Solution {
// public:
//     vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
//         int complete = 0, second = 0;
//         int n = tasks.size();
//         vector<bool> used(servers.size(), false);
//         while (complete < n) {
//             int id = -1;
//             for (int i = 0; i < servers.size(); i++) {
//                 if (!used[i]) {
//                     id = i;
//                     if (servers[i] < servers[id])
                    
//                 }
//             }
//             if (used[id])

//         }
//     }
// };


// 空闲队列里边是服务器的权重和下标 greater<pair<int, int>>是升序 从小到大
// pair<int, int>应该就是两个值依次从小到大
// 繁忙队列里边是服务器完成时间和下标 也是从小到大 最先完成的在前面

class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> off, on; 
        for (int i = 0; i < servers.size(); i++) {
            off.push({servers[i], i});
        }
        //标记最近结束时间
        int t = 0;
        vector<int> ans(tasks.size());
        // 第i秒第i个任务启动
        for (int i = 0; i < tasks.size(); i++) {
            // 把运行完毕的服务器加入到空闲队列中
            while (!on.empty() && on.top().first <= i) {
                int id = on.top().second;
                off.push({servers[id], id});
                on.pop();
            } 
            // 没有空闲服务器 找一个空闲的服务器
            if (off.empty()) {
                t = on.top().first; // on.top() 是最先完成的服务器 first是其完成的时间
                while(!on.empty() && on.top().first == t) {
                    int id = on.top().second;
                    off.push({servers[id], id}); // 这个服务器就空闲了 push到off里面
                    on.pop();
                }
            }
            t = max(t, i); // t就是开始时间 默认就是i 但是如果没有空闲队列 t就是运行的服务器最早结束的时间 
            on.push({t + tasks[i], off.top().second});
            ans[i] = off.top().second; // 记录分配的服务器id
            off.pop();
        }
        return ans;
    }
};

// 作者：Gosper
// 链接：https://leetcode-cn.com/problems/process-tasks-using-servers/solution/you-xian-dui-lie-by-gosper-kss1/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。