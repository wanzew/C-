#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
using namespace std;


namespace heapSortInplace {
	void maxHeapDown(int arr[], int i, int index_uplimit) {
		while (2 * i + 1 <= index_uplimit) {
			int sub_left = 2 * i + 1;
			int max_side = sub_left;

			//找到子树中最大的一边
			if (sub_left + 1 <= index_uplimit && arr[sub_left + 1] > arr[sub_left])
				max_side = sub_left +1;

			//最大堆：你还没下面大的大
			if (arr[i] < arr[max_side])
				swap(arr[i], arr[max_side]);
			else
				break;
			i = max_side;
		}
	}

	void heapSortInplace(int arr[], int index) {
		//heapify
		for (int i = (index - 1) / 2; i >= 0; i--) {
			maxHeapDown(arr, i, index);
		}
		//sort				//i不用=0
		for (int i = index; i >= 0; i--) {
			swap(arr[0],  arr[i]);
			maxHeapDown(arr, 0, i - 1);
		}
	}

}