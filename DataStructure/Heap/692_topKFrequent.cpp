#include <iostream>
#include <unordered_map>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

// 5-20
// 又遇到需要对map的value排序的问题了
// 像这种需要前k大 前k小的问题肯定是可以用优先队列的
class Solution {
public:
    unordered_map<string, int> mmap;
    // 这种比较函数正好跟排序的比较函数是相反的 这种按排序是高频的在前边 按优先队列是最小的在前边
    // 排序 > 从大到小排  对于优先队列 > -> greater -> 升序 -> 从小到大 -> 最小堆
    static bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto it : words)
            mmap[it]++;
        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        for (auto it : mmap) {
            q.emplace(it);
            // q.emplace(make_pair(it.first, it.second));
            // q.emplace({it.first, it.second}); 这个有错
            // q.push({it.first, it.second});    
            if (q.size() > k) {
                q.pop(); // 每次是把最小的给pop出去 最后留下的就是前K大的
            }
        }
        vector<string> ans;
        while(!q.empty()) {
            ans.push_back(q.top().first);
            // ans.emplace(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// 这个编译会出错 得用匿名函数

class Solution {
public:
    unordered_map<string, int> mmap;
    // 这种比较函数正好跟排序的比较函数是相反的 这种按排序是高频的在前边 按优先队列是最小的在前边
    // 排序 > 从大到小排  对于优先队列 > -> greater -> 升序 -> 从小到大 -> 最小堆
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto it : words)
            mmap[it]++;
        auto cmp = [](const pair<string, int>& a, const pair<string, int>& b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        };

        priority_queue<pair<string, int>, vector<pair<string, int>>, decltype(cmp)> q(cmp);
        for (auto it : mmap) {
            q.emplace(it);
            // q.emplace(make_pair(it.first, it.second));
            // q.emplace({it.first, it.second}); 这个有错
            // q.push({it.first, it.second});    
            if (q.size() > k) {
                q.pop(); // 每次是把最小的给pop出去 最后留下的就是前K大的
            }
        }
        vector<string> ans;
        while(!q.empty()) {
            ans.push_back(q.top().first);
            // ans.emplace(q.top().first);
            q.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
// 通过了
