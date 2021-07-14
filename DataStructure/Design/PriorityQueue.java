package LeetCode.Algorithm

import java.lang.reflect.Array;
import java.util.Arrays;

public class PriorityQueue {
    private int[] array;
    private int size;

    public PriorityQueue() {
        array = new int[32];
    }

    private void enQueue(int key) {
        if (size >= array.length)
            resize();
        array[size++] = key;
        upAdjust();
    }

    private int deQueue() throws Exception {
        if (size <= 0)
            throw new Exception("the queue is empty!");
        int head = array[0];
        array[0] = array[--size];
        downAdjust();
        return head;
    }

    private void upAdjust() {
        int childIndex = size - 1;
        int parentIndex = (childIndex - 1) / 2;

        int temp = array[childIndex];
        while (childIndex > 0 && temp < array[parentIndex]) {
            array[childIndex] = array[parentIndex];
            childIndex = parentIndex;
            parentIndex = (parentIndex - 1) / 2;
        }
        array[childIndex] = temp;
    }

    private void downAdjust() {
        int parentIndex = 0;
        int temp = array[parentIndex];
        int childIndex = 1;

        while (childIndex < size) {
            // 右孩子
            if (childIndex + 1 < size && array[childIndex + 1] < array[childIndex]) {
                childIndex++;
            }

            if (temp <= array[childIndex])
                break;

            array[parentIndex] = array[childIndex];
            parentIndex = childIndex;
            childIndex = 2 * childIndex + 1;
        }
        array[parentIndex] = temp;
    }
    
    private void resize() {
        int newSize = this.size * 2;
        this.array = Arrays.copyOf(this.array, newSize);
    }
}
