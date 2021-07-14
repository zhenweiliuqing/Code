#include <string>
#include <map>
#include <set>
#include <iostream>
#include <unordered_map>
using namespace std;

// class Solution {
// public:
//     // 如何判断t在temp里都有 应该把temp变成一个set
//     // target 可能是"aa" 所以还得用map
//     map<char, int> mt;
//     bool containst(string t, string temp) {
//         map<char, int> mtemp;
//         for (int i = 0; i < temp.size(); i++) {
//             mtemp[temp[i]]++;
//         }
//         // 需要判断一下mtemp里的个数是否大于mt里的个数
//         for (int i = 0; i < t.size(); i++) {
//             if (mtemp[t[i]] < mt[t[i]])
//                 return false;
//         }
//         return true;
//     }
//     string minWindow(string s, string t) {
//         int left = 0, right = 0;
//         int len = s.size();
//         string ans = "";

//         for (int i = 0; i < t.size(); i++)
//             mt[t[i]]++;
        
//         while (right < len) {
//             string temp = s.substr(left, right - left + 1);
//             if (containst(t, temp)) {
//                 left++;
//                 if (ans == "")
//                     ans = temp;
//                 if (ans.size() > temp.size())
//                     ans = temp;
//             } else if (!containst(t, temp)) {
//                 right++;
//             }
//         }
//         return ans;
//     }
// };
// // 超时了

// int main() {
//     string s = "tfsxfpbgrvlgngmrtgotjumbaxosseklkckrrlzljnrytfpolgjxcvycvounteafgkyaxylgleeglwuycfvecvgxmbmfhmmoykoykbgxhndsjzqneorjlzgxctckhqaibqgnrolybqskskxyyqhmqojsjocqeeyhugvlvglwwfjqqipqzwcrmmjvcoogsmopvjaqroontzglivcjtgagslbwbpdwetlbcnrtdhizhokploafvanpnqmpirnmkynmnghrnrqwicltrlaonndbersmihyshnguvplkhdhpgukxillvyqycksoszongdvbyloluusjamvzugmsfesjolahkqwturuuekhyezjgoffilrcswvekgetsurlqjhnpuuoywxfkcmuqexicumocsiupbihkrwclrqkpnrzsdvijuslohaqzknqlxyyouaansmehddzibjuvcfkjhcktrdhobhdxjfnbrriwxkgytatvifgpktlbwsqxzvwiajltdtradxazytugbdxlwimscerbbnldzwwcspexnewnzrvausnsdckfibhkquprrmvjdzgqfdffwahsvxkyzwdhzmtpjjhaxclaettjyyqwbaqwxauyyzfxobpxkyzjakjgfesediaekrchtwhuxnrlqikcgjljvwpbbhfgshmcaomwmtqjijxysjaatnjokzrlgwragddirrefkwqvintazwasjkitlaetyxueazptqtycsrxaetcfpcxaogwbicvgarncqcwixwmpnkpufrzwwzwmhsopvlxxckzumxcmwoblatffmhbiiaxpulgrydoaqquenyqjouvpncwzlaktahkwuqouweumuqqiohtcbotqtqpesbyukiqgbgaxlujfkzpagjfjzyzsqrxksxedfvjidkfogowtqltyuaiubjoraletiiyqfhyjtgzcuvvkhqjdrtzucoldbrymaweffcqbkqdflyruqcyjvzd";
//     string t = "ynrdribdizhqelgfwwid";
//     Solution sol;
//     string ans = sol.minWindow(s, t);
//     cout << ans;
//     // ehddzibjuvcfkjhcktrdhobhdxjfnbrriwxkgytatvifgpktlbwsq
// }

// // "tfsxfpbgrvlgngmrtgotjumbaxosseklkckrrlzljnrytfpolgjxcvycvounteafgkyaxylgleeglwuycfvecvgxmbmfhmmoykoykbgxhndsjzqneorjlzgxctckhqaibqgnrolybqskskxyyqhmqojsjocqeeyhugvlvglwwfjqqipqzwcrmmjvcoogsmopvjaqroontzglivcjtgagslbwbpdwetlbcnrtdhizhokploafvanpnqmpirnmkynmnghrnrqwicltrlaonndbersmihyshnguvplkhdhpgukxillvyqycksoszongdvbyloluusjamvzugmsfesjolahkqwturuuekhyezjgoffilrcswvekgetsurlqjhnpuuoywxfkcmuqexicumocsiupbihkrwclrqkpnrzsdvijuslohaqzknqlxyyouaansmehddzibjuvcfkjhcktrdhobhdxjfnbrriwxkgytatvifgpktlbwsqxzvwiajltdtradxazytugbdxlwimscerbbnldzwwcspexnewnzrvausnsdckfibhkquprrmvjdzgqfdffwahsvxkyzwdhzmtpjjhaxclaettjyyqwbaqwxauyyzfxobpxkyzjakjgfesediaekrchtwhuxnrlqikcgjljvwpbbhfgshmcaomwmtqjijxysjaatnjokzrlgwragddirrefkwqvintazwasjkitlaetyxueazptqtycsrxaetcfpcxaogwbicvgarncqcwixwmpnkpufrzwwzwmhsopvlxxckzumxcmwoblatffmhbiiaxpulgrydoaqquenyqjouvpncwzlaktahkwuqouweumuqqiohtcbotqtqpesbyukiqgbgaxlujfkzpagjfjzyzsqrxksxedfvjidkfogowtqltyuaiubjoraletiiyqfhyjtgzcuvvkhqjdrtzucoldbrymaweffcqbkqdflyruqcyjvzd"
// // "ynrdribdizhqelgfwwid"

