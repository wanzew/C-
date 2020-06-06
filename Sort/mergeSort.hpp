#include"mergeSort.h"


//归并排序模板类实现-开始
template<typename Dtype>
void mergeSort(Dtype arr[], int n){
	__mergeSort(arr, 0, n - 1);
}

template<typename Dtype>
void __mergeSort(Dtype arr[], int left, int right){
	if (left >= right) return;
	//cout << "left: " << left << "righ: " << right << endl;

	int middle = (right - left) / 2 + left;
	//cout << "midd: " << middle << endl;

	__mergeSort(arr, left, middle);
	__mergeSort(arr, middle + 1, right);

	merge(arr, left, middle, right);
}

template<typename Dtype>
void merge(Dtype arr[], int left, int middle, int right){
	int len = right - left + 1;
	Dtype *aux = new Dtype[len];
	for (int i = left; i <= right; i++)
		aux[i - left] = arr[i];
	
	int i = left, j = middle + 1;
	for (int k = left; k <= right; k++){
		if (i > middle){
			arr[k] = aux[j - left];
			j++;
		}
		else if (j > right){
			arr[k] = aux[i - left];
			i++;
		}
		else if (aux[i - left] < aux[j - left]){
			arr[k] = aux[i - left];
			i++;
		}
		else{
			arr[k] = aux[j - left];
			j++;
		}
	}
	delete[] aux;
}

//归并排序模板类实现-结束