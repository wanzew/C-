#include "TestHelper.hpp"

namespace TestHelper{
	//生成包含n各元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
	int *generateRandomArray(int f_len_i, int f_rangeL_i, int f_rangeR_i){
		srand(time(NULL));
		int * l_res_p = new int[f_len_i];
		for (int i = 0; i < f_len_i; i++){
			l_res_p[i] = rand() % (f_rangeR_i - f_rangeL_i) + f_rangeL_i;
		}
		return l_res_p;
	}

	//产生一个近乎有序的数组，首先生成一个有序数组，然后随机交换某些数据对
	//swapTimes 定义了数组的无序程度
	void generateNearlySortedArray(int* (&f_arr_p), int f_len_i, int f_swapTimes_i){
		for (int i = 0; i < f_len_i; i++)
			f_arr_p[i] = i;
		for (int i = 0; i < f_swapTimes_i; i++)
			swap(f_arr_p[rand() % f_len_i], f_arr_p[rand() % f_len_i]);
	}

	//检查数组是否有序
	bool isSorted(int *f_arr_p, int f_lengh_i){
		for (int i = 0; i < f_lengh_i - 1; i++)
			if (f_arr_p[i] > f_arr_p[i + 1])
				return false;
		return true;
	}

	//拷贝数组函数
	int *copyIntArray(int *arr, int n){
		int *res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = arr[i];
		return res;
	}

	//打印数组
	void printArray(int * arr, int n){
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

}
