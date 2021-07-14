#include <iostream>
#include <queue>
#include <cmath>
#include <vector>
using namespace std;

class Solution {
public:
    int numSquares(int n) {
        if (n == 0)                                         
            return 0;
        int steps = 0, tempSize, tempValue;
        queue<int> myQue; // 定义一个队列
        myQue.push(n); // 先把n push进去
        while (!myQue.empty()) { 
            tempSize = myQue.size(); // 暂时的size 不是一直都是1 
            for (int i = 0; i < tempSize; ++i) {
                tempValue = myQue.front(); // 第一个值
                myQue.pop(); 

                for (int j = sqrt(tempValue); j > 0; --j) { // 这个从大到小 从小到大没有关系
                    if (tempValue == j * j)
                        return steps + 1;
                    else 
                        myQue.push(tempValue - j * j); // 把减去平方数后的值push进去 3 8 11
                }
            }
            steps += 1;
        }
        return 0;
    }
};

// 好像可以用深度优先搜索的思想来写
vector<int> num;
int step = 1;
int n;
void getnum(int n) {
    for (int i = 1; i * i < n; i++)
        num.push_back(i*i);
}
void dfs(int step, int temp) {
    if (temp > n)
        return;
    while (temp < n) {
        for (int i = 0; i < num.size(); i++) {
            
        }
    }
}