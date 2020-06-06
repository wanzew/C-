#ifndef __PRIORITYQUEUE_HPP_
#define __PRIORITYQUEUE_HPP_

#include<iostream>
#include"TestHelper.hpp"

using namespace std;

namespace priorityQueue {
	class PriorityQueue {
	private:
		int count;
		int capacity;
		int *data;
		void minHeapDown(int index);
		void minHeapUp(int index);
	public:
		PriorityQueue(int top);
		~PriorityQueue();

		//用数组前top个元素初始化最小堆，最小堆一共top个元素
		void buildHeap(int arr[]);

		//arr数组中从第top+1个元素开始，依次和data[1]对比  比data[1]大就下沉
		void selectTop(int arr[], int len);

		void printData();

	};


	int subMain();
}

#endif // !PRIORITYQUEUE_HPP_
