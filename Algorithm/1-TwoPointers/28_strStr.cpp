//12-29
#include <iostream>
#include <string>
using namespace std;

class Solution {
public:
    int strStr(string haystack, string needle) {
        if (needle.size() == 0)
            return 0;
        for (int i = 0; i < haystack.size(); i++) {
            if (haystack.size() - i < needle.size())
                break;
            if (haystack[i] != needle[0])
                continue;
            
            for (int j = i, k = 0; k < needle.size(); j++, k++) {
                if (haystack[j] != needle[k])
                    break;
                if (k == needle.size() - 1)
                    return j - k;
            }
        }
        return -1;
    }
};
// 就是一个一个比 也没什么

