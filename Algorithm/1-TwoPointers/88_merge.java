package LeetCode.Algorithm.1-TwoPointers;

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
        int[] extra = new int[m];
        for (int i = 0; i < m; i++) 
            extra[i] = nums1[i];
        int cnt = 0, i = 0, j = 0;
        for (i = 0, j = 0; i < m && j < n;) {
            if (extra[i] < nums2[j]) {
                nums1[cnt++] = extra[i];
                i++;
            } else {
                nums1[cnt++] = nums2[j];
                j++;
            }
        }
        while (i < m)
            nums1[cnt++] = extra[i++];
        while (j < n) 
            nums1[cnt++] = nums2[j++];
    }
}
// 通过了 都得再开辟空间

class Solution {
    public void merge(int[] nums1, int m, int[] nums2, int n) {
      // Make a copy of nums1.
      int [] nums1_copy = new int[m];
      System.arraycopy(nums1, 0, nums1_copy, 0, m);
  
      // Two get pointers for nums1_copy and nums2.
      int p1 = 0;
      int p2 = 0;
  
      // Set pointer for nums1
      int p = 0;
  
      // Compare elements from nums1_copy and nums2
      // and add the smallest one into nums1.
      while ((p1 < m) && (p2 < n))
        nums1[p++] = (nums1_copy[p1] < nums2[p2]) ? nums1_copy[p1++] : nums2[p2++];
  
      // if there are still elements to add
      if (p1 < m)
        System.arraycopy(nums1_copy, p1, nums1, p1 + p2, m + n - p1 - p2);
      if (p2 < n)
        System.arraycopy(nums2, p2, nums1, p1 + p2, m + n - p1 - p2);
    }
}