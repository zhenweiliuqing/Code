#include <vector>
#include <algorithm>
#include <iostream>
#include <cmath>
using namespace std;

// 5-25
// 先用下暴力解法
// 这个又是求满足条件的最小值 就是求左侧边界 left
// ceil() 向上取整  也可以用*100 没试过
// time += (dist[i] + speed - 1) / speed; 这种也可以

class Solution {
public:
    bool isValid(const vector<int>& dist, double hour, int speed) {
        double time = 0.0;
        for (int i = 0; i < dist.size() - 1; i++) {
            // 这个用的时候里边得转一下double 要不然里边自动就是int了
            // time += ceil(double(dist[i]) / speed);
            time += (dist[i] + speed - 1) / speed;
        }
        time += double(dist[dist.size() - 1]) / double(speed);
        return time <= hour;
    }
    int minSpeedOnTime(vector<int>& dist, double hour) {
        int n = dist.size();
        if (n - 1 > hour)
            return -1;
        int left = 1, right = 1e7;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isValid(dist, hour, mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};

int main() {
    Solution sol;
    vector<int> v = {1, 3, 2};
    sol.minSpeedOnTime(v, 2.7);
}