// 2-21
#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 这个主要就是考虑大整数 需要用string来表示
// 这最后输出是vector<int> string有啥用
class Solution {
public:
    vector<int> printNumbers(int n) {
        vector<int> ans;
        if (n <= 0)
            return ans;
        string s;
        for (int i = 0; i < n; i++)
            s += "9";
        int max = stoi(s);
        for (int i = 1; i <= max; i++)
            ans.push_back(i);
        return ans;
    }
};
// 通过了 但是这么没有什么意义