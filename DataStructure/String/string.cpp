#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

// 测试一下s[i]的使用
// str[0] 到底是什么类型 是char 可以按照ASCII进行操作
// stoi(s[i]) 可以吗？ 不可以 直接减去 '0' 不就行了
// int main() {
//     // string s = '1'; // 错误
//     // string s = "123,";
//     // cout << s << endl;
//     // s.pop_back();
//     // cout << s << endl;
//     // cout << s[0] << endl;

//     // s[0] = (s[0] - 2 + 10);
//     // string str = "9000";
//     // str[0] = str[0] == 9 ? '0' : str[0] + 1; // 应该是'9' ASCII码值中 9的下一个就是 ：
//     // str[0] = '0';
//     // str[1] = 49;
//     // cout << s << endl;

//     // stoi(s[i])可以吗？ 不可以
//     string s = "123";
//     int num = stoi(s[0]);
//     cout << num << endl;
// }

// // 测试一下s.find()
// int main() {
//     string str = "asdfgh";
//     string t = "f";

//     // if (str.find(t) != str.npos)
//     //     cout << 1;
//     // else
//     //     cout << 0;

//     // if (str.find(t[0]) != str.npos)
//     //     cout << 1;
//     // else
//     //     cout << 0;

//     // if (str.find("s") != str.npos)
//     //     cout << 1;
//     // else
//     //     cout << 0;

//     if (str.find('s') != str.npos)
//         cout << 1;
//     else
//         cout << 0;

//     // if (str.find("ts") != str.npos)
//     //     cout << 1;
//     // else
//     //     cout << 0;
// }

// 测试一下 > < 的使用
// 按照字典序比大小
int main() {
    string s1 = "JFK";
    string s2 = "SFO";
    string s3 = "ATL";
    if (s1 > s2)
        cout << s1;
    else
        cout << s2;
    vector<string> v = {s1, s2, s3};
    sort(v.begin(), v.end(), greater<string>());
    return 0;
}

// 测试一下 s能不能转化成long
// int -2147483648 - 21474836487
// long 和 int 一样
// long long -9223372036854775808 -  9223372036854775807
// to_string() 都可以转
// int main() {
//     string s = "2147483648";
//     // cout << stol(s) << endl;
//     cout << to_string(-9223372036854775808) << endl;
//     return 0;
// }