// 2-26
// 心情太焦虑了 先做点简单的缓解一下焦虑情绪吧
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

// 思路：剑指offer上通过连接比较数字大小 进行排序然后连接起来
class Solution {
public:
    static bool cmp(int a, int b) {
        string str1 = to_string(a) + to_string(b);
        string str2 = to_string(b) + to_string(a);
        return str1 < str2;
    }
    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);
        string ans;
        for (int i = 0; i < nums.size(); i++)
            ans += to_string(nums[i]);
        return ans;
    }
};
// 通过了

// 这是因为所有我们在类内定义的非static成员函数在经过编译后隐式的为他们添加了一个this指针参数！变为了
// bool cmp(Solution *this, int a, int b)
// 而标准库的sort()函数的第三个cmp函数指针参数中并没有这样this指针参数，因此会出现输入的cmp参数和sort()要求的参数不匹配，从而导致了：
// error: reference to non-static member function must be called
// 而我们知道static静态类成员函数是不需要this指针的，因此改为静态成员函数即可通过！



int main() {
    string s1 = "123";
    string s2 = "124";
    bool flag;
    if (s1 < s2)
        flag = true;
    return 0;
}