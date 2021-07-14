#include <iostream>
#include <string>
using namespace std;

// 找当前第k个值 需要知道上一行对应的k/2位置的数是多少
// 上一行一个数对应这一行2个数 
// 根据上一行的值 以及 这一行的奇偶位来判断输出的值
class Solution1 {
public:
    int kthGrammar(int N, int k){
        if (N == 1)
            return 0;
        int lastk = kthGrammar(N - 1, (k + 1) / 2);
        if ((lastk == 0 && k % 2 == 1) || (lastk == 1 && k % 2 == 0))
            return 0;
        else if ((lastk == 0 && k % 2 == 0) || (lastk == 1 && k % 2 == 1))
            return 1;
        return 0; // 这个不写会报错 但是写了也没用 官方给的答案是 用了一个异或作为return
    }
};