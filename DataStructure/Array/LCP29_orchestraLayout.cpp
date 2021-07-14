// 4-5
#include <iostream>
#include <algorithm>
using namespace std;

// 一个表达式中如果有int还是不行 layer也得是long
class Solution {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        long layer = min(min(xPos, num - xPos - 1), min(yPos, num - yPos - 1));
        long cnt = 0;

        // 化简之后
        cnt = (num * layer * 4 - layer * layer * 4) % 9;
        xPos -= layer;
        yPos -= layer;
        long size = num - layer * 2; // 这里也很关键 不能用原来的num直接减

        if (xPos == 0) {
            cnt += yPos + 1;
        } else if (yPos == size - 1) {
            cnt += size + xPos;
        } else if (xPos == size - 1) {
            cnt += size * 2 - 1 + (size - yPos - 1);
        } else if (yPos == 0) {
            cnt += (size * 2 + size - 2) + (size - 1 - xPos);
        }
        return cnt % 9 == 0 ? 9 : cnt % 9;
    }
};

// 终于通过了
// 主要就是int会越界
class Solution1 {
public:  
    int orchestraLayout(int num, int xPos, int yPos) {
        int layer = min(min(xPos, num - xPos - 1), min(yPos, num - yPos - 1));
        int cnt = 0;

        // cnt有可能是负数
        cnt = (num % 9) * (num % 9) - ((num - layer * 2) % 9) * ((num - layer * 2) % 9);
        // 化简之后
        // cnt = ((num % 9) * (layer % 9) * 4) - ((layer % 9) * (layer % 9) * 4) % 9;

        num -= layer * 2;
        xPos -= layer;
        yPos -= layer;

        if (xPos == 0) {
            cnt += yPos + 1;
        } else if (yPos == num - 1) {
            cnt += num % 9 + xPos;
        } else if (xPos == num - 1) {
            cnt += num * 2 % 9 - 1 + (num - yPos - 1);
        } else if (yPos == 0) {
            cnt += (num * 2 % 9 + num % 9 - 2) + (num - 1 - xPos);
        }
        return cnt % 9 == 0 ? 9 : (cnt % 9 + 9) % 9;
    }
};

class Solution2 {
public:
    // 思路可以 int 越界
    int orchestraLayout1(int num, long long start, int xPos, int yPos) {
        long long cnt = 0;
        if (xPos == 0) {
            cnt = yPos + 1;
        } else if (yPos == num - 1) {
            cnt = num + xPos;
        } else if (xPos == num - 1) {
            cnt = num * 2 - 1 + (num - yPos - 1);
        } else if (yPos == 0) {
            cnt = (num * 2 + num - 2) + (num - 1 - xPos);
        }
        cnt += start;
        if (cnt != start)
            return cnt % 9 == 0 ? 9 : cnt % 9;
        return orchestraLayout1(num - 2, start + 4 * (num - 1), xPos - 1, yPos - 1);
    }
    
    int orchestraLayout(int num, int xPos, int yPos) {
        return orchestraLayout1(num, 0, xPos, yPos);
    }
};


// * / %是同一优先级
class Solution3 {
public:
    int orchestraLayout(int num, int xPos, int yPos) {
        int layer = min(min(xPos, num - xPos - 1), min(yPos, num - yPos - 1));
        int cnt = 0;
        // 一圈一圈的算 还是会超时
        // for (int i = 0; i < layer; i++) {
        //     cnt += ((num - 1) % 9) * 4 % 9;
        //     num -= 2;
        //     xPos--;yPos--;
        // }
        cnt = (num % 9) * (num % 9) - ((num - layer * 2) % 9) * ((num - layer * 2) % 9);

        num -= layer * 2;
        xPos -= layer;
        yPos -= layer;

        if (xPos == 0) {
            cnt += yPos + 1;
        } else if (yPos == num - 1) {
            cnt += num % 9 + xPos;
        } else if (xPos == num - 1) {
            cnt += num * 2 % 9 - 1 + (num - yPos - 1);
        } else if (yPos == 0) {
            cnt += (num * 2 % 9 + num % 9 - 2) + (num - 1 - xPos);
        }
        return cnt % 9 == 0 ? 9 : cnt % 9;
    }
};

int main() {
    // Solution sol;
    // int ans = sol.orchestraLayout(703903667, 271180214, 370227364);
    // int ans = sol.orchestraLayout(3690, 807, 814);
    // int ans = sol.orchestraLayout(8876, 217, 97);
    cout << sizeof(char) << endl;
}