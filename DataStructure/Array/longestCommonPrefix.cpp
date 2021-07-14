#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 先按照size从小到大排序 
// 按第一个字符串折半对比
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), [](string &a, string &b) { return a.size() < b.size(); }); // 按长度进行排序
        string prefix = strs[0];
        int len = prefix.size(); 
        // 先不用折半查找了
        while (len != 0) {
            int i;
            for (i = 1; i < strs.size(); i++) {
                if (strs[i].substr(0, len) != prefix) {
                    len--;
                    prefix = strs[0].substr(0, len);
                    break;
                } 
            }
            if (i == strs.size()) {
                break;
            }
        }
        return prefix;
    }
};
// 时间复杂度 O(mm n) m字符串平均长度 n字符串数量   
// 但是我排了个序
// 通过了 但是有没有更好的方法 
