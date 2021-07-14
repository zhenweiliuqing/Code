// 1-29
#include <iostream>
#include <vector>
using namespace std;

// 首先需要考虑内存问题 1.原字符串后面有没有足够内存 2.能够开辟新的内存空间
// 假如要求是原地修改 则从后往前改
// 双指针?
// "" 是const char* s[i]是char

// 测试用例:
// 1.空 2.一个空格
class Solution {
public:
    string replaceSpace(string s) {
        int n = s.size() - 1, cnt = 0;
        for (int i = 0; i <= n; i++) {
            if (s[i] == ' ')
                cnt++;
        }
        int i = n, j = i + cnt * 2;
        // 如何给s分配更长的内存空间
        s.resize(j + 1);
        while (i != j) {
            if (s[i] == ' ') {
                s[j--] = '0';
                s[j--] = '2';
                s[j--] = '%';
            } else {
                s[j--] = s[i];
            }
            i--;
        }
        return s;
    }
};
// 通过了