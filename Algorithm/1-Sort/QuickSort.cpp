#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 测试用例：
// 7 1 2 5 6 8
// 一前一后寻找并交换
int partition(vector<int>& nums, int start, int end) {
    int pivot = nums[start];
    int slow = start;
    for (int fast = slow + 1; fast <= end; fast++) {
        // 这个得是 <= 不然会有一些等于pivot的元素混在 > 之中
        // 其实也没关系把 要么混在大于之中 要么混在小于之中
        if (nums[fast] > pivot) {
            slow++;
            swap(nums[slow], nums[fast]);
        }
    }
    swap(nums[slow], nums[start]);
    return slow;
}

// 从两边寻找并交换
// int partition(vector<int>& nums, int start, int end) {
//     int pivot = nums[start];
//     int left = start + 1, right = end;
//     while (left <= right) {
//         while (left <= right && nums[left] <= pivot)
//             left++;
//         while (left <= right && nums[right] > pivot)
//             right--;
//         if (left < right) {
//             int tmp = nums[left];
//             nums[left] = nums[right];
//             nums[right] = tmp;
//         }
//     }
//     nums[start] = nums[right];
//     nums[right] = pivot;
//     return right;
// }

void quickSort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int mid = partition(nums, start, end);
        quickSort(nums, start, mid - 1);
        quickSort(nums, mid + 1, end);
    }
}

int main() {
    // vector<int> nums = {7, 1, 2, 3, 8};
    vector<int> nums = {3, 2, 1, 5, 6, 4};
    quickSort(nums, 0, nums.size() - 1);
    return 0;
}