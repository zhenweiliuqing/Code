// 3-14

// 思路：就把0移到前边 2移到后边
// 我这其实是单指针
class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0, right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] == 0)
                left++;
            while (left < right && nums[right] != 0)
                right--;
            if (left < right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }

        left = 0; right = nums.size() - 1;
        while (left < right) {
            while (left < right && nums[left] != 2)
                left++;
            while (left < right && nums[right] == 2)
                right--;
            if (left < right) {
                int tmp = nums[left];
                nums[left] = nums[right];
                nums[right] = tmp;
            }
        }
    }
};

class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size();
        int p0 = 0, p1 = 0;
        for (int i = 0; i < n; ++i) {
            // nums[i] == 2 移动i
            if (nums[i] == 1) {
                // 1 跟p1交换
                swap(nums[i], nums[p1]);
                ++p1;
            } else if (nums[i] == 0) {
                // 0 跟p0交换
                swap(nums[i], nums[p0]);
                // p1 指向的是1后边的元素
                // p0 指向的是0后边的元素 
                if (p0 < p1) {
                    // p0 < p1
                    swap(nums[i], nums[p1]);
                }
                ++p0;
                ++p1;
            }
        }
    }
};

// 作者：LeetCode-Solution
