#include <string>
#include <unordered_set>
using namespace std;

// 6-5
class Solution {
public:
    bool checkIfPangram(string sentence) {
        unordered_set<char> uset;
        for (auto c : sentence) {
            uset.insert(c);
        }
        return uset.size() == 26;
    }
};
// 通过了