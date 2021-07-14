#include <queue>
using namespace std;

//   Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// 5-17
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        queue<pair<TreeNode*, int>> q;
        // q.push(make_pair(root, 0));
        q.push({root, 0});
        while (!q.empty()){
            int size = q.size();
            int xp = 0, yp = 0;
            for (int i = 0; i < size; i++)
            {
                auto tmp = q.front();
                q.pop();
                if (tmp.first->val == x)
                    xp = tmp.second;
                if (tmp.first->val == y)
                    yp = tmp.second;

                if (tmp.first->left != nullptr)
                    q.push(make_pair(tmp.first->left, tmp.first->val));

                if (tmp.first->right != nullptr)
                    q.push(make_pair(tmp.first->right, tmp.first->val));
            }
            if (xp != 0 && yp != 0 && xp != yp)
                return true;
        }
        return false;
    }
};
// 通过了