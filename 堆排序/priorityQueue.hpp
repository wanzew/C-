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

		//������ǰtop��Ԫ�س�ʼ����С�ѣ���С��һ��top��Ԫ��
		void buildHeap(int arr[]);

		//arr�����дӵ�top+1��Ԫ�ؿ�ʼ�����κ�data[1]�Ա�  ��data[1]����³�
		void selectTop(int arr[], int len);

		void printData();

	};


	int subMain();
}

#endif // !PRIORITYQUEUE_HPP_
