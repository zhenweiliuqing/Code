// 1-28
#include <iostream>
#include <vector>
using namespace std;

// 方法1 排序 时间复杂度nlogn
// 方法2 哈希表 时间复杂度n 空间复杂度n
// 方法3 交换 不知道这可以归为Algorithm的哪一个文件夹下 双指针？
class Solution {
public:
    int findRepeatNumber(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (nums[i] == i)
                continue;
            while (nums[i] != i) {
                int tmp = nums[i];
                if (nums[tmp] == nums[i])
                    return nums[i];
                nums[i] = nums[tmp];
                nums[tmp] = tmp;
            }
        }
        return -1;
    }
};
// 通过了