#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        vector<int> idx;
        for (int i = 0; i < numbers.size(); i++) {
            int left = i + 1, right = numbers.size() - 1;
            int mid = left + ((right - left) >> 1);
            while (left < right) {
                if (numbers[i] + numbers[mid] == target) {
                    break;
                } else if (numbers[i] + numbers[mid] < target) {//需要大一点
                    left = mid + 1;
                    mid = left + ((right - left) >> 1);
                } else if (numbers[i] + numbers[mid] > target) {
                    right = mid - 1;
                    mid = left + ((right - left) >> 1);
                }
            }
            if (numbers[i] + numbers[mid] == target) {
                idx.push_back(i + 1);
                idx.push_back(mid + 1);
                break;
            }
        }
        return idx;
    }
};

// 双指针解法 有序数组 一定不会错过正确的值
class Answer {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int low = 0, high = numbers.size() - 1;
        while (low < high) {
            int sum = numbers[low] + numbers[high];
            if (sum == target) {
                return {low + 1, high + 1};
            } else if (sum < target) {
                ++low;
            } else {
                --high;
            } 
        }
        return {-1, -1};
    }
};
