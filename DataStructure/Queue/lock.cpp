#include <iostream>
#include <vector>
#include <unordered_set>
#include <queue>
using namespace std;

class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlocks(deadends.begin(), deadends.end());
        if (deadlocks.count(target) != 0 || deadlocks.count("0000") != 0) // count返回某个值元素的个数
            return -1;
        queue<string> q;
        q.push("0000");
        unordered_set<string> visited;
        visited.insert("0000");
        vector<int> directs = {1, -1};
        int res = 0;
        while (!q.empty()) {
            int size = q.size();
            while (size-- > 0) {
                auto t = q.front;
                q.pop();
                if (t == target)
                    return res;
                if (deadlocks.count(t))
                    return -1;
                for (int i = 0; i < 4; i++) {
                    for (auto direct : directs) {
                        string newWord = t; // 这个不能在外边
                        newWord[i] = (newWord[i] - '0' + 10 + direct) % 10 + '0';
                        if (visited.count(newWord) || deadlocks.count(newWord))
                            continue;
                        q.push(newWord);
                        visited.insert(newWord);
                    }
                }
            }
            res++;
        }
        return -1;
    }
};


class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deadlocks(deadends.begin(), deadends.end());
        if (deadlocks.count(target) != 0 || deadlocks.count("0000") != 0)
            return -1;
        unordered_set<string> visited;
        queue<string> q;
        q.push("0000");
        visited.insert("0000");
        int steps = 1;
        vector<int> directs = {1, -1};
        while (!q.empty()) {
            int size = q.size();
            while (size--) {
                string temp = q.front();
                q.pop();
                string newword = temp;  
                for (int i = 0; i < 4; i++) {
                    for (auto direct : directs) {
                        newword[i] = (newword[i] - '0' + 10 + direct) % 10 + '0';
                        if (visited.count(newword) != 0 || deadlocks.count(newword) != 0)
                            continue;
                        if (target == newword)
                            return steps;
                        visited.insert(newword);
                        q.push(newword);
                    }
                }
            }
            steps++;
        }
    }
};