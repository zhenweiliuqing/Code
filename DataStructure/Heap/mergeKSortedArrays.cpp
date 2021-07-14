// 4-24
#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct node {
    int val, row, col;
};

// 大于号 升序 最小堆 第一个是最小值
static bool cmp(node a, node b) {
    return a.val > b.val;
}

vector<int> mergekSortedArrays(vector<vector<int>> &arrays) {
    vector<int> ans;
    if (arrays.size() == 0 || arrays[0].size() == 0)
        return ans;
    priority_queue<node, vector<node>, decltype(&cmp)> q(cmp);
    for (int i = 0; i < arrays.size(); i++) {
        q.emplace(node{arrays[i][0], i, 0});
    }

    while (!q.empty()) {
        node tmp = q.top();
        q.pop();
        ans.push_back(tmp.val);
        if (tmp.col + 1 < arrays[tmp.row].size())
            q.emplace(node{arrays[tmp.row][tmp.col + 1], tmp.row, tmp.col + 1});
    }
    return ans;
}
// 通过