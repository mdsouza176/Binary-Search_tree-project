/*
  Melroy Dsouza
  Last edited: Nov 11, 2018
  Binary tree .h file
*/

#pragma once
#include <queue>
class BinaryTree
{
public:
	BinaryTree();
	~BinaryTree();
	bool add(int value);
	void clear(); //clears all nodes in tree.
	//Traverse nodes in tree based in the traversal and add node values to string and return it.
	std::string inOrderTraverse();
	std::string preOrderTraverse();
	std::string postOrderTraverse();
	std::string levelOrderTraverse(); 
private:
	struct BinaryNode {
		BinaryNode* leftptr{ nullptr };
		BinaryNode* rightptr{ nullptr };
		BinaryNode* brotherptr{ nullptr }; //special pointer to make tree into level-order.
		int value;
	};
	//sets brother for each of the binary nodes in the tree.
	void setBrother(BinaryNode* root);
	BinaryNode* headptr{ nullptr };

};
