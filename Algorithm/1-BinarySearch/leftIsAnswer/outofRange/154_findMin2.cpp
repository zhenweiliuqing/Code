#include <vector>
using namespace std;
// 3-16
class Solution {
public:
    int findMin(vector<int>& nums) {
        int left = 0;
        int right = nums.size() - 1;

        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] > nums[right])
                left = mid + 1;
            else if (nums[mid] < nums[right])
                right = mid;
            else 
                right--; // 之所以这个格式不对也能正确的道理是right--

        }
        return nums[left];
    }
};
// 通过了 
// right = mid 的玄机是什么？ 能让left移动到正确位置
// 11101 11121

class Solution {
public:
    int findMin(vector<int>& nums) {
        int low = 0;
        int high = nums.size() - 1;
        while (low < high) {
            int pivot = low + (high - low) / 2;
            if (nums[pivot] < nums[high]) {
                high = pivot;
            }
            else if (nums[pivot] > nums[high]) {
                low = pivot + 1;
            }
            else {
                high -= 1;
            }
        }
        return nums[low];
    }
};
// Leetcode


// 几个错误
// [3 1 3]
while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[nums.size() - 1])
        left = mid + 1;
    else if (nums[mid] < nums[nums.size() - 1])
        right = mid - 1;
    else 
        right--;
}
// 153题这样是正确的 因为mid到了左边 一定大于最后一个数 所以left=mid+1
// 这里错误是因为 到了左边之后 等于最后一个数 不能右移

// 从下面这两个错误中体会一下right = mid的玄机
// [3 1 3]
while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[right])
        left = mid + 1;
    else if (nums[mid] < nums[right])
        right = mid - 1;
    else 
        right--;
}
// 跟上个错误类似
// 153题这样也会出错 right位置变化 移到了左边 
// right为什么不能mid - 1 关键是看left能不能移动到正确位置

// [3 1 3] 输出3
while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[nums.size() - 1])
        left = mid + 1;
    else if (nums[mid] < nums[nums.size() - 1])
        right = mid;
    else 
        right--;
}
// 跟第一个问题一样 就是不能跟右侧比 无非是快一步慢一步的问题
// 一直和最后一个比较 导致mid移到左侧 还是right--
// 但是153 和最后一个比就没有问题 因为mid落到左边 一定会有left=mid+1

// [1 3 5]
// 格式问题
// 如果是 <= 一定要 -1
while (left <= right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[nums.size() - 1])
        left = mid + 1;
    else if (nums[mid] < nums[nums.size() - 1])
        right = mid;
    else 
        right--;
}
// 陷入right = mid的死循环
// 153题也是如此

// [1 3 3]
while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[right])
        left = mid + 1;
    else if (nums[mid] < nums[right])
        right = mid;
    else 
        left++; // 最值是在左边 往右走不行
}

// [2 2 2 0 1] [1 3 3]
// 这个错的更离谱
while (left < right) {
    int mid = left + ((right - left) >> 1);
    if (nums[mid] > nums[right])
        left = mid;
    else if (nums[mid] < nums[right])
        right = mid - 1; // left不能到达正确位置
    else 
        left++;
}
// right-- 的正确性在于最右侧如果是最小 那么left一定会加
// 如果往左移动 那么左边一定是有相等的小的存在







