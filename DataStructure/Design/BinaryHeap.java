package LeetCode.BinaryTree;

import java.util.Arrays;

// 最小堆操作
public class Binary_Heap {
    public static void upAdjust(int[] array) {
        int childIndex = array.length - 1;
        int parentIndex = (childIndex - 1) / 2;

        int temp = array[childIndex];
        // temp < 父节点 上浮 构建最小堆
        while (childIndex > 0 && temp < array[parentIndex]) {
            array[childIndex] = array[parentIndex];
            childIndex = parentIndex;
            parentIndex = (childIndex - 1) / 2;
        }
        array[childIndex] = temp;
    }

    // 删除的时候把最后一个节点放到头节点 然后下沉
    public static void downAdjust(int[] array, int parentIndex, int length) {
        int temp = array[parentIndex];
        int childIndex = 2 * parentIndex + 1;

        while (childIndex <= length) {
            // 有右孩子且右孩子更小
            if (childIndex + 1 < length && array[childIndex + 1] < array[childIndex]) {
                childIndex++;
            }

            if (temp <= array[childIndex])
                break;
            
            array[parentIndex] = array[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * parentIndex + 1;
        }
        array[parentIndex] = temp;
    }

    public static void buildHeap(int[] array) {
        for (int i = (array.length - 2) / 2; i >= 0; i--) {
            downAdjust(array, i, array.length - 1);
        }
    }
    public static void main(String[] args) {
        // int[] array = new int[] { 1, 3, 2, 6, 5, 7, 8, 9, 10, 0 };
        // upAdjust(array);
        // System.out.println(Arrays.toString(array));

        int[] array = new int[] { 7, 1, 3, 10, 5, 2, 8, 9, 6 };
        buildHeap(array);
        System.out.println(Arrays.toString(array));
    }
}
