// 2-14
#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
    bool verifyPostorder(vector<int>& postorder, int st, int end) {
        // 只有 == 不行
        if (st >= end)
            return true;
        
        int leftidx = st;
        while (leftidx < end && postorder[leftidx] < postorder[end])
            leftidx++;
        leftidx--;

        for (int i = leftidx + 1; i <= end - 1; i++) {
            if (postorder[i] < postorder[end]) {
                return false;
            }
        }

        return verifyPostorder(postorder, st, leftidx) && verifyPostorder(postorder, leftidx + 1, end -  1);
    }
};
// 通过了

// 5-4 
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
    bool verifyPostorder(vector<int>& postorder, int st, int end) {
        if (st >= end)
            return true;
        
        // [1, 2, 3, 4, 5] 这种情况找的leftroot不对 应该是4
        int leftidx = st;
        for (int i = st + 1; i < end; i++) {
            // 这里没有 > 的 leftidx = st对吗
            if (postorder[i] > postorder[end]) {
                leftidx = i - 1;
                break;
            }
        }

        for (int i = leftidx + 1; i <= end - 1; i++) {
            if (postorder[i] < postorder[end]) {
                return false;
            }
        }

        return verifyPostorder(postorder, st, leftidx) && verifyPostorder(postorder, leftidx + 1, end -  1);
    }
};


// 判断二叉树是不是后序遍历
// 先找到左子树和右子树区分的间隔点 左子树都都小于root
class Solution {
public:
    bool verifyPostorder(vector<int>& postorder, int start, int end) {
        if (start > end)
            return true;
        int root = postorder[end];
        int rightSt = start;
        while (postorder[rightSt] < root && rightSt <= end)
            rightSt++;
        
        for (int i = rightSt; i <= end; i++) {
            if (postorder[i] < root)
                return false;
        }
        bool ans = verifyPostorder(postorder, start, rightSt - 1) && verifyPostorder(postorder, rightSt, end - 1);
        return ans;
    }
    bool verifyPostorder(vector<int>& postorder) {
        return verifyPostorder(postorder, 0, postorder.size() - 1);
    }
};
// 一次通过 真好


// return false的条件在右侧判定 就没问题了
// 3-18
// class Solution {
//     public boolean verifyPostorder(int[] postorder) {
//         int n = postorder.length;
//         if (n == 0)
//             return true;
//         return verifyPostorder(postorder, 0, n - 1);
//     }
//     public boolean verifyPostorder(int[] postorder, int start, int end) {
//         if (start > end)
//             return true;
//         int root = postorder[end];
//         int leftRoot = start;

//         while (postorder[leftRoot] < root && leftRoot <= end)
//             leftRoot++;

//         for (int i = leftRoot; i <= end - 1; i++) {
//             if (postorder[i] < root)
//                 return false;
//         }

//         return verifyPostorder(postorder, start, leftRoot - 1) && verifyPostorder(postorder, leftRoot, end - 1);
//     }

// }






// class Solution {
//     public boolean verifyPostorder(int[] postorder) {
//         int n = postorder.length;
//         if (n == 0)
//             return false;
//         return verifyPostorder(postorder, 0, n - 1);
//     }
//     public boolean verifyPostorder(int[] postorder, int start, int end) {
//         if (start > end)
//             return false;
//         if (start == end)
//             return true;
//         int root = postorder[end];
//         int right = end - 1;

//         int len = 0;
//         for (int i = right; i >= start; i--) {
//             if (postorder[i] < root) {
//                 len = right - i;
//                 break;
//             }
//         }
            // 在左侧就不行
//         for (int i = start; i <= right - len; i++) {
//             if (postorder[i] > root)
//                 return false;
//         }

//         return verifyPostorder(postorder, start, right - len) && verifyPostorder(postorder, right - len + 1, right);
//     }

// }