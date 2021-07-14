// 2-25
#include <vector>
#include <iostream>
#include <set>
#include <queue>
using namespace std;

// 思路: 利用快排中partition函数可以找出第k个index 可以知道前面就是k个小的数 但是需要交换位置
// 第二种方法: 利用一个最大堆 一共有k个值 利用红黑树来维持最大堆 
// 最大堆不知道如何用multiset实现
class Solution {
public:
    vector<int> getLeastNumbers(vector<int>& arr, int k) {
        vector<int> ans;
        priority_queue<int> q; // 默认为最大堆
        if (arr.size() < k || k == 0)
            return ans;

        for (int i = 0; i < arr.size(); i++) {
            if (q.size() < k) {
                q.push(arr[i]);
            }
            else {
                if (q.top() > arr[i]) {
                    q.pop();
                    q.push(arr[i]);
                }                    
            }
        }
        while (!q.empty()) {
            int tmp = q.top();
            ans.push_back(tmp);
            q.pop();
        }
        return ans;
    }
};
// 通过了
// 得把partition再看看 有点生疏了

// 3-15
vector<int> getLeastNumbers(vector<int>& arr, int k) {
    vector<int> ans;
    if (k == 0)
        return ans;
    int left = 0, right = arr.size() - 1;
    while (left < right) {
        int index = partition(arr, left, right);
        if (index == k - 1)
            break;
        else if (index > k - 1)
            right = index - 1;
        else if (index < k - 1)
            left = index + 1;
    }
    for (int i = 0; i < k; i++)
        ans.push_back(arr[i]);
    return ans;
}
int partition(vector<int>& nums, int start, int end) {
    int left = start, right = end;
    int pivot = nums[left];
    while (left < right) {
        // 这里必须是 == 
        while (left <= right && nums[left] <= pivot)
            left++;
        while (left <= right && nums[right] > pivot)
            right--;
        if (left < right) {
            int tmp = nums[left];
            nums[left]= nums[right];
            nums[right] = tmp;
        }
    }
    nums[start] = nums[right];
    nums[right] = pivot;
    return right;
}

