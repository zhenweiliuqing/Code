#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

const double ZERO = 0.00000001;
struct node {
    int charnum, digitnum;
    string s;
};


bool cmp(const node& s1, const node& s2) {
    double zero = double(s1.charnum / s1.digitnum) - double(s2.charnum / s2.digitnum);
    if (zero < ZERO && zero > -ZERO)
        return s1.s > s2.s;
    return zero > 0;
}


int main() {
    vector<string> s = {"abcx123","abcx122", "abc+12344", "ababab--1", "a1"};
    int n = s.size();
    vector<node> v;
    for (auto i : s) {
        node tmp = {};
        tmp.s = i;
        for (auto c : i) {
            if (isdigit(c))
                tmp.digitnum++;
            else
                tmp.charnum++;
        }
        v.emplace_back(tmp);
    }
    sort(v.begin(), v.end(), cmp);
}