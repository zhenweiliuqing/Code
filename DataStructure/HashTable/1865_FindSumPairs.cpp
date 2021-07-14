#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;

// 5-21
// 这得用map统计个数
class FindSumPairs {
private:
    vector<int> v1, v2;
    unordered_map<int, int> mmap;

public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1, v2 = nums2;
        for (int i : nums2)
            mmap[i]++;
    }
    
    void add(int index, int val) {
        mmap[v2[index]]--;
        v2[index] += val;
        mmap[v2[index]]++;
    }
    
    int count(int tot) {
        int cnt = 0;
        for (int i : v1) {
            int target = tot - i;
            cnt += mmap[target];
        }
        return cnt;
    }
};
// 通过了

class FindSumPairs {
public:
    FindSumPairs(vector<int>& nums1, vector<int>& nums2) {
        v1 = nums1;
        v2 = nums2;
    }
    
    void add(int index, int val) {
        if (index < v2.size())
            v2[index] += val;
    }
    
    int count(int tot) {
        int cnt = 0;
        // 暴力方法 应该会超时
        // for (int i = 0; i < v1.size(); i++) {
        //     for (int j = 0; j < v2.size(); j++) {
        //         if (v1[i] + v2[j] == tot)
        //             cnt++;
        //     }
        // }

        vector<int> t1 = v1, t2 = v2;
        sort(t1.begin(), t1.end());
        sort(t2.begin(), t2.end());
        int i = 0, j = t2.size() - 1;
        while (i < t1.size() && j >= 0) {
            if (t1[i] + t2[j] == tot) {
                int k1 = i, k2 = j;
                while (k1 < t1.size() && t1[k1] == t1[i])
                    k1++;
                while (k2 >= 0 && t2[k2] == t2[j])
                    k2--;
                cnt += (k1 - i) * (j - k2);
                i = k1;
                j = k2;
            } else if (t1[i] + t2[j] > tot)
                j--;
            else if (t1[i] + t2[j] < tot)
                i++;
        }
        return cnt;
    }
private:
    vector<int> v1, v2;
};
// 23/26 这还超出时间限制啊

/**
 * Your FindSumPairs object will be instantiated and called as such:
 * FindSumPairs* obj = new FindSumPairs(nums1, nums2);
 * obj->add(index,val);
 * int param_2 = obj->count(tot);
 */
