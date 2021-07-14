#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;

// 首先得会暴力写法 
// 1. 每一步有几个选择 这里每一步代表一个任务 选择就是k个工人
// 2. 一共有多少步 总的步数就是任务的总数

// 另外一种思路
// 设置一个limit 然后按照这个limit 从大到小给所有工人分配任务 
// 如果不超过limit 优先给第一个工人分配 当他超过了之后 再给后来的工人分配

class Solution {
public:
    bool backtrack(const vector<int>& jobs, vector<int>& worktime, int k, int limit, int id) {
        if (id == jobs.size())
            return true;
        for (int i = 0; i < k; i++) {
            if (worktime[i] + jobs[id] <= limit) {
                worktime[i] += jobs[id];
                if(backtrack(jobs, worktime, k, limit, id + 1))
                    return true;
                worktime[i] -= jobs[id];
            }
            // 注意 如果worktime[i] = 0 说明分配了一圈 最后失败了 这里避免的是分配给下一个工人还是同样的情况
            // 所以直接跳出就好了 前一个工人分配失败 后面肯定也不成功
            if (worktime[i] == 0)
                break;
            // 单独这个过不去
            // if (worktime[i] + jobs[id] == limit)
                // break;
            // 解答错误 53/60 这个第一次分配失败就全失败了 不会再调整
            // if (worktime[i] + jobs[id] <= limit)
            //     break;
        }
        return false;
    }

    bool isValid(vector<int>& jobs, int k, int limit) {
        vector<int> worktime(k);
        return backtrack(jobs, worktime, k, limit, 0);
    }
    int minimumTimeRequired(vector<int>& jobs, int k) {
        sort(jobs.begin(), jobs.end(), greater<int>());
        int left = jobs[0], right = accumulate(jobs.begin(), jobs.end(), 0);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(jobs, k,  mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> v = {6518448, 8819833, 7991995, 7454298, 2087579, 380625, 4031400, 2905811, 4901241, 8480231, 7750692, 3544254};
    sol.minimumTimeRequired(v, 4);
}
// 不优化 会超出时间限制
// 加上worktime[i] == 0 就通过了

// [6518448,8819833,7991995,7454298,2087579,380625,4031400,2905811,4901241,8480231,7750692,3544254]
// 4
// 16274131