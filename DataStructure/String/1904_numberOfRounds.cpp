#include <string>
using namespace std;

// 6-20
class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int hour1 = stoi(startTime.substr(0, 2));
        int hour2 = stoi(finishTime.substr(0, 2));

        int min1 = stoi(startTime.substr(3, 2));
        int min2 = stoi(finishTime.substr(3, 2));
        if (hour2 < hour1 || (hour2 == hour1 && min2 < min1))
            hour2 += 24;
        int h = hour2 - hour1;
        
        if (min1 != 0 && min1 != 15 && min1 != 45)
            min1 = (min1 / 15) * 15 + 15;
        if (min2 != 0)
            min2 = (min2 / 15) * 15;
        if (min2 < min1) {
            --h;
            min2 += 60;
        }
        int m = min2 - min1;
        
        int ans = (h * 60 + m) / 15;
        return ans < 0 ? 0 : ans;
    }
};
// 通过了 
int main() {
    Solution sol;
    string s1 = "12:01";
    string s2 = "12:46";
    sol.numberOfRounds(s1, s2);
}