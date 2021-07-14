// 3-6
#include <list>
#include <vector>
#include <iostream>
using namespace std;

class Solution {
public:
    int lastRemaining(int n, int m) {
        list<int> nums;
        for (int i = 0; i < n; i++)
            nums.push_back(i);

        auto cur = nums.begin();
        while (nums.size() > 1) {
            for (int i = 1; i < m; i++) {
                cur++;
                if (cur == nums.end())
                    cur = nums.begin();
            }

            // auto next = cur++; // 会报错
            cur++;
            auto next = cur;
            if (next == nums.end())
                next = nums.begin();
            cur--;
            nums.erase(cur);
            cur = next;
        }
        return *cur;
    }
};
// 超时了

// 数学方法
class Solution {
public:
    int lastRemaining(int n, int m) {
        if (n == 1)
            return 0;
        return (lastRemaining(n - 1, m) + m) % n;
    }
};

class Solution {
public:
    int lastRemaining(int n, int m) {
        int last = 0; // n = 1的情况
        for (int i = 2; i <= n; i++)
            last = (last + m) % i;
        return last;
    }
};
// 我们有n个数，下标从0到n-1，然后从index=0开始数，每次数m个数，最后看能剩下谁。我们假设能剩下的数的**下标**为y，则我们把这件事表示为

// f(n,m) = y
// 这个y到底表示了啥呢？注意，y是下标，所以就意味着你从index=0开始数，数y+1个数，然后就停，停谁身上谁就是结果。

// 行了，我们假设f(n-1,m)=x，然后来找一找f(n,m)和f(n-1,m)到底啥关系。

// f(n-1,m)=x意味着啥呢？意味着有n-1个数的时候从index=0开始数，数x+1个数你就找到这结果了。那我不从index=0开始数呢？比如我从index=i开始数？那很简单，你把上面的答案也往后挪i下，就得到答案了。当然了，你要是挪到末尾了你就取个余，从头接着挪。

// 于是我们来思考f(n,m)时考虑以下两件事：

// 有n个数的时候，要划掉一个数，然后就剩n-1个数了呗，那划掉的这个数，**下标**是多少？
// 划完了这个数，往后数，数x+1个数，停在谁身上谁就是我们的答案。当然了，数的过程中你得取余
// **问题一**：有n个数的时候，划掉了谁？**下标**是多少？

// 因为要从0数m个数，那最后肯定落到了下标为m-1的数身上了，但这个下标可能超过我们有的最大下标（n-1）了。所以攒满n个就归零接着数，逢n归零，所以要模n。

// 所以有n个数的时候，我们划掉了下标为(m-1)%n的数字。

// **问题二**：我们划完了这个数，往后数x+1下，能落到谁身上呢，它的下标是几？

// 你往后数x+1，它下标肯定变成了(m-1)%n +x+1，和第一步的想法一样，你肯定还是得取模，所以答案为[(m-1)%n+x+1]%n，则

// f(n,m)=[(m-1)%n+x+1]%n
// 其中x=f(n-1,m)

// 我们化简它！

// 定理一：两个正整数a，b的和，模另外一个数c，就等于它俩分别模c，模完之后加起来再模。

// (a+b)%c=((a%c)+(b%c))%c
// 定理二：一个正整数a，模c，模一遍和模两遍是一样的。

// a%c=(a%c)%c
// 你稍微一琢磨就觉得，嗯，说得对。

// 所以

// f(n,m)=[(m-1)%n+x+1]%n
//       =[(m-1)%n%n+(x+1)%n]%n
//       =[(m-1)%n+(x+1)%n]%n
//       =(m-1+x+1)%n
//       =(m+x)%n
// 剩下的故事你们就都知道了。