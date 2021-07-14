#include <string>
using namespace std;

// 6-4
class Solution {
public:
    int sumBase(int n, int k) {
        string ans;
        while (n != 0) {
            ans = to_string(n % k) + ans;
            n /= k;
        }
        int sum = 0;
        for (char c : ans)
            sum += c - '0';
        return sum;
    }
};
// 通过了