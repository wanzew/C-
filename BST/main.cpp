#include<iostream>
#include"BST.h"

using namespace std;


int main() {

	BST2::BST bst;

	bst.insertNode(10, "h");
	bst.insertNode(5, "d");
	bst.insertNode(3, "b");
	bst.insertNode(7, "f");
	bst.insertNode(2, "a");
	bst.insertNode(4, "c");
	bst.insertNode(6, "e");
	bst.insertNode(8, "g");
	bst.insertNode(15, "l");
	bst.insertNode(13, "j");
	bst.insertNode(12, "i");
	bst.insertNode(14, "k");
	bst.insertNode(17, "n");
	bst.insertNode(16, "m");
	bst.insertNode(18, "o");

	cout << "bst.size: " << bst.size() << endl;
	bst.printBST();
	bst.findNode(11);
	cout << "minNode: " << bst.minNode()->key << endl;
	cout << "maxNode: " << bst.maxNode()->key << endl;

	bst.deleteNode(7);
	bst.printBST();

	/*cout << "Min Node is: " << bst.minNode() << endl;
	cout << "Max Node is: " << bst.maxNode() << endl;
	bst.printInLayer();

	bst.deleteNode(5);
	bst.printBST();*/


	system("pause");
	return 0;
}