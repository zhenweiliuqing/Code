#include <iostream>
#include <vector>
#include <unordered_map>
#include <map>
using namespace std;

// typedef struct tagStudentInfo {  
//     int iID;  
//     string  strName;  
//     bool operator < (tagStudentInfo const& r) const {  
//         //这个函数指定排序策略，按iID排序，如果iID相等的话，按strName排序  
//         if(iID < r.iID)  return true;  
//         if(iID == r.iID) return strName.compare(r.strName) < 0;  
//         return false;
//     }
// } StudentInfo;

class Solution {
public:
    struct node {
        int a,b,c;
        // int a;
        const bool operator < (const node& T) const {
            if (a < T.a)
                return true;
            if (b < T.b)
                return true;
            return c < T.c;
        }
    };
    // unordered_map<node, bool> mmap;
    map<node, bool> mmap;

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        return isInterleave(s1, 0, s2, 0, s3, 0);
    }

    bool isInterleave(string& s1, int idx1, string& s2, int idx2, string& s3, int idx3) {
        if (idx3 == s3.size())
            return true;
        node tmp = {idx1, idx2, idx3};
        if (mmap.count(tmp) != 0)
            return mmap[tmp];

        bool ans1 = false, ans2 = false;
        if (idx1 < s1.size() && s3[idx3] == s1[idx1])
            ans1 = isInterleave(s1, idx1 + 1, s2, idx2, s3, idx3 + 1);
        if (idx2 < s2.size() && s3[idx3] == s2[idx2])
            ans2 = isInterleave(s1, idx1, s2, idx2 + 1, s3, idx3 + 1);
        mmap[tmp] = (ans1 || ans2);
        return (ans1 || ans2);
    }
};
// 思路没错 就是不知道怎么写struct 作为map的key

int main() {
    Solution sol;
    sol.isInterleave("123", "123", "123123");
    return 0;
}

// bool值通过了99/103个测试用例 false不知道是初始化还是真的false
class Solution {
public:
    // bool mmap[101][101][201];
    vector<vector<vector<char>>> mmap = vector<vector<vector<char>>>(101, vector<vector<char>>(101, vector<char>(201, -1)));

    bool isInterleave(string s1, string s2, string s3) {
        if (s1.size() + s2.size() != s3.size())
            return false;
        return isInterleave(s1, 0, s2, 0, s3, 0);
    }

    bool isInterleave(string& s1, int idx1, string& s2, int idx2, string& s3, int idx3) {
        // static 会出现错误 因为之前的状态没有清除
        // static vector<vector<vector<char>>> mmap(101, vector<vector<char>>(101, vector<char>(201, -1)));
        if (idx3 == s3.size())
            return true;
        if (mmap[idx1][idx2][idx3] != -1)
            return mmap[idx1][idx2][idx3];
        // node tmp = {idx1, idx2, idx3};
        // if (mmap.count(tmp) != 0)
        //     return mmap[tmp];

        bool ans1 = false, ans2 = false;
        if (idx1 < s1.size() && s3[idx3] == s1[idx1])
            ans1 = isInterleave(s1, idx1 + 1, s2, idx2, s3, idx3 + 1);
        if (idx2 < s2.size() && s3[idx3] == s2[idx2])
            ans2 = isInterleave(s1, idx1, s2, idx2 + 1, s3, idx3 + 1);
        // mmap[tmp] = (ans1 || ans2);
        if (ans1 || ans2)
            mmap[idx1][idx2][idx3] = 1;
        else
            mmap[idx1][idx2][idx3] = 0;
        return (ans1 || ans2);
    }
};
// 通过了 但是效率很低 只超过了5%