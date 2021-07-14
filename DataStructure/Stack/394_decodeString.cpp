#include <iostream>
#include <stack>
#include <vector>
#include <string>
using namespace std;

class Solution {
public:
    string decodeString(string s) {
        string out;
        stack<string> st_str;
        stack<int> st_cnt;
        int mul = 0;
        string res = "";
        for (int i = 0; i < s.size(); i++) {
            if (s[i] >= '0' && s[i] <= '9') {
                mul = mul * 10 + s[i] - '0';
            } else if (s[i] == '[') {
                st_cnt.push(mul); // s[i]直接就是ASCII
                st_str.push(res); // 可以直接把之前的保存起来
                res = "";
                mul = 0;
            } else if (s[i] == ']') {
                int cur_mul = st_cnt.top();
                string last_res = st_str.top();
                st_cnt.pop();
                st_str.pop();
                for (int j = 0; j < cur_mul; j++)
                    last_res += res; // 用之前的res 加上现在的mul * res
                res = last_res;
            } else {
                res += s[i];
            }
        }
        return res;
    }
};