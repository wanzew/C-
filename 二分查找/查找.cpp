#include"binarySearch.h"
#include"../≈≈–Ú/quickSort.hpp"
#include"../≈≈–Ú/TestHelper.hpp"

using namespace std;

int main() {

	int arrLen = 100;

	int *arr = TestHelper::generateRandomArray(arrLen, 0, 100);

	TestHelper::testSort("quickSort: ", quickSort::quickSort, arr, arrLen);

	TestHelper::printArray(arr, arrLen);

	BinarySearch::findKey(arr, arrLen, 30);


	delete[] arr;

	system("pause");
	return 0;
}