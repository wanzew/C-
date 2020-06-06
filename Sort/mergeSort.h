#include<iostream>
#include"TestHelper.hpp"

using namespace std;


template<typename Dtype>
void mergeSort(Dtype arr[], int n);

template<typename Dtype>
void __mergeSort(Dtype arr[], int left, int right);

template<typename Dtype>
void merge(Dtype arr[], int left, int middle, int right);


//归并排序一般实现-开始
void _merge(int arr[], int left, int middle, int right) {
	int len = right - left + 1;
	int *aux = TestHelper::copyIntArray(arr, len);
	for (int i = left; i <= right; i++) {
		aux[i - left] = arr[i];
	}
	int i = left, j = middle + 1;
	for (int k = left; k <= right; k++) {
		if (i > middle) {
			arr[k] = aux[j - left];
			j++;
		}
		else if (j > right) {
			arr[k] = aux[i - left];
			i++;
		}
		else if (aux[i - left] < aux[j - left]) {
			arr[k] = aux[i - left];
			i++;
		}
		else {
			arr[k] = aux[j - left];
			j++;
		}
	}
	delete[] aux;
}
void _mergeSort(int arr[], int left, int right) {
	if (left >= right) return;
	int middle = (right - left) / 2 + left;
	_mergeSort(arr, left, middle);
	_mergeSort(arr, middle + 1, right);
	_merge(arr, left, middle, right);
}
void mergeSortGeneral(int arr[], int len) {
	_mergeSort(arr, 0, len - 1);
}
//归并排序一般实现-结束