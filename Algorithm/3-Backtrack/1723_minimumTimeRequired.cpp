#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 首先得会暴力写法 
// 1. 每一步有几个选择 这里每一步代表一个任务 选择就是k个工人
// 2. 一共有多少步 总的步数就是任务的总数

// 5-13
// 树还是那棵树，但是搜索调整分配优先级后，我们可以在首次取得一个「较好」的答案，来增强我们的 max >= ans 剪枝效益。
// 第一次的ans比累加到一个人上变得小很多 累加到一个人身上是最差的答案
class Solution {
public:
    int ans = INT_MAX;
    vector<int> g_jobs;
    int n, K;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        g_jobs = jobs;
        n = jobs.size();
        K = k;
        vector<int> worktime(k);
        backtrack(worktime, 0, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& worktime, int maxworktime, int jobid, int id) {
        if (maxworktime >= ans)
            return;
        if (jobid == n) {
            ans = maxworktime;
            return;
        }
        if (id < K) {
            worktime[id] += g_jobs[jobid];
            backtrack(worktime, max(worktime[id], maxworktime), jobid + 1, id + 1);
            worktime[id] -= g_jobs[jobid];
        }

        for (int i = 0; i < id; i++) {
            worktime[i] += g_jobs[jobid];
            backtrack(worktime, max(worktime[i], maxworktime), jobid + 1, id);
            worktime[i] -= g_jobs[jobid];
        }
    }
};
// 通过了

// 这个还是符合自己的思路 关键就是开始搞到一个比较好的ans 后边就会剪枝好多
class Solution {
public:
    int ans = INT_MAX;

    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> worktime(k);
        backtrack(jobs, worktime, 0, k, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& jobs, vector<int>& worktime, int maxworktime, int k, int jobid, int id) {
        if (maxworktime > ans)
            return;
        if (jobid == jobs.size()) {
            ans = min(ans, maxworktime);
            return;
        }
        if (id < k) {
            worktime[id] += jobs[jobid];
            backtrack(jobs, worktime, max(worktime[id], maxworktime), k, jobid + 1, id + 1);
            worktime[id] -= jobs[jobid];
        }
        // 不能是k k的话就没用了 k改为id就通过了
        for (int i = 0; i < k; i++) {
            worktime[i] += jobs[jobid];
            backtrack(jobs, worktime, max(worktime[i], maxworktime), k, jobid + 1, id);
            worktime[i] -= jobs[jobid];
        }
    }
};
// 16/60 超时了
// k改为id就通过了


class Solution {
public:
    int ans = INT_MAX;
    int minimumTimeRequired(vector<int>& jobs, int k) {
        vector<int> worktime(k);
        backtrack(jobs, worktime, k, 0);
        return ans;
    }

    void backtrack(vector<int>& jobs, vector<int>& worktime, int k, int idx) {
        if (*max_element(worktime.begin(), worktime.end()) >= ans)
            return;
        if (idx == jobs.size()) {
            if (ans > *max_element(worktime.begin(), worktime.end()))
                ans = *max_element(worktime.begin(), worktime.end());
            return;
        }
        // 有k个工人 则每个任务有k个选择
        for (int i = 0; i < k; i++) {
            worktime[i] += jobs[idx];
            backtrack(jobs, worktime, k, idx + 1);
            worktime[i] -= jobs[idx];
        }
    }
};
// 42/60 至少先把这种给写出来
