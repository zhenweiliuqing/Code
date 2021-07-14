#include <vector>
#include <algorithm>
using namespace std;

class Answer {
public:
    int search(vector<int>& nums, int target) {
        int n = (int)nums.size();
        if (n == 0)
            return -1;
        if (n == 1)
            return nums[0] == target ? 0 : -1;
        int l = 0, r = n - 1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] == target)
                return mid;
            
            // 关键就是这一块 一定要在有序部分查找 一定有一半是有序的
            if (nums[0] <= nums[mid]) { // 中间值在左半部分 说明左半部分有序
                if (nums[0] <= target && target < nums[mid]) // target在 0 和 mid 之间 在左半部分有序之间
                    r = mid - 1;
                else
                    l = mid + 1;
            } else { // 中间值在右半部分
                if (nums[mid] < target && target <= nums[n - 1]) // taget在 mid 和 n - 1之间
                    l = mid + 1;
                else
                    r = mid - 1;
            }
        }
        return -1;
    }
};