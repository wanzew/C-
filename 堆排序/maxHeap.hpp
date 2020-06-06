#ifndef __MAXHEAP_HPP_
#define __MAXHEAP_HPP_


#include <iostream>
#include <algorithm>
#include <string>
#include <ctime>
#include <cmath>
#include <cassert>
#include"TestHelper.hpp"

using namespace std;

namespace maxHeap {
	class maxHeap {
	public:
		maxHeap(int capa);
		~maxHeap();

		int size();
		void insert(int item);
		int max();
		void testPrint();
	private:
		int count;
		int capacity;
		int* data;
		void maxHeapUp(int index);
		void maxHeapDown(int index);
		void putNumberInLine(int num, string &line, int index_cur_level, int cur_tree_width, bool isLeft);
		void putBranchInLine(string &line, int index_cur_level, int cur_tree_width);
	};

	int maxHeapMain();

}
#endif // !MAXHEAP_HPP_