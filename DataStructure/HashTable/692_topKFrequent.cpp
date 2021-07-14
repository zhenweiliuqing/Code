#include <iostream>
#include <unordered_map>
#include <vector>
#include <algorithm>
using namespace std;

// 5-20
// 又遇到需要对map的value排序的问题了
// 这种方法是先统计 统计完之后 push进vector进行排序
class Solution {
public:
    unordered_map<string, int> mmap;
    static bool cmp(const pair<string, int>& a, const pair<string, int>& b) {
        return a.second == b.second ? a.first < b.first : a.second > b.second;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (auto it : words) {
            mmap[it]++;
        }
        vector<pair<string, int>> sortWords;
        for (auto it : mmap) {
            // emplace这样做会出错
            // sortWords.emplace_back({it.first, it.second});
            sortWords.push_back({it.first, it.second});
        }
        sort(sortWords.begin(), sortWords.end(), cmp);
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.emplace_back(sortWords[i].first);
        }
        return ans;
    }
};
// 通过了 


class Solution {
public:
    unordered_map<string, pair<int, int>> mmap;
    struct node {
        string s;
        int cnt;
        int id;
    };
    // 搞错了 是按照string顺序排序
    bool cmp(const node& a, const node& b) {
        return a.cnt == b.cnt ? a.id < b.id : a.cnt > b.cnt;
    }
    vector<string> topKFrequent(vector<string>& words, int k) {
        for (int i = words.size() - 1; i >= 0; i--) {
            mmap[words[i]].first++;
            mmap[words[i]].second = i;
        }
        vector<node> sortWords;
        for (auto it : mmap) {
            // node tmp;
            // tmp.s = it.first;
            // tmp.cnt = it.second.first;
            // tmp.id = it.second.second;
            // sortWords.emplace_back(tmp);
            sortWords.push_back({it.first, it.second.first, it.second.second});
        }
        sort(sortWords.begin(), sortWords.end(), cmp);
        vector<string> ans;
        for (int i = 0; i < k; i++) {
            ans.emplace_back(sortWords[i].s);
        }
        return ans;
    }
};
