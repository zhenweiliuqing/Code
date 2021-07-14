#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Solution {
public:
    unordered_map<int, int> m;
    int fib(int N) {
        int ret;
        if (N < 2)
            return N;
        if (m.count(N)) // m里key的个数为0 表示不存在
            return m[N];
        ret = fib(N - 1) + fib(N - 2);
        m[N] = ret;
        return ret;
    }
};
