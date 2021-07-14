#include <iostream>
#include <vector>
using namespace std;

void mergeSort(vector<int>& nums, int start, int end) {
    if (start < end) {
        int mid = start + ((end - start) >> 1);
        mergeSort(nums, start, mid);
        mergeSort(nums, mid + 1, end);
        merge(nums, start, mid, end);
    }
}

void merge(vector<int>& nums, int start, int mid, int end) {
    vector<int> tmp(end - start + 1);
    int p1 = start, p2 = mid + 1, p = 0;
    while (p1 <= mid && p2 <= end) {
        if (nums[p1] <= nums[p2])
            tmp[p++] = nums[p1++];
        else
            tmp[p++] = nums[p2++];
    }
    while (p1 <= mid)
        tmp[p++] = nums[p1++];
    while (p2 <= end)
        tmp[p++] = nums[p2++];
    for (int i = 0; i < tmp.size(); i++)
        nums[i + start] = tmp[i];
}
