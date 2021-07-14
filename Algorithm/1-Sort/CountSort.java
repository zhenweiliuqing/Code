package LeetCode.Algorithm.1-Sort;

// 优化后的是稳定排序
public class CountSort {
    public static int[] countSort(int[] array) {
        int min = array[0];
        int max = array[0];
        // 每两个元素进行三次比较
        for (int i = 1; i < array.length; i++) {
            if (array[i] > max)
                max = array[i];
            if (array[i] < min)
                min = array[i];
        }

        int d = max - min;
        int[] countArray = new int[d + 1];
        for (int i = 0 ; i < array.length; i++) 
            countArray[array[i] - min]++;

        // 变形 转换成排名
        // int sum = 0;
        for (int i = 1; i < countArray.length; i++) {
            // sum += countArray[i];
            countArray[i] += countArray[i - 1];
        }

        // 倒序遍历数组 
        int[] sortedArray = new int[array.length];
        for (int i = array.length - 1; i >= 0; i--) {
            // countArray[array[i] - min]是排名 -1是下标
            sortedArray[countArray[array[i] - min] - 1] = array[i];
            countArray[array[i] - min]--; // 排名-1
        }
        return sortedArray;       
    }
}
