#include <iostream>
#include "Binary_Search_Tree.h"
#include <string>

void Automated_Tests();
int main() {
	Automated_Tests();
	BST<int> User_List;
	while (true)
	{
		system("cls");
		std::cout << "\t\tWelcome to the User Created List test suite!" << std::endl;
		std::cout << "This testing suite allows you to add integer values into a list." << std::endl;
		std::cout << "Please follow the Menu selection to begin adding values into your list." << std::endl;
		std::cout << "1.) Insert a value into the List" << std::endl;
		std::cout << "2.) Display the values stored in the list" << std::endl;
		std::cout << "3.) Delete a value inside of the List" << std::endl;
		std::cout << "4.) Find Maximum value in Tree." << std::endl;
		std::cout << "5.) Exit" << std::endl;

		int menu_select;
		std::cin >> menu_select;
		int User_Data;
		switch (menu_select)
		{
		case 1:
			system("cls");
			std::cout << "Please enter a value to insert: " << std::flush;
			std::cin >> User_Data;
			User_List.insert(User_Data);
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		case 2:
			std::cout << "This is all of the Data stored in your list: " << std::flush;
			User_List.inorder();
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		case 3:
			std::cout << "\t\tWarning! Deleting the final node in the tree will exit the program.\n\n" << std::flush;
			std::cout << "Please enter a value to delete: " << std::flush;
			std::cin >> User_Data;
			User_List.Delete_Node(User_Data);
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
		case 4:
			User_List.Maximum();
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		case 5:
			exit(0);
		default:
			std::cout << "Invalid information entered." << std::endl;
			std::cout << "Returning to main menu..." << std::endl;
			system("pause");
			break;
		}
	}	

	return 0;
};
void Automated_Tests()
{
	BST<int> BST;
	std::cout << "Initiating Automated Test.  Press any key during the test to continue." << std::endl;
	BST.insert(10);
	system("pause");
	BST.insert(20);
	system("pause");
	BST.insert(5);
	system("pause");
	BST.insert(4);
	system("pause");
	BST.insert(6);
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
	BST.Delete_Node(5);
	system("pause");
	BST.inorder();
	system("pause");

}