// 4-5
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int magicTower(vector<int>& nums) {
        int sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum < 0)
            return -1;
        
        priority_queue<int, vector<int>, greater<int>> q;
        int blood = 1;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            blood += nums[i];
            if (nums[i] < 0) {
                q.push(nums[i]);
                
                while (!q.empty() && blood <= 0) {
                    blood -= q.top();
                    q.pop();
                    ans++;
                }
            }   
        }
        return ans;
    }

    // int越界 把int 改成long就好了
    // 修改
    int magicTower(vector<int>& nums) {
        long sum = 0;
        for (int i = 0; i < nums.size(); i++)
            sum += nums[i];
        if (sum < 0)
            return -1;
        
        priority_queue<int, vector<int>, greater<int>> q;
        long blood = 1;
        int ans = 0;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            blood += nums[i];
            if (nums[i] < 0) {
                q.push(nums[i]);
                
                while (!q.empty() && blood <= 0) {
                    blood -= q.top();
                    q.pop();
                    ans++;
                }
            }   
        }
        return ans;
    }
};

int main() {
    Solution sol;
    vector<int> v = {100, 100, 100, -250, -60, -140, -50, -50, 100, 150};
    sol.magicTower(v);
}