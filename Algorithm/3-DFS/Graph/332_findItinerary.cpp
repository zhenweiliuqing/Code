// 4-14
#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <deque>
using namespace std;

class Solution {
public:
    // unordered_map<string, int> isVisited;
    // unordered_map<string, vector<string>> mmap;
    // vector<string> ans;
    // void dfs(vector<vector<string>>& tickets, string start) {
    //     ans.push_back(start);
    //     isVisited[start]--;
    //     string next;
    //     for (int i = 0; i < tickets.size(); i++) {
    //         if (tickets[i][0] == start) {
    //             if (isVisited.count(tickets[i][1]) == 0) {
    //                 ans.push_back(tickets[i][1]);
    //                 return;
    //             }
    //             if (next == "" || next > tickets[i][1])
    //                 next = tickets[i][1];
                
                
    //         }
    //     }
    //     dfs(tickets, next);
    // }
    // vector<string> findItinerary(vector<vector<string>>& tickets) {
    //     int n = tickets.size();
    //     for (int i = 0; i < n; i++) {
    //         isVisited[tickets[i][0]]++;
    //         //isVisited[tickets[i][1]]++;
    //     }
    //     dfs(tickets, "JFK");
    //     return ans;
    // }

    // unordered_map<string, vector<string>> mmap;
    unordered_map<string, deque<string>> mmap;
    vector<string> ans;

    void dfs(string start) {
        ans.push_back(start);
        int n = mmap[start].size();
        if (n == 0)
            return;
        string next;
        next = mmap[start][n - 1];
        mmap[start].pop_back();
        dfs(next);
    }

    vector<string> findItinerary(vector<vector<string>>& tickets) {
        int n = tickets.size();
        for (int i = 0; i < n; i++) {
            mmap[tickets[i][0]].push_back(tickets[i][1]);
        }
        for (auto it : mmap) {
            // sort(it.second.begin(), it.second.end(), less<string>());
            sort(it.second.begin(), it.second.end(), [](string a, string b) {return a > b;});
            mmap[it.first] = it.second; // 应该重新赋值 不然拿出来的排了序 里边的没动
            
        }
        dfs("JFK");
        return ans;
    }
};

int main() {
    Solution sol;
    vector<vector<string>> v = {{"JFK","SFO"},{"JFK","ATL"},{"SFO","ATL"},{"ATL","JFK"},{"ATL","SFO"}};
    sol.findItinerary(v);
}