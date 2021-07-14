#include <iostream>
using namespace std;

// 7-12
class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 1;
        for (int i = n - 1; i >= 0; --i) {
            if (citations[i] >= h)
                ++h;
        }
        return h - 1;
    }
};
// 通过

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n = citations.size();
        int h = 0;
        for (int i = n - 1; i >= 0; --i) {
            if (citations[i] > h)
                ++h;
        }
        return h;
    }
};