#include <vector>
#include <string>
using namespace std;

// 6-27
class Solution {
public:
    int compareVersion(string version1, string version2) {
        vector<int> v1, v2;
        version1.push_back('.');
        version2.push_back('.');
        string tmp;
        for (int i = 0; i < version1.size(); ++i) {
            if (version1[i] == '.') {
                v1.push_back(stoi(tmp));
                tmp = "";
            } else {
                tmp += version1[i];
            }
        }
        for (int i = 0; i < version2.size(); ++i) {
            if (version2[i] == '.') {
                v2.push_back(stoi(tmp));
                tmp = "";
            } else {
                tmp += version2[i];
            }
        }
        int k = 0;
        while (k < v1.size() && k < v2.size()) {
            if (v1[k] < v2[k])
                return -1;
            else if (v1[k] > v2[k])
                return 1;
            k++;
        }
        while (k < v1.size()) {
            if (v1[k] > 0)
                return 1;
            k++;
        }
        while (k < v2.size()) {
            if (v2[k] > 0)
                return -1;
            k++;
        }
        return 0;
    }
};
// 通过了