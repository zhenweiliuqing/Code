#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int slow = 0, fast = 1, cnt = 0;
        int n = nums.size();
        if (n == 0)
            return 0;
        else if (n == 1)
            return 1;
        while (cnt < n) {
            if (nums[slow] == nums[fast]) {
                // 循环覆盖
                for (int i = fast; i < n - 1; i++) {
                    nums[i] = nums[i + 1];
                }
            } else if (nums[slow] != nums[fast]) {
                if (fast == n - 1){
                    slow++;
                    break;}
                slow++;
                fast++;
            }
            cnt++;
        }
        return slow+1;
    }
};
// 终于通过了 这在这凑补丁呢 1192ms

class Answer {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        if (n == 0)
            return 0;
        int cnt = 0;
        for (int i = 0; i < n; i++) {
            if (nums[cnt] != nums[i]) {
                cnt++;
                nums[cnt] = nums[i];
            }
        }
        return cnt + 1;
    }
};
// 20ms

