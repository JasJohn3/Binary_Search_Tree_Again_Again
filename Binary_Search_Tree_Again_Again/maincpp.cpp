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
	BST.insert(2);
	BST.insert(1);
	system("pause");
	BST.insert(21);
	system("pause");
	BST.insert(22);
	system("pause");
	BST.insert(23);
	system("pause");
	BST.inorder();
	system("pause");
	BST.Delete_Node(4);
	BST.inorder();
	system("pause");
	BST.Delete_Node(1);
	BST.inorder();
	system("pause");
	return 0;
};