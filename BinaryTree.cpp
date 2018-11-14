/*
  Melroy Dsouza
  last edited: Nov 11, 2018
  Binary tree .cpp file
*/


#include "BinaryTree.h"



BinaryTree::BinaryTree()
{
}



BinaryTree::~BinaryTree()
{
}
//to be implemented.
bool BinaryTree::add(int value)
{
	if (headptr == nullptr) {
		headptr = new BinaryNode();
		headptr->value = value;
		return true;
	}
	BinaryNode * cur = headptr;
	return addHelper(cur, value);
}

std::string BinaryTree::inOrderTraverse()
{
	std::string output = "InOrder traversal: ";
	if (headptr == nullptr) {
		return output;
	}
	BinaryNode* cur = headptr;
	return inOrderHelper(cur, output);
}

//Not completed yet.
void BinaryTree::setBrother(BinaryNode * root)
{
	if (root == nullptr) {
		return;
	}
	std::queue<BinaryNode*> *s1 = new std::queue<BinaryNode*>();
	std::queue<BinaryNode*> *s2 = new std::queue<BinaryNode*>();
	std::queue<BinaryNode*> *temp;
	s1->push(root);
	while (!s1->empty() && !s2->empty()) {
		BinaryNode* front = s1->front();
		s1->pop();
		if (!s1->empty()) { //set brother pointer if the node
							// is not the last one in the level.
			front->brotherptr = s1->front();
		}
		if (front->leftptr != nullptr) { //add left and right child to
			s2->push(front->leftptr);   //other queue to keep the tree traversal going.
		}
		if (front->rightptr != nullptr) {
			s2->push(front->rightptr);
		}
		if (s1->empty()) { //once the first queue is empty, switch around queue's to check next level. I there
			temp = s1;		//is nothing there, the while loop will exit meaning end of tree.
			s1 = s2;
			s2 = temp;
		}
	}
}

//goes through tree recursively and finds position to add
//node if the node does not already exist in the tree.
bool BinaryTree::addHelper(BinaryNode* cur, int value)
{
	if (cur->value > value) {
		if (cur->leftptr != nullptr) {
			return addHelper(cur->leftptr, value);
		}
		else {
			cur->leftptr = new BinaryNode();
			cur->leftptr->value = value;
			return true;
		}
	}
	else if (cur->value < value) {
		if (cur->rightptr != nullptr) {
			return addHelper(cur->rightptr, value);
		}
		else {
			cur->rightptr = new BinaryNode();
			cur->rightptr->value = value;
			return true;
		}
	}
	else {
		return false;
	}
}

std::string BinaryTree::inOrderHelper(BinaryNode* cur, std::string &s)
{
	if (cur == nullptr) {
		return s;
	}
	inOrderHelper(cur->leftptr, s);
	s += std::to_string(cur->value);
	s += " ";
	inOrderHelper(cur->rightptr, s);
	return s;
}

