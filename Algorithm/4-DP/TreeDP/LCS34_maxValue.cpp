// 4-11
#include <iostream>
#include <unordered_map>
using namespace std;
// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

class Solution {
public:
    unordered_map<TreeNode*, int[11]> mmap;
    int K;
    int dfs(TreeNode* root, int k) {
        if (root == NULL)
            return 0;
        // 判断root存在 且 mmap[root][k]有数 因为初始为0
        if (mmap.count(root) != 0 && mmap[root][k] > 0)
            return mmap[root][k];
        int ans = 0;
        // root不选择
        ans = dfs(root->left, K) + dfs(root->right, K);
        // root选择
        for (int i = 0; i < k; i++) {
            ans = max(ans, root->val + dfs(root->left, i) + dfs(root->right, k - 1 - i));
        }
        mmap[root][k] = ans;
        return ans;
    }

    int maxValue(TreeNode* root, int k) {
        K = k;
        return dfs(root, k);
    }    
};

int main() {
    Solution sol;
    // TreeNode *tree = new TreeNode(2);
    sol.maxValue(new TreeNode(2), 2);
}

// 第一名解法
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
// class Solution1 {
// public:
// 	vector<int> dfs(TreeNode* root, int k){
// 		if (root==NULL){
// 			vector<int> res;
// 			res.push_back(0);
// 			return res;
// 		}
// 		vector<int> vl=dfs(root->left ,k);
// 		vector<int> vr=dfs(root->right ,k);
// 		vector<int> res;
// 		res.resize(k+1);
// 		for (int i=0;i<vl.size();i++)
// 			for (int j=0;j<vr.size();j++){
// 				res[0]=max(res[0],vl[i]+vr[j]);
// 				if (i+j+1<=k)
// 					res[i+j+1]=max(res[i+j+1],vl[i]+vr[j]+root->val);
// 			}
// 		return res;
// 	}
//     int maxValue(TreeNode* root, int k) {
// 		vector<int> result=dfs(root,k);
// 		int ans=0;
// 		for (int i=0;i<=result.size();i++)
// 			if (i<=k) ans=max(ans,result[i]);
// 		return ans;
//     }
// };