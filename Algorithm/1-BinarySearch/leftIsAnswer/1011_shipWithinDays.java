
class Solution {
    public int findMaxofWeights(int[] weights) {
        int max = weights[0];
        for (int i = 1; i < weights.length; i++) {
            if (weights[i] > max)
                max = weights[i];
        }
        return max;
    }

    public int getSum(int[] weights) {
        int sum = 0;
        for (int i = 0; i < weights.length; i++) {
            sum += weights[i];
        }
        return sum;
    }

    public boolean canFinishWithinDays(int shipLoad, int[] weights, int D) {
        int days = 0;
        int i = 0;
        while (i < weights.length) {
            int load = 0;
            while (i < weights.length && load + weights[i] <= shipLoad) {
                load += weights[i];
                i++;
            }
            days++;
        }
        return days <= D;
    }
    
    // 这思路不好用
    // public boolean canFinishWithinDays(int shipLoad, int[] weights, int D) {
    //     int days = 0;
    //     for (int i = 0; i < weights.length; i++) {
    //         int load = 0;
    //         while (load <= shipLoad && i < weights.length) {
    //             load += weights[i];
    //             i++;
    //         }
    //         days++;
    //         if (i == weights.length)
    //             break;
    //         i -= 2;
    //     }
    //     return days <= D;
    // }
    
    public int shipWithinDays(int[] weights, int D) {
        int left = findMaxofWeights(weights);
        int right = getSum(weights);
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (canFinishWithinDays(mid, weights, D))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return left;   
    }
}
// 通过了

class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        //int[] weights = {1,2,3,4,5,6,7,8,9,10};
        // int D = 5;
        int[] weights = { 1, 2, 3, 1, 1 };
        int D = 4;
        solution.shipWithinDays(weights, D);
    }
}