#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maximumElementAfterDecrementingAndRearranging(vector<int>& arr) {
        sort(arr.begin(), arr.end());
        arr[0] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] - arr[i - 1] <= 1)
                continue;
            arr[i] = arr[i - 1] + 1;
        }
        return arr.back();
    }
};
// 通过了 太水了 