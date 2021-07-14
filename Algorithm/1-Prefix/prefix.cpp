#include <vector>
#include <unordered_map>
using namespace std;
// labuladong
// 给定一个整数数组和一个整数k 找到该数组中和为target的连续子数组的个数

// 利用前缀和
int subarraySum(vector<int>& nums, int target) {
    int n = nums.size();
    vector<int> pre(n + 1);
    for (int i = 1; i <= n; i++) {
        pre[i] = pre[i - 1] + nums[i - 1];
    }
    int ans = 0;
    // 当确定j之后 需要从0到j一个一个判断pre[i]是否等于pre[j]-k
    // 可以用一个哈希表记录j之前有多少个0-i的前缀和等于pre[j]-k
    for (int i = 0; i <= n; i++) {
        for (int j = i + 1; j <= n; j++) {
            if (pre[j] - pre[i] == target)
                ans++;
        }
    }
    return ans;
}

// 再利用哈希表优化
// 用一个哈希表记录j之前有多少个0-i的前缀和等于pre[j]-k
int subarraySum(vector<int>& nums, int target) {
    int n = nums.size();
    // vector<int> pre(n + 1);
    // for (int i = 1; i <= n; i++)
    //     pre[i] = pre[i - 1] + nums[i - 1]; // 可以合并到下边的循环里
    int ans = 0, sum = 0;
    unordered_map<int, int> mmap;
    mmap[0] = 1;
    for (int j = 1; j <= n; j++) {
        sum += nums[j - 1];
        int need = sum - target;
        if (mmap.find(need) != mmap.end())
            ans += mmap[need];
        ++mmap[sum]; 
    }
    return ans;
}
