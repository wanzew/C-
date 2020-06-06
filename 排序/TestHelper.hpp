#ifndef TESTHELPER_HPP_
#define TESTHELPER_HPP_

#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cassert> 

using namespace std;

namespace TestHelper{
	//生成包含n各元素的随机数组，每个元素的随机范围为[rangeL, rangeR]
	int *generateRandomArray(int f_len_i, int f_rangeL_i, int f_rangeR_i);

	//产生一个近乎有序的数组，首先生成一个有序数组，然后随机交换某些数据对
	//swapTimes 定义了数组的无序程度
	void generateNearlySortedArray(int* (&f_arr_p), int f_len_i, int f_swapTimes_i);

	//检查数组是否有序
	bool isSorted(int *f_arr_p, int f_lengh_i);

	//拷贝数组函数
	int *copyIntArray(int *arr, int n);

	//打印数组
	void printArray(int * arr, int n);

	template<typename Dtype>
	void testSort(const string &sortname, void(*sort)(Dtype[], int), Dtype arr[], int len){
		clock_t startTime = clock();
		sort(arr, len);
		clock_t endTime = clock();
		cout << sortname << " time elapsed: " << double(endTime - startTime) << endl;
		assert(isSorted(arr, len));
		cout << "isSorted:" << isSorted(arr, len) << endl;
	}
}

#endif