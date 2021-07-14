#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

// 5-2
class Solution {
public:
    TreeNode* dfs(vector<int>& nums, int st, int end) {
        if (st > end)
            return nullptr;
        int maxValue = nums[st], idx = st;
        for (int i = st + 1; i <= end; i++) {
            if (maxValue < nums[i]) {
                maxValue = nums[i];
                idx = i;
            }
        }

        TreeNode* root = new TreeNode(maxValue);
        root->left = dfs(nums, st, idx - 1);
        root->right = dfs(nums, idx + 1, end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        return dfs(nums, 0, nums.size() - 1);
    }
};
// 通过

class Solution {
public:
    TreeNode* dfs(const vector<int>& nums, int st, int end) {
        if (st > end) 
            return nullptr;
        int max = nums[st], mid = st;
        for (int i = st + 1; i <= end; i++) {
            if (nums[i] > max) {
                max = nums[i];
                mid = i;
            }
        }
        TreeNode* root = new TreeNode(max);
        root->left = dfs(nums, st, mid - 1);
        root->right = dfs(nums, mid + 1, end);
        return root;
    }

    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        int n = nums.size();
        return dfs(nums, 0, n - 1);
    }
}; // 通过了

class Answer {
public:
    TreeNode* constructMaximumBinaryTree(vector<int>& nums) {
        if(nums.empty()) return nullptr;
        return constructTree(nums, 0, nums.size()-1);
    }
    TreeNode* constructTree(const vector<int>& nums, const int start, const int end){
        if(start > end) return nullptr;
        int maxValue = nums[start];
        int index = start;
        for(int i = start+1; i <= end; ++i){
            if(nums[i]>maxValue){
                maxValue = nums[i];
                index = i;
            }
        }
        TreeNode* root = new TreeNode(maxValue);
        root->left = constructTree(nums, start, index-1);
        root->right = constructTree(nums, index+1, end);
        return root;
    }
};

int main() {
    vector<int> v = { 3, 2, 1, 6, 0, 5 };
    Solution s;
    TreeNode* root = s.constructMaximumBinaryTree(v);
}