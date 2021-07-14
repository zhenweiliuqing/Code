#include <iostream>
#include <vector>
using namespace std;


// 测试用例
// 4 5 5 5 1 4 4
// 5 5 5 5 1 5 5
// 1 2 3 4 5 6 7
// 7 6 5 4 3 2 1
// 3 4 5 6 1 2 3
// 3 4 0 0 1 2 3

// 3 1 1
// 3 1 3 
// 3 3 1 3
// 调换顺序也不能全部通过测试 可以转换一下思路 我的思路有漏洞
// 二分查找的细节是魔鬼啊

class Solution {
public:
    int minArray(vector<int>& numbers) {
        int left = 0, right = numbers.size() - 1;
        while (left <= right) {
            int mid = ((right - left) >> 1) + left;
            if (numbers[mid] == numbers[left] && numbers[mid] == numbers[right])
                return findinOrder(numbers, left, right);
            else if (numbers[mid] <= numbers[right])
                right = mid - 1;
            else if (numbers[mid] > numbers[right])
                left = mid + 1;
            else if (numbers[mid] < numbers[mid - 1] && numbers[mid] < numbers[mid + 1]) // 这个可能会越界
                return numbers[mid];
        }
        return numbers[left];
    }

    int findinOrder(vector<int>& nums, int left, int right) {
        for (int i = left + 1; i <= right; i++) {
            if (nums[i] < nums[i - 1])
                return nums[i];
        }
        return nums[left];
    }
};

// 
int minArray(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    int mid = left;
    while (nums[left] <= nums[right]) {
        if (right - left == 1) {
            mid = right;
            break;
        }
        mid = ((right - left) >> 1) + left;
        if (nums[left] == nums[right] && nums[left] == nums[mid])
            return findinOrder(nums, left, right);
        if (nums[mid] >= nums[8])
        
    }
}

int findinOrder(vector<int>& nums, int left, int right) {
    for (int i = left + 1; i <= right; i++) {
        if (nums[i] < nums[i - 1])
            return nums[i];
    }
    return nums[left];
}


