// 3-25
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    // 最小堆 greater >
    static bool cmp1(pair<int, int> a, pair<int, int> b) {
        return a.first > b.first;
    }
    static bool cmp2(pair<int, int> a, pair<int, int> b) {
        return a.first < b.first;
    }
    int getNumberOfBacklogOrders(vector<vector<int>>& orders) {
        // 用两个最小堆来存一下结构体
        int m = orders.size();
        // priority_queue<pair<int, int>, vector<pair<int, int>>, less<pair<int, int>>> BuyQ;  //<价格, 数目>，最大堆
        // priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> SellQ

        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp1)> sell(cmp1);
        priority_queue<pair<int, int>, vector<pair<int, int>>, decltype(&cmp2)> buy(cmp2);

        for (int i = 0; i < m; i++) {
            if (orders[i][2] == 0) {
                while (true) {
                    if (sell.empty()) {
                        buy.push(make_pair(orders[i][0], orders[i][1]));
                        break;
                    }
                    pair<int, int> tmp = sell.top();
                    sell.pop();
                    // 最低sell <= buy 需要匹配
                    if (tmp.first <= orders[i][0]) {
                        if (tmp.second < orders[i][1]) {
                            orders[i][1] -= tmp.second;
                            tmp.second = 0;                                
                        } else if (tmp.second > orders[i][1]) {
                            tmp.second -= orders[i][1];
                            orders[i][1] = 0;
                            sell.push(tmp);
                            break;
                        } else if (tmp.second == orders[i][1]) {
                            tmp.second = 0;
                            orders[i][1] = 0;
                            break;
                        }
                    } else  {
                        buy.push(make_pair(orders[i][0], orders[i][1]));
                        sell.push(tmp);
                        break;
                    }
                }
            } else if (orders[i][2] == 1) {
                while (true) {
                    if (buy.empty()) {
                        sell.push(make_pair(orders[i][0], orders[i][1]));
                        break;
                    }
                    pair<int, int> tmp = buy.top();
                    buy.pop();
                    // 最高buy >= sell 需要匹配
                    if (tmp.first >= orders[i][0]) {
                        if (tmp.second < orders[i][1]) {
                            orders[i][1] -= tmp.second;
                        } else if (tmp.second > orders[i][1]) {
                            tmp.second -= orders[i][1];
                            buy.push(tmp);
                            break;
                        } else if (tmp.second == orders[i][1]) {
                            break;
                        }
                    } else  {
                        sell.push(make_pair(orders[i][0], orders[i][1]));
                        buy.push(tmp);
                        break;
                    }
                }
            }
        }
        int ans = 0;
        while (!buy.empty()) {
            pair<int, int> tmp = buy.top();
            buy.pop();
            ans = (ans + tmp.second) % 1000000007;
        }
        while (!sell.empty()) {
            pair<int, int> tmp = sell.top();
            sell.pop();
            ans = (ans + tmp.second) % 1000000007;
        }
        return ans;
    }
};
// 思路是一点都不难 就是太繁琐 调了一个小时


int main() {
    Solution sol;
    // vector<vector<int>> v = {{7, 1000000000, 1}, {15, 3, 0}, {5, 999999995, 0}, {5, 1, 1}};
    vector<vector<int>> v = {{26, 7, 0}, {16, 1, 1}, {14, 20, 0}, {23, 15, 1}, {24, 26, 0}, {19, 4, 1}, {1, 1, 0}};
    sol.getNumberOfBacklogOrders(v);
}