#include<iostream>
#include<vector>
#include<time.h>
using namespace std;

namespace quickSolution {
	//快速排序leetcode版-开始
	class Solution {
	public:
		void quickSort(vector<int> &arr) {
			quick(arr, 0, arr.size() - 1);
		}

	private:
		void quick(vector<int> &arr, int left, int right) {
			if (left >= right) return;
			int p = partition(arr, left, right);
			quick(arr, left, p - 1);
			quick(arr, p + 1, right);
		}

		int partition(vector<int> &arr, int left, int right) {
			srand(time(NULL));
			swap(arr[left], arr[rand() % (right - left + 1) + left]);
			int v = arr[left];
			int j = left, i = left + 1;

			//[left+1, j] < v    &&   v < [j+1, i) 
			for (i; i <= right; i++) {
				if (arr[i] < v)
					swap(arr[++j], arr[i]);
			}
			swap(arr[left], arr[j]);
			return j;
		}

	};
	//快速排序leetcode版-结束
}

namespace quickSort {

	int partition(int arr[], int left, int right) {
		srand(time(NULL));
		swap(arr[left], arr[rand() % (right - left + 1) + left]);
		int v = arr[left];

		//[left+1, j] < v  [j+1, i) >= v
		int j = left, i = left + 1;
		while (i <= right) {
			if (arr[i] < v)
				swap(arr[++j], arr[i++]);
			else
				i++;
		}
		swap(arr[left], arr[j]);
		return j;
	}

	void quickSort(int arr[], int left, int right) {
		if (left >= right) return;
		int p = partition(arr, left, right);
		quickSort(arr, left, p - 1);
		quickSort(arr, p + 1, right);
	}

	void quickSort(int arr[], int len) {
		quickSort(arr, 0, len - 1);
	}
}

namespace twoWays {
//双路快速排序有三点需要注意：
//1. 防止左移，右移越界
//2. i>j时终结循环
//3. swap(arr[left], arr[j])  
// j是小于等于v的元素，在右侧

//双路快速排序-开始
int __partition(int arr[], int left, int right) {
	srand(time(NULL));
	swap(arr[left], arr[rand() % (right - left + 1) + left]);
	int v = arr[left];
	//[left+1, i) <= v  && (j, right] >= v
	int i = left + 1, j = right;
	while (true) {
		while (i <= right && arr[i] < v) i++;
		while (j >= left + 1 && arr[j] > v) j--;
		if (i > j) break;

		swap(arr[i++], arr[j--]);
	}
	swap(arr[left], arr[j]);
	return j;
}

void __twoWayQuickSort(int arr[], int left, int right) {
	if (left >= right) return;
	int p = __partition(arr, left, right);
	__twoWayQuickSort(arr, left, p - 1);
	__twoWayQuickSort(arr, p + 1, right);
}

void twoWayQuickSort(int arr[], int len) {
	__twoWayQuickSort(arr, 0, len - 1);
}
//双路快速排序-结束
}

namespace threeWays {
	void threeWaysQuickSort(int arr[], int left, int right) {
		if (left >= right) return;
		swap(arr[left], arr[rand() % (right - left + 1) + left]);
		int v = arr[left];
		//[left+1, lt] < v  [lt+1, i) == v [gt, right] > v
		int lt = left, i = left + 1, gt = right + 1;
		while (i<gt) {
			if (arr[i] < v)
				swap(arr[++lt], arr[i++]);
			else if (arr[i] > v)
				swap(arr[i], arr[--gt]);
			else
				i++;
		}
		swap(arr[left], arr[lt]);
		threeWaysQuickSort(arr, left, lt - 1);
		threeWaysQuickSort(arr, gt, right);
	}
	void threeWaysQuickSort(int arr[], int len) {
		threeWaysQuickSort(arr, 0, len - 1);
	}
}
