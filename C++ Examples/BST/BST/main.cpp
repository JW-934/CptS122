// This example illustrates how to implement a binary search tree (BST) in C++
// with templates.

// History 3/7/22 - Implemented the private version of BST::insert (). Implemented
//                  Node::Node (), both private and public versions of
//                  BST::inorderTraversal (). After lecture, I added
//                  getters and setters for class Node.
//         3/4/22 - Implemented the BST constructor. Implemented a public
//                  insert for a BST. Started implementing a private insert ()
//                  for a BST as well.
//         3/2/22 - Filled in the private data members for the BST and Node
//                  classes. Started working on the BST constructor.
//

#include "BST.h"

int main(void)
{
	BST<int> t1;

	t1.insert(10);
	t1.insert(15);
	t1.insert(5);
	t1.insert(12);
	t1.insert(10);

	t1.inorderTraversal();

	return 0;
}