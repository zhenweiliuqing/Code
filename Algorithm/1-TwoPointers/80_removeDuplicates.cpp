// 12-31
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int slow = 0, fast = 0;
        unordered_map<int, int> mmap;
        while (fast < n) {
            mmap[nums[fast]]++;
            if (mmap[nums[fast]] <= 2) {
                nums[slow] = nums[fast];
                slow++;
            }
            fast++;
        }
        return slow;
    }
};
// 通过了