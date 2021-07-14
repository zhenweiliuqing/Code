// 3-16
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> qNode;
        queue<int> qVal;
        qNode.push(root);
        qVal.push(1);

        int ans = 1;
        while (!qNode.empty()) {
            int n = qNode.size();
            int left = INT_MAX, right = 0;
            
            for (int i = 0; i < n; i++) {
                TreeNode* node = qNode.front();
                qNode.pop();
                int tmp = qVal.front();
                if (tmp < left)
                    left = tmp;
                if (tmp > right)
                    right = tmp;
                qVal.pop();

                if (node->left != NULL) {
                    qNode.push(node->left);
                    qVal.push(tmp * 2 - 1);
                } 
                if (node->right != NULL) {
                    qNode.push(node->right);
                    qVal.push(tmp * 2);
                }
            }
            if (left != INT_MAX && right != 0)
                ans = max(ans, right - left + 1);
        }
        return ans;
    }
    
};

class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> qNode;
        root->val = 1;
        qNode.push(root);
        
        int ans = 1;
        while (!qNode.empty()) {
            int n = qNode.size();
            ans = max(ans, qNode.back()->val - qNode.front()->val + 1);
            int tmp = qNode.front()->val - 1;

            for (int i = 0; i < n; i++) {
                TreeNode* node = qNode.front();
                qNode.pop();
                node->val -= tmp; // 把front变为1

                if (node->left != NULL) {
                    node->left->val = node->val * 2 - 1;
                    qNode.push(node->left);
                } 
                if (node->right != NULL) {
                    node->right->val = node->val * 2;
                    qNode.push(node->right);
                }
            }
        }
        return ans;
    }
};
// 通过了！


// 这种方法简洁些 
// 错误都是越界了 不能用int 表示
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == NULL)
            return 0;
        queue<TreeNode*> qNode;
        root->val = 1;
        qNode.push(root);
        
        int ans = 1;
        while (!qNode.empty()) {
            int n = qNode.size();
            ans = max(ans, qNode.back()->val - qNode.front()->val + 1);
            
            for (int i = 0; i < n; i++) {
                TreeNode* node = qNode.front();
                qNode.pop();

                if (node->left != NULL) {
                    node->left->val = node->val * 2 - 1;
                    qNode.push(node->left);
                } 
                if (node->right != NULL) {
                    node->right->val = node->val * 2;
                    qNode.push(node->right);
                }
            }
        }
        return ans;
    }
};


/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
 
class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (root == nullptr)
        {
            return 0;
        }

        // 保存最大的宽度
        int res = 0;

        // 队列用于广度优先遍历
        queue<TreeNode*> q;

        // 对于根节点的编号为0
        root->val = 0;
        q.push(root);

        while (!q.empty())
        {
            // 基于目前队列头和尾获得当前层的宽度
            res = max(res, q.back()->val - q.front()->val + 1);

            // 编号缩小的差值
            int offset = q.front()->val;

            // 遍历完当前层
            int n = q.size();
            for (int i = 0; i < n; ++i)
            {
                TreeNode* curr = q.front();
                q.pop();
                // 缩小数值
                curr->val -= offset;

                if (curr->left)
                {
                    // 转换为对应的编号
                    curr->left->val = curr->val*2;
                    q.push(curr->left);
                }
                if (curr->right)
                {
                    // 转换为对应的编号
                    curr->right->val = curr->val*2+1;
                    q.push(curr->right);
                }
            }
        }

        return res;
    }
};
// 作者：ffreturn


