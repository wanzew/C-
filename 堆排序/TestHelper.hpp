#ifndef TESTHELPER_HPP_
#define TESTHELPER_HPP_

#include<iostream>
#include<algorithm>
#include<string>
#include<ctime>
#include<cassert> 

using namespace std;

namespace TestHelper{
	//���ɰ���n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
	int *generateRandomArray(int f_len_i, int f_rangeL_i, int f_rangeR_i);

	//����һ��������������飬��������һ���������飬Ȼ���������ĳЩ���ݶ�
	//swapTimes ���������������̶�
	void generateNearlySortedArray(int* (&f_arr_p), int f_len_i, int f_swapTimes_i);

	//��������Ƿ�����
	bool isSorted(int *f_arr_p, int f_lengh_i);

	//�������麯��
	int *copyIntArray(int *arr, int n);

	//��ӡ����
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