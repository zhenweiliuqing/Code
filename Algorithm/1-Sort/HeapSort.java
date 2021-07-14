package LeetCode.Array;

import java.util.Arrays;

// 这个应该没问题 heapsort只用到 downAdjust
public class HeapSort {
    public static void downAdjust(int[] array, int parentIndex, int length) {
        int temp = array[parentIndex];
        int childIndex = 2 * parentIndex + 1;

        while (childIndex < length) {
            if (childIndex + 1 < length && array[childIndex + 1] > array[childIndex]) {
                childIndex++;
            }
            // 这是个最大堆
            if (temp >= array[childIndex])
                break;

            array[parentIndex] = array[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        array[parentIndex] = temp;
    }
    
    // 从最后的非叶子节点开始调整
    public static void heapSort(int[] array) {
        for (int i = (array.length - 2) / 2; i >= 0; i--) {
            downAdjust(array, i, array.length);
        }
        System.out.println(Arrays.toString(array));
        
        for (int i = array.length - 1; i > 0; i--) {
            int temp = array[i];
            array[i] = array[0]; // 构建最大堆 把堆顶的最大值交换到最后 全部完成后就是从小到大排列
            array[0] = temp;
            // 不包括i 堆的长度-1
            downAdjust(array, 0, i); // 删除了堆顶的元素 把最后一个元素放到堆顶重新调整 使之成为最大堆
        }
    }
} 
