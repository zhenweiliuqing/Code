#include<iostream>
#include<time.h>
#define length 10
using namespace std;

// 自己搞个容易记忆的
// 堆排序就两步 
// 1. buildHeap 大顶堆 最后是从小到大排序
// 2. heapSort

void swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void downAdjust(int arr[], int parentIndex, int size) {
	int childIndex = 2 * parentIndex + 1;
	while (childIndex < size) {
		if (childIndex + 1 < size && arr[childIndex] > arr[childIndex + 1])
			childIndex++;
		// 大顶堆
		if (arr[parentIndex] >= arr[childIndex])
			break;
		swap(arr[parentIndex], arr[childIndex]);
		parentIndex = childIndex;
		childIndex = 2 * parentIndex + 1;
	}
}

void buildHeap(int arr[], int n) {
	for (int i = (n - 2) / 2; i >= 0; i--)
		downAdjust(arr, i, n);
}

void heapsort(int arr[], int size) {
	buildHeap(arr, size);
	for (int i = size - 1; i >= 0; i--) {
		swap(arr[i], arr[0]);
		downAdjust(arr, 0, i);
	}
}




// 这个不对 heapsort 不是一个一个insert构建二叉堆的过程
// 应该是给了一个array 输出一个有序数组的过程 应该在现有array上进行调整使之成为一个二叉堆

// void swap(int &a,int &b)
// {
// 	int temp = a;
// 	a = b;
// 	b = temp;
// }
// void heapify(int arr[], int index, int heapsize)
// {
// 	int left = 2*index+1;
// 	while (left < heapsize)
// 	{
// 		int largest = left+1<heapsize && arr[left+1]>arr[left]?
// 			left+1:left;
// 		largest = arr[index] < arr[largest]?largest:index;
// 		if(index == largest)
// 			break;
// 		swap(arr[index],arr[largest]);
// 		index = largest;
// 		left = 2*index+1;
// 	}

// }
// void heapsort(int arr[],int heapsize)
// {
// 	while(heapsize > 1)
// 	{
// 		swap(arr[0],arr[heapsize-1]);
// 		heapsize--;
// 		heapify(arr,0,heapsize);
// 	}
// }
// void heapinsert(int arr[],int index)
// {
// 	while(arr[index] > arr[(index-1)/2])
// 	{
// 		swap(arr[index],arr[(index-1)/2]);
// 		index = (index-1)/2;
// 	}
// }
// int main() {
// 	srand((unsigned)time(NULL));	
// 	int arr[length]  ;
// 	int heapsize = length ;
// 	cout<<"arr = ";
// 	for(int i = 0;i<heapsize;i++)
// 	{
// 		arr[i] = rand()%10;
// 		cout<<arr[i]<<" ";
// 		heapinsert(arr,i);
// 	}
// 	cout<<endl<<"arr1 = ";

// 	heapsort(arr,heapsize);

// 	for(int i = 0;i<length;i++)
// 	{
// 		cout<<arr[i]<<" ";
// 	}
// 	cout<<endl;
// 	//system("pause");
// 	return 0;
// }
