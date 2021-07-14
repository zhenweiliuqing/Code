// 4-11
// 思路：固定一个统一蓄水的次数 然后统计每个桶需要升级的次数
// vat[j]/i 需要的水桶的容量 会去除小数部分 需要加i-1使得最后结果 +1 对于正好整除的没有影响
class Solution {
public:
    int storeWater(vector<int>& bucket, vector<int>& vat) {
        int n = bucket.size();
        int ans = 1e9;
        if (*max_element(vat.begin(), vat.end()) == 0)
            return 0;
        // 最多次数应该是vat最大值 但是算出次数还没有直接写10000快 
        // *max_element(vat.begin(), vat.end())
        for (int i = 1; i <= 10000; i++) {
            int sum = i;
            for (int j = 0; j < n; j++)
                sum += max(0, (vat[j]+i-1)/i - bucket[j]);
            ans = min(ans, sum);
        }
        return ans;
    }
};
