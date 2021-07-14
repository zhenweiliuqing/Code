#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 6-16
// 把最左侧当作判断标准
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] >= nums[0])
                left = mid + 1;
            else if (nums[mid] < nums[0])
                right = mid - 1;
        }
        return nums[left];
    }
};
// 会报错 1 2 3 这种有序情况下left会一直到最后 left会越界

// 3-15
// 那么换成右侧就不越界了吗 right越界没有问题 left不会
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[nums.size() - 1])
                left = mid + 1;
            else if (nums[mid] <= nums[nums.size() - 1])
                right = mid - 1;
        }
        return nums[left];
    }
};
// 通过 这跟33第一问是一样的 找到峰值
// 用nums[0] 作为判别条件 1 2 3 4 5 这种会报错 得用右边的作为条件

// 用改进的二分查找来做
// 普通的是跟target进行比较
class Answer {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;
        while (left < right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right])
                left = mid + 1;
            else
                right = mid;
        }
        return nums[left];
    }
};




// 二分法思考
// 1. 把right left移到测试用例上 看哪个是正确答案 
// 2. 大部分left是正确答案 关键就在于当right等于正确答案时 一定要让 right = mid - 1; 这样left才会移到正确答案的位置
// 条件是千变万化的 一定要抓住本质

// 几个错误

//格式错误
// [3,1,2] 输出3
// left 移不到正确位置
while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[nums.size() - 1])
        left = mid + 1;
    else if (nums[mid] <= nums[nums.size() - 1])
        right = mid - 1;
}
// [3 4 5 1 2] 超时
while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[nums.size() - 1])
        left = mid;
    else if (nums[mid] <= nums[nums.size() - 1])
        right = mid;
}
// 卡死在left = mid这里
while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[nums.size() - 1])
        left = mid + 1;
    else if (nums[mid] <= nums[nums.size() - 1])
        right = mid;
}
// 卡死在right = mid这里 卡在5这里
// 这三个错误都是格式错误
// 如果循环取等号 下边一定要 +1 -1
// 循环没等号 要有一个+1 两个也不行

// [1] 超时
// 边界问题
while (left <= right) {
    int mid = left + ((right - left) >> 1);
    // 左侧没有问题 不管是落在哪个点 都要往右移
    if (nums[mid] > nums[nums.size() - 1])
        left = mid + 1;
    // < 往左移没有问题 = 就是边界情况 
    // left right mid 都在一个位置 left right都在正确位置 
    // 所以这个边界情况就要让right左移
    else if (nums[mid] < nums[nums.size() - 1])
        right = mid - 1;
}
// 大部分情况下 right在正确答案可以移到左侧
// 这里的条件是nums[mid] = nums[right]  

// [3 1 2] 会输出3 right是动态的
while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[right])
        left = mid + 1;
    else if (nums[mid] <= nums[right])
        right = mid - 1;
}
// 这里没有重复的数字 right改变之后反而会影响left到达正确的位置
