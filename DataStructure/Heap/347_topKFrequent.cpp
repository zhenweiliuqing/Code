// 3-18
#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <unordered_map>
#include <algorithm>
using namespace std;


// 关键是怎么写出一个cmp函数让堆能够自己调整
// 需要一个hashmap
// 思路：遍历数组 得到每个key的次数
// 先把前k个map的{key, value} push到最小堆中
// 最小堆要实现一个排序函数 按照value递增排序 从小到大排序
// 然后就是遍历map了 如果value > q.top() 就把原来的pop出去 新的push进来
// 最后最小堆内的就是答案了
 

// priority_queue <int, vector<int>, less<int>> max_heap; // 降序队列    用于得到最小的k个数    最大堆
// priority_queue<int, vector<int>, greater<int>> min_heap; // 升序队列  用于得到最大的k个数    最小堆
class Solution {
public:
    static bool cmp(pair<int, int> a, pair<int, int> b) {
        return a.second > b.second; //  greater是升序排列 >
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0 || k == 0)
            return ans;

        unordered_map<int, int> count;
        for (auto i : nums)
            count[i]++;

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp)> q(cmp);//注意最后括号里有个cmp
        for (auto it : count) {
            if (q.size() < k) {
                q.push(make_pair(it.first, it.second));
            } else {
                if (q.top().second < it.second) {
                    q.pop();
                    q.push(make_pair(it.first, it.second));
                }
            }
        }

        while (!q.empty()) {
            ans.push_back(q.top().first);
            q.pop();
        }
        return ans;
    }
};


// 一种奇思妙想
// map是按照key排序 但是我需要找到前k个value
// 所以就把value作为key再搞一次 就得到了原来按照vaule排序的key了
class Solution1 {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int> ans;
        if (nums.size() == 0 || k == 0)
            return ans;

        map<int, int> count;
        for (auto i : nums)
            count[i]++;

        // 这个问题就是出现次数相同的就会覆盖
        // 必须要保证key的唯一性
        map<int, int, greater<int>> key;
        for (auto it : count)
            key[it.second] = it.first;
        
        // 找到前k个
        for (auto it : key) {
            ans.push_back(it.second);
            if (ans.size() == k)
                break;
        }
        return ans;
    }
};

bool cmp(int a, int b) {
    return a > b;
}

int main() {
    vector<int> v = {2, 1, 5, 3, 0};
    sort(v.begin(), v.end(), cmp);
    return 0;
}