#include <string>
using namespace std;

// 6-1
class Solution {
public:
    string minValue(string n, int x) {
        for (int i = 1; i < n.size(); i++) {
            if (n[i] > x + '0') {
                n.insert(n.begin() + i, x + '0');
                break;
            }
            if (i == n.size() - 1) {
                n.insert(n.end(), x + '0');
                break; // 一定要 break               
            }
        }
        return n;
    }
    string maxValue(string n, int x) {
        if (n[0] == '-')
            return minValue(n, x);

        // 找到第一个 < x的位置 放在他的左边
        // 不能等于 386 
        for (int i = 0; i < n.size(); i++) {
            if (n[i] < x + '0') {
                n.insert(n.begin() + i, x + '0');
                break;
            }
            if (i == n.size() - 1) {
                n.insert(n.end(), x + '0');
                break;                
            }
        }
        return n;
    }
};
// 通过了

int main() {
    Solution sol;
    sol.maxValue("-132", 3);
}