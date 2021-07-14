#include <vector>
using namespace std;

// 搜索旋转排序数组 数组中的值互不重复
// 3-19
// 先找到峰值 再按照普通二分进行查找 不重复就很好说
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int left = 0, right = nums.size() - 1;
        // 为什么right要用-1 mid肯定不是最后一个数
        // 假如是一个值 mid也是自身 肯定不会+1 所以right-1一定不会让left越界
        // nums.size() 可以吗？
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            // 跟旋转后的最后一个数比较
            if (nums[mid] > nums[nums.size() - 1])
                left = mid + 1; 
            else 
                right = mid - 1;
        }
        
        int min = nums[left];
        int ans = -1;
        if (target >= min && target <= nums[nums.size() - 1])
            ans = search(nums, target, left, nums.size() - 1);
        // 这里right不能省 right=-1 后边还有一个nums[right]
        else if (right >= 0 && target >= nums[0] && target <= nums[right])
            ans = search(nums, target, 0, right);
        return ans;
    }
    // 普通二分
    int search(vector<int>& nums, int target, int left, int right) {
        if (left > right)
            return -1;
        while (left <= right) {
            int mid = left + ((right - left) >> 1);
            if (nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1;
            else if (nums[mid] > target)
                right = mid - 1;
        }
        return -1;
    }
};
// 一次通过 可以

// 6-18
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size();
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int left = 0, right = n - 1;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] == target) 
                return mid;
            if (nums[mid] >= nums[0]) { 
                if (target >= nums[0] && target < nums[mid])
                    right = mid - 1;
                else
                    left = mid + 1;
            } else {
                if (target <= nums[n - 1] && target > nums[mid])
                    left = mid + 1;
                else
                    right = mid - 1;
            }
        }
        return -1;
    }
};
// 通过了


class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (!n) {
            return -1;
        }
        if (n == 1) {
            return nums[0] == target ? 0 : -1;
        }
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target) return mid;
            if (nums[0] <= nums[mid]) {
                if (nums[0] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } else {
                if (nums[mid] < target && target <= nums[n - 1]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        return -1;
    }
};

// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/search-in-rotated-sorted-array/solution/sou-suo-xuan-zhuan-pai-xu-shu-zu-by-leetcode-solut/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。