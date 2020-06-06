#include "TestHelper.hpp"

namespace TestHelper{
	//���ɰ���n��Ԫ�ص�������飬ÿ��Ԫ�ص������ΧΪ[rangeL, rangeR]
	int *generateRandomArray(int f_len_i, int f_rangeL_i, int f_rangeR_i){
		srand(time(NULL));
		int * l_res_p = new int[f_len_i];
		for (int i = 0; i < f_len_i; i++){
			l_res_p[i] = rand() % (f_rangeR_i - f_rangeL_i) + f_rangeL_i;
		}
		return l_res_p;
	}

	//����һ��������������飬��������һ���������飬Ȼ���������ĳЩ���ݶ�
	//swapTimes ���������������̶�
	void generateNearlySortedArray(int* (&f_arr_p), int f_len_i, int f_swapTimes_i){
		for (int i = 0; i < f_len_i; i++)
			f_arr_p[i] = i;
		for (int i = 0; i < f_swapTimes_i; i++)
			swap(f_arr_p[rand() % f_len_i], f_arr_p[rand() % f_len_i]);
	}

	//��������Ƿ�����
	bool isSorted(int *f_arr_p, int f_lengh_i){
		for (int i = 0; i < f_lengh_i - 1; i++)
			if (f_arr_p[i] > f_arr_p[i + 1])
				return false;
		return true;
	}

	//�������麯��
	int *copyIntArray(int *arr, int n){
		int *res = new int[n];
		for (int i = 0; i < n; i++)
			res[i] = arr[i];
		return res;
	}

	//��ӡ����
	void printArray(int * arr, int n){
		for (int i = 0; i < n; i++)
			cout << arr[i] << " ";
		cout << endl;
	}

}
