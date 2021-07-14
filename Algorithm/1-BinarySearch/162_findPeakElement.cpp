#include <vector>
using namespace std;

// 6-18
// 分而治之 中间不是 那就去两边找 
// 答案一定在两边之中 分成两半 一定有一半是有序的
class Solution {
public:
    int binarySearch(const vector<int>& nums, int start, int end) {
        if (start > end)
            return -1;
        int left = start, right = end;
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[mid - 1] && nums[mid] > nums[mid + 1])
            return mid;
        int findleft = binarySearch(nums, start, mid - 1);
        if (findleft != -1)
            return findleft;
        int findright = binarySearch(nums, mid + 1, end);
        if (findright != -1)
            return findright;
        return -1;
    }

    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int n = nums.size() - 1;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n] > nums[n - 1])
            return n;
        return binarySearch(nums, 1, n - 1);
    }
};
// 通过了

// 一个峰和多个峰没有区别
class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        if (nums.size() == 1)
            return 0;
        int n = nums.size() - 1;
        if (nums[0] > nums[1])
            return 0;
        if (nums[n] > nums[n - 1])
            return n;

        // 这点是经典的left is answer 
        int left = 1, right = nums.size() - 2;
        while (left <= right) {
            int mid = (left + right) / 2;
            if (nums[mid] > nums[mid + 1])
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;
    }
};



class Solution {
    int findPeakElement(vector<int>& nums) {
        int l = 0, r = nums.size() - 1;
        // 这种不用考虑越界的问题
        while (l < r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums[mid + 1])
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

// 作者：LeetCode
// 链接：https://leetcode-cn.com/problems/find-peak-element/solution/xun-zhao-feng-zhi-by-leetcode/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。