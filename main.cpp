/*
  Melroy Dsouza
  Last Edited: Nov 16, 2018
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


//test print sideways the binary tree.
void testBinaryPrintTree() {
	BinaryTree r1;
	r1.printTree();
	r1.add(3);
	r1.printTree();
	r1.add(4);
	r1.add(99);
	r1.add(-2);
	r1.add(-1);
	r1.add(-3);
	r1.printTree();
}
void testBinaryTreeClear() {
	BinaryTree r1;
	r1.printTree();
	r1.deleteAll();
	r1.printTree();
	r1.add(3);
	r1.printTree();
	r1.deleteAll();
	r1.printTree();
	r1.add(3); r1.add(4); r1.add(-2); r1.add(8); r1.add(88);
	r1.printTree();
	r1.deleteAll();
	r1.printTree();
}
int main() {
	

	testBinaryTreeAdd();
	testBinaryPrintTree();
	testBinaryTreeClear();

	cin.get(); //stop cmd from exiting after running code.
	
	return 0;
}
