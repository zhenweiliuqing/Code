// 3-15
class Solution {
public:
    vector<int> smallestK(vector<int>& arr, int k) {
        vector<int> ans;
        if (k == 0)
            return ans;
        int left = 0, right = arr.size() - 1;
        while (left < right) {
            int index = partition(arr, left, right);
            if (index == k - 1)
                break;
            else if (index > k - 1)
                right = index - 1;
            else if (index < k - 1)
                left = index + 1;
        }
        for (int i = 0; i < k; i++)
            ans.push_back(arr[i]);
        return ans;
    }
    int partition(vector<int>& nums, int start, int end) {
        int left = start, right = end;
        int pivot = nums[left];
        while (left < right) {
            // 这里必须是 == 
            while (left <= right && nums[left] <= pivot)
                left++;
            while (left <= right && nums[right] > pivot)
                right--;
            if (left < right) {
                int tmp = nums[left];
                nums[left]= nums[right];
                nums[right] = tmp;
            }
        }
        nums[start] = nums[right];
        nums[right] = pivot;
        return right;
    }
};