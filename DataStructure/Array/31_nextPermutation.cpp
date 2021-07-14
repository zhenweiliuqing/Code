#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1)
            return;
        // for (int i = n - 1; i >= 0; i--) {
        //     // 找到前一位小的 交换之后就变大了
        //     // 得双重循环 找到之前有一位小的
        //     for (int j = i - 1; j >= 0; j--) {
        //         if (nums[j] < nums[i]) {
                    // 插入需要iterator 用下标能转成迭代器吗         
        //         }
        //     }    
        // }

        for (auto i = nums.end(); i != nums.begin(); i--) {
            for (auto j = i - 1; j != nums.begin(); j--) {
                if (*j <= *i) {
                    nums.insert(j, *j); // 感觉还是不全面啊 不是按这个顺序的 
                }
            }
        }
            sort(nums.begin(), nums.end());
        return;
    }
};

class MyAnswer {
public:
    // 从最后一位开始找 找到第一位下降的
    void nextPermutation(vector<int>& nums) {
        int n = nums.size();
        if (n == 1 || n == 0)
            return;

        int up = -1, down = -1;
        for (int i = n - 1; i >= 0; i--) {
            if (i != 0 && nums[i - 1] < nums[i]) {
                down = i - 1;
                break;
            }
        }
        if (down != -1) {
            // 再从后边开始 找到第一位比down高的
            for (int i = n - 1; i >= 0; i--) {
                if (nums[i] > nums[down]) {
                    up = i;
                    break;
                }
            }
            // 将up 与 down交换
            int temp = nums[down];
            nums[down] = nums[up];
            nums[up] = temp;
        }
        
        // 将down之后的全部反转
        for (int i = down + 1, j = n - 1; i < j; i++, j--) {
            int temp = nums[i];
            nums[i] = nums[j];
            nums[j] = temp;
        }
    }
};
// 终于通过了 调整了一下判断条件