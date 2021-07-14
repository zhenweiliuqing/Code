#include <unordered_map>
#include <algorithm>
using namespace std;

// 5-15
// 这个简洁
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for (auto& v : wall) {
            if (v.size() > 1)
                mp[v[0]]++;
            for (int i = 1; i < v.size() - 1; i++) {
                v[i] += v[i - 1];
                mp[v[i]]++;
            }
        }
        int maxBrick = 0;
        for (auto it : mp) {
            maxBrick = max(maxBrick, it.second);
        }
        return wall.size() - maxBrick;
    } 
};

// 5-15
class Solution {
public:
    typedef pair<int, int> PAIR;
    static bool cmp(const PAIR a, const PAIR b) {
        return a.second > b.second;
    }

    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> mp;
        for (auto& v : wall) {
            if (v.size() > 1)
                mp[v[0]]++;
            for (int i = 1; i < v.size() - 1; i++) {
                v[i] += v[i - 1];
                mp[v[i]]++;
            }
        }
        if (mp.size() == 0)
            return wall.size();
        vector<pair<int, int>> v;
        for (auto it : mp) {
            v.push_back(make_pair(it.first, it.second));
        }
        sort(v.begin(), v.end(), cmp);
        return wall.size() - v[0].second;
    }
};
// 通过了 可以的

