#include <iostream>
#include "Binary_Search_Tree.h"

int main() {

	BST<int> BST;

	BST.insert(10);
	system("pause");
	BST.insert(20);
	system("pause");
	BST.insert(5);
	system("pause");
	BST.insert(4);
	system("pause");
	BST.insert(3);
	system("pause");
	BST.insert(21);
	system("pause");
	BST.insert(22);
	system("pause");
	BST.insert(23);
	system("pause");
	BST.inorder();
	system("pause");

	return 0;
};