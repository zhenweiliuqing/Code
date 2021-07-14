#include <string>
using namespace std;

// 6-9
class Solution {
public:
    int minFlips(string s) {
        // 先看看通过第一种操作能否得到交错序列
        // 得用暴力方法判断 O(n2)
        int ans = INT_MAX;
        int cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i % 2 == 0 && s[i] == '0') || (i % 2 == 1 && s[i] == '1'))
                continue;
            cnt++;
        }
        ans = cnt;
        cnt = 0;
        for (int i = 0; i < s.size(); i++) {
            if ((i % 2 == 0 && s[i] == '1') || (i % 2 == 1 && s[i] == '0'))
                continue;
            cnt++;
        }
        ans = min(ans, cnt);
        return ans;
    }
};
// 不会做 看答案

class Solution {
public:
    int minFlips(string s) {
        int len = s.size();
        string target = "01";

        int cnt = 0;
        for (int i = 0; i < len; i++) {
            cnt += (s[i] != target[i % 2]);
        }

        // s += s;
        // 将字符串复制一份接在后面 通过滑动窗口把前面加上的去掉 后面需要修改的加进来
        int ans = min({ cnt, len - cnt });
        for (int i = 0; i < len; i++) {
            cnt -= (s[i] != target[i % 2]);
            cnt += (s[i] != target[(i + len) % 2]);
            ans = min({ ans, cnt, len - cnt });
        }

        return ans;
    }
};

// 作者：ikaruga
// 链接：https://leetcode-cn.com/problems/minimum-number-of-flips-to-make-the-binary-string-alternating/solution/minimum-number-of-flips-by-ikaruga-lu32/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。