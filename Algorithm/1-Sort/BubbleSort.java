package LeetCode.Algorithm.1-Sort;

// 相邻元素交换
public class BubbleSort {
    private static void sort(int array[]) {
        int tmp = 0;
        for (int i = 0; i < array.length; i++) {
            for (int j = 0; j < array.length - i - 1; j++) {
                if (array[j] > array[j + 1]) {
                    tmp = array[j + 1];
                    array[j + 1] = array[j + 1];
                    array[j + 1] = tmp;
                }
            }
        }
    }
}