// // labuladong
// string minWindow(string s, string t) {
//     unordered_map<char, int> need, window;
//     for (char c : t)
//         need[c]++;

//     int left = 0, right = 0;
//     int valid = 0;
//     int start = 0, len = INT_MAX;
//     while (right < s.size()) {
//         char c = s[right];
//         right++;
//         if (need.count(c)) {
//             window[c]++;
//             if (window[c] == need[c])
//                 valid++;
//         }

//         while (valid == need.size()) {
//             if (right - left < len) {
//                 start = left;
//                 len = right - left;
//             }

//             char d = s[left];
//             left++;
//             if (need.count(d)) {
//                 if (window[d] == need[d])
//                     valid--;
//                 window[d]--;
//             }
//         }
//     }
//     return len == INT_MAX ? "" : s.substr(start, len);
// }

class Solution {
public: 
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int len = s.size();
        string ans = "";

        unordered_map<char, int> target;
        unordered_map<char, int> win;
        for (int i = 0; i < t.size(); i++)
            target[t[i]]++;

        int valid = 0;
        while (right <= len) {
            if (valid == target.size()) {
                if (ans == "")
                    ans = s.substr(left, right - left);
                if (ans.size() > (right -left))
                    ans = s.substr(left, right - left);
                
                char c = s[left];
                left++;
                if (target.count(c) != 0) {
                    if (win[c] == target[c])
                        valid--;
                    win[c]--;
                }
            } else {
                char c = s[right];
                right++;
                // 这几行代码是核心 通过valid判断是否
                if (target.count(c) != 0) {
                    win[c]++;
                    if (win[c] == target[c]) // 多余的也不会多记
                        valid++;
                }
            }
        }
        return ans;
    }
};
// 通过了 但是感觉有问题 right是不是越界了 但是好像不影响
// 大体思路是正确的 细节部分不太一样

class Solution {
public: 
    string minWindow(string s, string t) {
        int left = 0, right = 0;
        int len = s.size();
        string ans = "";

        unordered_map<char, int> target;
        unordered_map<char, int> win;
        for (int i = 0; i < t.size(); i++)
            target[t[i]]++;

        int valid = 0;
        while (right < len) {
            char c = s[right];
            if (target.count(c) != 0) {
                win[c]++;
                if (win[c] == target[c])
                    valid++;
            }
            right++;

            while (valid == target.size()) {
                if (ans == "")
                    ans = s.substr(left, right - left);
                if (ans.size() > (right -left))
                    ans = s.substr(left, right - left);
                
                char c = s[left];
                if (target.count(c) != 0) {
                    if (win[c] == target[c])
                        valid--;
                    win[c]--;
                }
                left++;
            }
        }
        return ans;
    }
};
// 这种就没有问题了


int main() {
    // string s = "tfsxfpbgrvlgngmrtgotjumbaxosseklkckrrlzljnrytfpolgjxcvycvounteafgkyaxylgleeglwuycfvecvgxmbmfhmmoykoykbgxhndsjzqneorjlzgxctckhqaibqgnrolybqskskxyyqhmqojsjocqeeyhugvlvglwwfjqqipqzwcrmmjvcoogsmopvjaqroontzglivcjtgagslbwbpdwetlbcnrtdhizhokploafvanpnqmpirnmkynmnghrnrqwicltrlaonndbersmihyshnguvplkhdhpgukxillvyqycksoszongdvbyloluusjamvzugmsfesjolahkqwturuuekhyezjgoffilrcswvekgetsurlqjhnpuuoywxfkcmuqexicumocsiupbihkrwclrqkpnrzsdvijuslohaqzknqlxyyouaansmehddzibjuvcfkjhcktrdhobhdxjfnbrriwxkgytatvifgpktlbwsqxzvwiajltdtradxazytugbdxlwimscerbbnldzwwcspexnewnzrvausnsdckfibhkquprrmvjdzgqfdffwahsvxkyzwdhzmtpjjhaxclaettjyyqwbaqwxauyyzfxobpxkyzjakjgfesediaekrchtwhuxnrlqikcgjljvwpbbhfgshmcaomwmtqjijxysjaatnjokzrlgwragddirrefkwqvintazwasjkitlaetyxueazptqtycsrxaetcfpcxaogwbicvgarncqcwixwmpnkpufrzwwzwmhsopvlxxckzumxcmwoblatffmhbiiaxpulgrydoaqquenyqjouvpncwzlaktahkwuqouweumuqqiohtcbotqtqpesbyukiqgbgaxlujfkzpagjfjzyzsqrxksxedfvjidkfogowtqltyuaiubjoraletiiyqfhyjtgzcuvvkhqjdrtzucoldbrymaweffcqbkqdflyruqcyjvzd";
    // string t = "ynrdribdizhqelgfwwid";

    string s = "ADOBECODEBANC";
    string t = "ABC";
    Solution sol;
    string ans = sol.minWindow(s, t);
    cout << ans;
    // ehddzibjuvcfkjhcktrdhobhdxjfnbrriwxkgytatvifgpktlbwsq

    // unordered_map<char, int> mmap;
    // if (mmap.count('A') == 0) // 不会插入A
    //     mmap['B'] = 1;
    // mmap['s']++;
    // cout << mmap.size() << endl;
}