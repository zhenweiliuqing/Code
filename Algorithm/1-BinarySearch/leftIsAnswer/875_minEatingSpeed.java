package LeetCode.BinarySearch;

class Solution {
    public int findMaxofPiles(int[] piles) {
        int ans = piles[0];
        for (int i = 1; i < piles.length; i++) {
            if (piles[i] > ans)
                ans = piles[i];
        }
        return ans;
    }

    public boolean canFinishNPiles(int speed, int[] piles, int H) {
        int total = 0;
        for (int i = 0; i < piles.length; i++) {
            total += (piles[i] + speed - 1) / speed;
            if (total > H)
                break;
        }
        return total <= H;
    }

    // 二分法 
    public int minEatingSpeed(int[] piles, int H) {
        int max = findMaxofPiles(piles);
        int left = 1, right = max;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (!canFinishNPiles(mid, piles, H)) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
        return left;
    }
    // target属于右边
    // 通过了        
    // 想的也不是很清楚 不过记住就好了
}

    // public int minEatingSpeed(int[] piles, int H) {
    //     int max = findMaxofPiles(piles);
    //     int minSpeed = max;
    //     for (int i = 1; i <= max; i++) {
    //         if (canFinishNPiles(i, piles, H)) {
    //             minSpeed = i;
    //             break;
    //         }
    //     }
    //     return minSpeed;
    // }


class Main {
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] piles = {332484035,524908576,855865114,632922376,222257295,690155293,112677673,679580077,337406589,290818316,877337160,901728858,679284947,688210097,692137887,718203285,629455728,941802184};
        int H = 823855818;
        int minSpeed = solution.minEatingSpeed(piles, H);
    }
}
