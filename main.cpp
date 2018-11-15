/*
  Melroy Dsouza
  Last Edited: November 15, 2018
  Main driver file for testing all BinaryTree methods.
*/


#include <iostream>
#include "BinaryTree.h"
#include <string>
using namespace std;

//test adding nodes to tree + all Traversal methods.
void testBinaryTreeAdd() {
	BinaryTree r1;
	r1.add(3);
	cout << r1.inOrderTraverse() << endl; //should just print 3.
	r1.add(3); //should not add two 3's to BST tree.
	r1.add(4);
	r1.add(7);
	cout << r1.inOrderTraverse() << endl; //should print 3 4 7
	r1.add(33);
	r1.add(-1);
	r1.add(6);
	cout << r1.inOrderTraverse() << endl;
	cout << r1.preOrderTraverse() << endl;
	cout << r1.postOrderTraverse() << endl;
	cout << r1.levelOrderTraverse() << endl;
}

int main() {
	

	testBinaryTreeAdd();
	cin.get(); //stop cmd from exiting after running code.
	
	return 0;
}
