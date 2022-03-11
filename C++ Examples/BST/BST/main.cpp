// This example illustrates how to implement a binary search tree (BST) in C++
// with templates.

// History 3/11/22 - Implemented a destructor for the BST. We discussed different
//                   ways to implement it! 
//         3/9/22 - Discussed friend classes. We made class BST a friend of
//                  class Node, so that class BST could access the private
//                  data members of the class directly instead of via getters/setters.
//                  This is an example where, in general, using a friend class
//                  is acceptable because of the close relationship between
//                  a BST object and Node objects. We also overloaded operator <
//                  for Rational objects so that we could use Rational objects
//                  and insert into the tree. We discussed the algorithms
//                  behind preorder and postorder traversal of a tree. We
//                  haven't implemented the code for those yet though.
//         3/7/22 - Implemented the private version of BST::insert (). Implemented
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
	BST<Rational> t2;

	t1.insert(10);
	t1.insert(15);
	t1.insert(5);
	t1.insert(12);
	t1.insert(10);

	t1.inorderTraversal();

	Rational r1(5, 2), r2(7, 3), r3(5);

	t2.insert((Rational)10); // placed this in the code after class. try to explain to yourself what the argument means. what functions are called?
	t2.insert(r1);
	t2.insert(r2);
	t2.insert(r3);
	
	t2.inorderTraversal();

	return 0;
}