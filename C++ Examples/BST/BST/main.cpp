#include "BST.h"

int main(void)
{
	BST<int> t1;

	// order of insertion changes tree layout
	t1.insert(10);
	t1.insert(15);
	t1.insert(5);
	t1.insert(12);
	t1.insert(10);

	t1.inorderTraversal();

	return 0;
}