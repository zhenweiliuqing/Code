#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> ans;
        vector<string> sorted;
        string temp;
        for (int i = 0; i < strs.size(); i++) {
            temp = strs[i];
            sort(temp.begin(), temp.end());
            
            int j = 0;
            for (j = 0; j < sorted.size(); j++){
                if (temp == sorted[j]) {
                    ans[j].push_back(strs[i]);
                    break;
                }
            }
            if (j == sorted.size()) {
                sorted.push_back(temp);
                ans.resize(j + 1); // resize 不会清除之前的数据
                ans[j].push_back(strs[i]);
            }    
        }
        return ans;
    }
};

// 竟然一下通过了！！
