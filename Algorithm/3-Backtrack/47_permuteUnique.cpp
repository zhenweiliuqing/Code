// 1-5
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// 6-22
// 感觉可以用set来进行去重


// 5-18
// for循环就是nums中的每个元素 这个不仅需要去除自身的重复 还有其他元素的重复 但是还得保留一个 元素值相同但还是不同的元素
// 递归就是nums的size 
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int>& tmp, vector<bool>& isVisited) {
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            if (isVisited[i])
                continue;
            // 1 1 1 2 3
            if (i != 0 && !isVisited[i - 1] && nums[i] == nums[i - 1])
                continue;

            isVisited[i] = true;
            tmp.push_back(nums[i]);
            backtrack(nums, tmp, isVisited);
            tmp.pop_back();
            isVisited[i] = false;
        }
    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<bool> isVisited(nums.size(), false);
        vector<int> tmp;
        sort(nums.begin(), nums.end());
        backtrack(nums, tmp, isVisited);
        return ans;
    }
};
// 通过了

// 40 47可以借鉴一下
// 测试用例:
// 1 1 1 2 2 3 4 
class Solution {
public:
    vector<vector<int>> ans;
    void backtrack(vector<int>& nums, vector<int> tmp, vector<int> track) {
        // if (tmp.size() == nums.size()) {
        //     if (!count(ans.begin(), ans.end(), tmp))
        //         ans.push_back(tmp);
        //     return;
        // }
        if (tmp.size() == nums.size()) {
            ans.push_back(tmp);
            return;
        }

        for (int i = 0; i < nums.size(); i++) {
            // 如何跳过自己 不跳过别的重复的
            // 这里可以用一个bool数组解决
            // 不跳过自己也不行 不重复的数还必须跳过自己
            if(count(track.begin(), track.end(), i))
                continue;
            // 这种方法不好 在递归中跳过自己后 后边的第一个是不应该跳过的
            // 主要是针对111 22中第一个重复的数字 在跳过自身后 后边会全跳过 
            // if (i != 0 && nums[i] == nums[i - 1])
            //     continue;

            track.push_back(i);
            tmp.push_back(nums[i]);
            backtrack(nums, tmp, track);
            tmp.pop_back();
            track.pop_back();

            // 这个方法好 这个是最后再跳过重复的 那么第一个会保留下来
            while (i + 1 < nums.size() && nums[i] == nums[i + 1])
                i++;
        }
    }

    vector<vector<int>> permuteUnique(vector<int>& nums) {
        vector<int> tmp, track;
        sort(nums.begin(), nums.end());
        backtrack(nums, tmp, track);
        return ans;
    }
};
// 通过了

int main() {
    Solution sol;
    vector<int> v = {1, 1, 2};
    sol.permuteUnique(v);
}


