#include"Graph.h"
#include<iostream>
#include<ctime>
using namespace std;

int main() {
	cout << "welcome to graph part..." << endl;

	const int N = 5;
	const int M = 10;
	Graph::SparseGraph sparseGraph(N, false);
	srand(time(NULL));

	for (int i = 0; i < N; i++) {
		int a = rand() % N;
		int b = rand() % N;

		sparseGraph.addEdge(a, b);
	}

	for (int i = 0; i < N; i++) {
		cout << i <<" : ";
		Graph::SparseGraph::adjIterator iter(sparseGraph, i);

		for (int i = iter.begin(); !iter.end(); i = iter.next()) {
			cout << i << " ";
		}
		cout << endl;
	}

	system("pause");
	return 0;	
}