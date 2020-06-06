#include<iostream>
#include<vector>
#include<string>
#include"quickSort.hpp"
#include"mergeSort.hpp"
#include"TestHelper.hpp"

using namespace std; 

int main(){

	int arrLen = 100;
	int arrLeft = 0;
	int arrRight = 10;
	int *l_arr_p = TestHelper::generateRandomArray(arrLen, arrLeft, arrRight);
	int *l_arrNearSorted_p = new int[arrLen];
	TestHelper::generateNearlySortedArray(l_arrNearSorted_p, arrLen, 20);
	
	TestHelper::testSort<int>("threeWays::threeWaysQuickSort", threeWays::threeWaysQuickSort, l_arrNearSorted_p, arrLen);
	TestHelper::printArray(l_arrNearSorted_p, arrLen);
	cout << "l_arrNearSorted_p isSorted: " << TestHelper::isSorted(l_arrNearSorted_p, arrLen) << endl;


	delete[] l_arr_p;
	delete[] l_arrNearSorted_p;

	system("pause");
	return 0;
}