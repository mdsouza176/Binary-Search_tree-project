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
	
	return false;
}

//Not completed yet.
void BinaryTree::setBrother(BinaryNode * root)
{
	if (root == nullptr) {
		return;
	}
	std::queue<BinaryNode*> *s1;
	std::queue<BinaryNode*> *s2;
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

