#pragma once
#ifndef BST_H
#define BST_H
#include <iostream>
template<typename Type>
struct NODE
{
	Type Key;
	NODE* left;
	NODE * right;
	NODE* Parent; //will implement if time allows
	//constructor of the Node maybe called within the recursive insert functions to pass values into the Binary Search Tree
	/*NODE(const Type & K, NODE*left_child, NODE*right_child) :Key{ K }, left{ left_child }, right{ right_child }
	{}*/
	NODE( Type K)
	{
		Key = K;
		left = nullptr;
		right = nullptr;
		Parent = nullptr;  //will implement if time allows
	}
};
template<typename Type>
class BST
{
public:
	BST()
	{

	}
	void inorder()
	{

		inorder(root);

	}

	NODE<Type> * insert(Type K)
	{
		//first insertion operation, setting root value on first insertion call
		if (root == nullptr)
		{
			//declaring a new node for root with k value for the key
			root = new NODE<Type>(K);
			return root;
		}
		else
		{
			//testing the fundamental structure of the binary search tree
			std::cout << "Root: " << root->Key << std::endl;
			if (root->left != nullptr)
			{
				//displays left child value to show successful creation of left child for the root node
				std::cout << "Left Child: " << root->left->Key << std::endl;
				//displays the parent Node Value to show successful parent creation
				std::cout << "Left Parent: " << root->left->Parent->Key << std::endl;
			}
			if (root->right !=nullptr)
			{
				//displays right child value to show successful creation of right child for the root node
				std::cout << "Right Child: " << root->right->Key << std::endl;
				//displays the parent Node Value to show successful parent creation
				std::cout << "Right Parent: " << root->right->Parent->Key << std::endl;
			}
			//recursive call function takes user input k value and root from BST class returns a pointer
			return insert(K, root);
		}
		
		
	}

	void Delete_Node(Type K)
	{
		Delete_Node(K, root);
	}
	~BST()
	{
		Delete_Tree(root);
	}

private:



	NODE<Type>* root = nullptr;
	//private Methods used for recursion
	NODE<Type> * insert(Type K, NODE<Type>* node)
	{
		if (node == nullptr)
		{
			node = new NODE<Type>(K);
			std::cout << "Node Successfully inserted: " << node->Key << std::endl;
			return node;
			
		}
		else if (K < node->Key)
		{
			NODE<Type>* left_child = insert(K, node->left);
			node->left = left_child;
			left_child->Parent = node;
			if (node->Parent != nullptr)
			{
				std::cout << "Parent: " << node->Parent->Key << std::endl;
			}
			return node;
		}
		else if (K > node->Key)
		{
			//recursive call moving right
			NODE<Type>* right_child = insert(K, node->right);
			//
			node->right = right_child;
			right_child->Parent = node;

			if (node->Parent != nullptr)
			{
				std::cout << "Parent: " << node->Parent->Key << std::endl;
			}
			return node;
		}

	}
	NODE<Type>* Minimum(NODE<Type>*node)
	{
		if (node->left == nullptr)
		{
			return node;
		}
		if (node==nullptr)
		{
			return nullptr;
		}
		return Minimum(node->left);

	}
	NODE<Type>* Maximum(NODE<Type>*node)
	{
		if (node->right == nullptr)
		{
			return node;
		}
		if (node == nullptr)
		{
			return nullptr;
		}
		return Maxmimum(node->right);
	}

	void Delete_Node(Type K, NODE<Type>* node)
	{

		if (K<node->Key)
		{
			Delete_Node(K, node->left);
		}
		else if (K>node->Key)
		{
			Delete_Node(K, node->right);
		}
		else
		{
			//Two Children
			if (node->left != nullptr && node->right != nullptr)
			{
				//create a successor Node that stores the minimum value of the tree
				NODE<Type>*successor = Minimum(node->right);
				successor->Key > successor->Parent->Key ? successor->Parent->right = nullptr : successor->Parent->left = nullptr;
				node->Key = successor->Key;
				delete successor;
			}
			//Node with one child
			else if (node->right == nullptr && node->left!= nullptr)
			{
				
				node->left->Parent = node->Parent;
				node->Parent->left = node->left;
				delete node;
			}
			else if (node->left == nullptr && node->right != nullptr)
			{
				
				node->Parent->right = node->right;
				node->right->Parent = node->Parent;
				
				delete node;
			}
			//no children
			else if (node->left==nullptr && node->right == nullptr)
			{
				node->Key > node->Parent->Key ? node->Parent->right = nullptr : node->Parent->left = nullptr;
				node->Parent = nullptr;
				delete node;
			}
		}
		//if value does not exist, return.
		return;

	}
	void Delete_Tree(NODE<Type>* node)
	{
		if (node != nullptr)
		{
			Delete_Tree(node->left);
			Delete_Tree(node->right);
			delete node;
		}
		node = nullptr;
	}
	void inorder(NODE<Type>*node)
	{
		if (node != nullptr)
		{
			inorder(node->left);
			std::cout << node->Key << std::endl;
			if (node->Parent != nullptr)
			{
				std::cout <<"Parent: "<< node->Parent->Key << std::endl;
			}
			
			inorder(node->right);
		}

	}


};



#endif // !BST_H

/*		else if (node->left != nullptr && node->right != nullptr)
		{
			//find the minimum and swap the value of node with the value of minimum
			node->Key = Minimum(node->right)->Key;
			//perform recursive delete
			Delete_Node(node->Key, node->right);
		}
		else if (node == root)
		{
			NODE<Type> * Delete_root = root;	
			node->Key = Minimum(node->right)->Key;
			root = node;
			delete Delete_root;
		}
		else
		{
			NODE<Type> * Delete_Node = node;
			node = (node->left != nullptr)? node->left:node->right;
				delete Delete_Node;
		}*/
		/*NODE<Type> * temp = node;*/