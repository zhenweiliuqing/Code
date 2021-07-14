package LeetCode.Algorithm.1-Sort;

// 从后往前 如果insertValue小于array[j] 就把前面的数往后移 最后空出来的那个位置就是insertValue的位置
public class InsertSort {
    public static void InsertionSort(int[] array) {
        for (int i = 1; i < array.length; i++) {
            int insertValue = array[i];
            int j = i - 1;
            for (; j >= 0 && insertValue < array[j]; j--)
                array[j + 1] = array[j];
            array[j + 1] = insertValue;
        }
    }
}
