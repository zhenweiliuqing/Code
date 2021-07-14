#include <iostream>
using namespace std;

// 6-14
class Solution {
public:
    int guessNumber(int n) {
        int left = 1, right = n;
        int mid;
        while (left <= right) {
            mid = left + (right - left) / 2;
            int tmp = guess(mid);
            if (tmp == 0)
                return mid;
            else if (tmp == -1)
                left = mid + 1;
            else if (tmp == 1)
                right = mid - 1;
        }
        return mid;
    }
};