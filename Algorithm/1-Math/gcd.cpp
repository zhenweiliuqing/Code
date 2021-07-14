#include <iostream>
#include <vector>
using namespace std;

int gcd(int a, int b) {
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// int gcd(int a, int b) {
//     if (a < b)
//         swap(a, b);
//     else if (a == b)
//         return a;
    
//     while (a % b != 0) {
//         a = a % b;
//         if (a < b)
//             swap(a, b);
//     }
//     return b;
// }


int calGCD(vector<int>& nums) {
    if (nums.size() == 0)
        return 0;
    if (nums.size() == 1)
        return nums[0];
    
    int first = nums[0];
    for (int i = 1; i < nums.size(); i++) {
        int x = gcd(first, nums[i]);
        if (x == 1)
            return 1;
        else 
            first = x;
    }
    return first;
}

// 计算一下一个序列的最大公约数
int main() {
    vector<int> v = {3, 6, 10};
    int ans = calGCD(v);
    return ans;
}