#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    struct node {
        int idx;
        int h;
    };
    static bool cmp(node a, node b){
        return a.h > b.h;
    }
    int maxArea(vector<int>& height) {
        int n = height.size();
        vector<node> v(n);
        for (int i = 0; i < height.size(); i++) {
            v[i] = {i, height[i]}; // 之前什么地方也可以这样写？
        }
        sort(v.begin(), v.end(), cmp); // 还得加static?
        for (int i = 1; i < n; i++) {
            // 这不还得遍历？
        }
    }
};

// 双指针 一个指针遍历 另一个指针怎么确定边界？
class Answer {
public:
    int maxArea(vector<int>& height) {
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans, area);
            if (height[l] <= height[r])
                l++;
            else
                r--;
        }
        return ans;
    }
};

// 自己的思路是找到一个比自己高的且最远的 问题是还要遍历判断比自己高的

// 答案的思路是直接从最远的开始 然后舍弃小的 往中间缩 
// 那个小的确实没有利用价值了 因为最远的比他高 所以中间比他高的比他矮的都没有意义了
// 所以先确定最远的 再把小的给一个一个剔除出去

// maxArea
// 主要是两个维度 一个最远 一个最高 先从两端开始 肯定是最远
// 把那个矮的指针向下遍历 在保证在距离-1的情况下 得到一个高的
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int max = 0;
        int l = 0, r = n - 1;
        while (l < r) {
            if (max < min(height[l], height[r]) * (r - l))
                max = min(height[l], height[r]) * (r - l);
            height[l] < height[r] ? l++ : r--; // 可以这么用
        }
        return max;
    }
};
// 通过了