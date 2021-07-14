#include <string>
using namespace std;

// 5-29
// 将字符串拆分为递减的连续值 -1
// 感觉可以用回溯 就枚举每一种拆分方法
// for 循环 就是选择多长的字符串
// 递归 就是把剩下的字符串 重新进行for循环
class Solution {
public:
    bool backtrack(string s, int start, unsigned long pre) {
        if (start == s.size())
            return true;

        for (int i = start; i < s.size(); i++) {
            if (pre == ULLONG_MAX && i == s.size() - 1)
                return false;
            unsigned long tmp = stoul(s.substr(start, i - start + 1));
            if (tmp >= pre)
                return false;
            if (pre == ULLONG_MAX || pre - 1 == tmp) {
                if(backtrack(s, i + 1, tmp))
                    return true;
            }
        }
        return false;
    }
    bool splitString(string s) {
        return backtrack(s, 0, ULLONG_MAX);
    }
};
// 通过了 可真不容易 就是怕越界

// "6442 4509 4421 4748 3647"
// 52/195

// "2275 9227 5822 7572 2756"
// 161/195

int main() {
    Solution sol;
    sol.splitString("22759227582275722756");
}