// 4-17
// 看看一个句子中能不能插入一个句子 就是用双指针
class Solution {
public:
//     bool isValid(vector<string> s1, vector<string> s2) {
//         if (s1.size() < s2.size())
//             return isValid(s2, s1);
//         unordered_set<string> sset;
//         for (int i = 0; i < s1.size(); i++)
//             sset.insert(s1[i]);
//         for (int i = 0; i < s2.size(); i++) {
//             if (sset.count(s2[i]) == sset.end())
//                 return false;
//         }
//         return true;
//     }
    
//     bool isHeadorTail(vector<string> s1, vector<string> s2) {
//         if (s1[0] != s2[0] && s1[s1.size() - 1] != s2[s2.size() - 1])
//             return false;
//         return true;
//     }
    
    bool canInsert(vector<string> s1, vector<string> s2) {
        if (s1.size() < s2.size())
            return canInsert(s2, s1);
        int left1 = 0, right1 = s1.size() - 1;
        int left2 = 0, right2 = s2.size() - 1;
        while (left2 < s2.size() && s2[left2] == s1[left1]) {
            left1++;
            left2++;            
        }
        while (right2 >= 0 && s2[right2] == s1[right1]) {
            right1--;
            right2--;
        }
        return left2 > right2;
    }
    
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1, s2;
        sentence1 += ' ';sentence2 += ' ';
        int st = 0;
        for (int i = 0; i < sentence1.size(); i++) {
            if (sentence1[i] == ' ') {
                s1.push_back(sentence1.substr(st, i - st));
                st = i + 1;
            }
        }
        st = 0;
        for (int i = 0; i < sentence2.size(); i++) {
            if (sentence2[i] == ' ') {
                s2.push_back(sentence2.substr(st, i - st));
                st = i + 1;
            }
        }
        return canInsert(s1, s2);
    }
};