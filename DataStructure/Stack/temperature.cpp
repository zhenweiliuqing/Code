#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> temp;
        for (int i = 0; i < T.size(); i++)
            temp.push(T[i]);
        for (int i = 0; i < T.size(); i++) {
            int tpra = temp.top();
            temp.pop();
            for (int j = i + 1; j < T.size(); j++) {
                if (tpra < T[j]) {
                    res[i] = j - i;
                    break;
                }
            }
        } 
        return res;
    }
};

class Solution1 {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {
        int n = temperatures.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = 0; i < temperatures.size(); ++i) {
            while (!st.empty() && temperatures[i] > temperatures[st.top()]) {
                auto t = st.top(); 
                st.pop();
                res[t] = i - t;
            }
            st.push(i); // 把下标push进去
        }
        return res;
    }
};

class Solution{
public:
    vector<int> dailyTemperatures(vector<int>& T) {
        vector<int> res(T.size(), 0);
        stack<int> st;
        for (int i = 0; i < T.size(); i++) {
            while (!st.empty() && T[i] > T[st.top()]) {
                int temp = st.top();
                st.pop();
                res[temp] = i - temp;
            }
            st.push(i);                
        }
        
        // queue<int> temp;
        // for (int i = 0; i < T.size(); i++)
        //     temp.push(T[i]);
        // for (int i = 0; i < T.size(); i++) {
        //     int tpra = temp.front();
        //     temp.pop();
        //     for (int j = i + 1; j < T.size(); j++) {
        //         if (tpra < T[j]) {
        //             res[i] = j - i;
        //             break;
        //         }
        //     }
        // } 
        return res;
    }
};

int main() {
    int input[] = {73, 74, 75, 71, 69, 72, 76, 73};
    vector<int> t;
    for (int i = 0; i < 8; i++)
        t.push_back(input[i]);
    Solution sol;
    vector<int> res = sol.dailyTemperatures(t);
    return 0;
}

