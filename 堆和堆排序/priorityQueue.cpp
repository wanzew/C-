#include "priorityQueue.hpp"

namespace priorityQueue {
	void PriorityQueue::minHeapDown(int index) {
		while (index * 2 <= capacity) {
			int sub_left = index * 2;
			int min_side = sub_left;
			if (sub_left + 1 <= capacity && data[sub_left + 1] < data[sub_left])
				min_side = sub_left + 1;
			//最小堆：你比下面小的还小
			if (data[index] > data[min_side])
				swap(data[index], data[min_side]);
			else 
				break;
			index = min_side;
		}
	}
	void PriorityQueue::minHeapUp(int index) {
		while (index > 1) {
			if (data[index] < data[index / 2])
				swap(data[index], data[index / 2]);
			index /= 2;
		}
	}
	PriorityQueue::PriorityQueue(int top):capacity(top),count(0){
		data = new int[top +1];
	}
	PriorityQueue::~PriorityQueue() { delete[] data; }

	void PriorityQueue::buildHeap(int arr[]) {
		for (int i = 0; i < capacity; i++) {
			data[++count] = arr[i];
			minHeapUp(count);
		}
	}

	//arr数组中从第top+1个元素开始，依次和data[1]对比
	//比data[1]大就下沉
	void PriorityQueue::selectTop(int arr[], int len) {
		for (int i = capacity; i < len; i++) {
			if (arr[i] > data[1]) {
				data[1] = arr[i];
				minHeapDown(1);
			}
		}
	}

	void PriorityQueue::printData() {
		for (int i = 1; i <= capacity; i++) {
			cout << data[i] << " ";
		}
		cout << endl;
	}


	int subMain()
	{
		int *arr = TestHelper::generateRandomArray(100, 0, 100);

		//TestHelper::testSort("heapSort: ", heapSortInplace::heapSortInplace, arr, 99);

		//优先队列，从100个数中，提取前10大的数

		for (int i = 0; i < 100; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;

		priorityQueue::PriorityQueue priority(10);
		priority.buildHeap(arr);
		priority.selectTop(arr, 100);
		priority.printData();


		delete[] arr;

		return 0;
	}
}
