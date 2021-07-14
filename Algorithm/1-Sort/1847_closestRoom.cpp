#include <vector>
#include <set>
#include <algorithm>
using namespace std;

// 6-3
// 找到面积符合要求的且离要求最近的下标最小的房间
// 还是用双指针把 每个就是O(n) 
// 肯定不能排序 排序复杂度O(nlogn)
class Solution {
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        vector<int> ans;
        for (auto q : queries) {
            int len = INT_MAX;
            int id = -1;
            for (auto r : rooms) {
                if (r[1] >= q[1]) {
                    if (abs(r[0] - q[0]) < len || (abs(r[0] - q[0]) == len && r[0] < id)) {
                        len = abs(r[0] - q[0]);
                        id = r[0];
                    }
                }
            }
            ans.push_back(id);
        }
        return ans;
    }
};
// 果然超时

// 这个真的是妙
class Solution {
    vector<int> ans;
    set<int> s;
public:
    vector<int> closestRoom(vector<vector<int>>& rooms, vector<vector<int>>& queries) {
        int n = rooms.size(), q = queries.size(), i, j, k;
        ans.clear();
        ans.resize(q, -1);
        // 按照房间面积从大到小排序
        for(i = 0; i < n; i++)
            swap(rooms[i][0],rooms[i][1]);
        sort(rooms.begin(), rooms.end());
        reverse(rooms.begin(), rooms.end());
        
        for(i = 0; i < q; i++) {
            swap(queries[i][0],queries[i][1]);
            queries[i].push_back(i); // 询问里边又push进一个下标i 这是什么意思
        }
        // 也是按照房间面积从大到小排序
        sort(queries.begin(), queries.end()); 
        reverse(queries.begin(), queries.end());
        
        s.clear();
        for(i = j = 0; i < q; i++) {
            k = queries[i][2]; // 这个用来当作ans的下标
            // rooms[j][0] 房间j的面积 queries[i][0] 询问房间i的面积 
            // 都是从大到小排序 把大于询问面积的房间都push进去
            // 第二次来的话 会接着上次不满足要求的room接着往后比较 上次满足的这次也一定满足
            for(; j < n && rooms[j][0] >= queries[i][0]; j++)
                s.insert(rooms[j][1]); // 把符合要求的房间id push进set里
            auto it = s.lower_bound(queries[i][1]); // 找到第一个 >=询问房间的id
            if(it != s.end())
                ans[k] = *it; // 先找到一个最小的>=询问的房间id
            if(it != s.begin()) {
                it--; // 往左挪一步 这个肯定是小于询问房间的id 这个是左边的 上面那个是右边的
                // ans[k] = -1 取反就是0 假如没有右边的那就只能是左侧的房间了
                if(!~ans[k] || ans[k] - queries[i][1] >= queries[i][1] - *it)
                    ans[k] = *it;
            }
        }
        return ans;
    }
};
