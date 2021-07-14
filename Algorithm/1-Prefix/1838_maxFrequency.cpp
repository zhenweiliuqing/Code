#include <vector>
#include <algorithm>
using namespace std;

// 先排个序 计算下前缀和
// 对于每一个元素进行计算 看这个范围内是不是满足k 满足k的话就是这个数
// 又是只想到O(n2)解法 
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        int ans = 1;
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        for (int i = 2; i <= n; i++) {
            // 一共需要几个数 从多到少 前开后闭 一减就是个数和差
            for (int j = 0; j < i; j++) {
                int sum = (i - j) * nums[i - 1];
                int have = pre[i] - pre[j];
                if (sum - have <= k) {
                    ans = max(ans, i - j);
                    break;
                }
            }
        }
        return ans;
    }
};
// 感觉会超时 53/71

// 想想一次遍历的方法
// 这是前缀和 + 二分的思想
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> pre(n + 1);
        int ans = 1;
        for (int i = 1; i <= n; i++)
            pre[i] = pre[i - 1] + nums[i - 1];
        for (int i = 1; i <= n; i++) {
            // 这里至少可以用二分 找到第一个pre[i] + k >= pre[j] j是能够到达的位置
            // 肯定可以用二分 但不是这么用
            int j = lower_bound(pre.begin(), pre.end(), pre[i] + k) - pre.begin();

        }
        return ans;
    }
};

// 排序+双指针
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long total = 0;
        int l = 0, res = 1;
        for (int r = 1; r < n; ++r) {
            // 一步一步地累加 先把第一个数变成第二个 再把前两个数变成第三个 一步步累加需要的值
            total += (long long)(nums[r] - nums[r - 1]) * (r - l); 
            // 当总的值超过k时需要缩小窗口
            while (total > k){
                total -= nums[r] - nums[l];
                ++l;
            }
            res = max(res, r - l + 1);
        }
        return res;
    }
};
// 作者：LeetCode-Solution
// 链接：https://leetcode-cn.com/problems/frequency-of-the-most-frequent-element/solution/zui-gao-pin-yuan-su-de-pin-shu-by-leetco-q5g9/
// 来源：力扣（LeetCode）
// 著作权归作者所有。商业转载请联系作者获得授权，非商业转载请注明出处。