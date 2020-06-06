#include<iostream>

using namespace std;

namespace BinarySearch {
	int BinarySearch(int arr[], int len, int key) {
		int left = 0, right = len - 1;
		while (left <= right) {
			int mid = (right - left) / 2 + left;
			if (key == arr[mid])
				return mid;
			else if (key < arr[mid])
				right = mid - 1;
			else
				left = mid + 1;
		}
		return -1;
	}

	void findKey(int arr[], int len, int key) {
		int res = BinarySearch(arr, len, key);

		if (res < 0)
			cout << "can not find£º" << key << " in the array." << endl;
		else
			cout << "find the " << key << " in arr[" << res << "]" << endl;
	}
}