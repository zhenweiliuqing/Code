#include <vector>
#include <iostream>
using namespace std;

// 5-24
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int num : nums) {
                sum += (num >> i) & 1;
            }
            ans |= (sum % 3) << i;
        }
        return ans;
    }
};
// 通过了

// 思路没错 但是用了long
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        long ans = 0;
        for (int i = 0; i < 32; i++) {
            long sum = 0;
            for (long num : nums) {
                sum += (num & (1l << i));
            }
            ans += sum % (3l * (1l << i));
        }
        return ans;
    }
};
// 通过了

// 会溢出
class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int ans = 0;
        for (int i = 0; i < 32; i++) {
            int sum = 0;
            for (int num : nums) {
                sum += (num & (1 << i));
            }
            ans += sum % (3 * (1 << i));
        }
        return ans;
    }
};

int main() {
    vector<int> v = {2, 2, 2, 99};
    Solution sol;
    sol.singleNumber(v);
}