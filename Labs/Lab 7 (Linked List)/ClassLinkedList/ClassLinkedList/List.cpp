#include "List.h"

// default constructor; will always set mpHead to NULL or nullptr
List::List()
{
	mpHead = nullptr;
}

// copy constructor - implicitly invoked copying a List object during construction of 
// another List object, or when a List object is passed-by-value - must perform a deep copy, 
// which means create new memory for each node copied!
List::List(const List& copyList)
{
	// fill in your code here!
	if (copyList.mpHead == nullptr)
	{
		return;
	}

	ListNode *pCur = copyList.mpHead;
	ListNode *pMem = new ListNode;
	ListNode* pNew = new ListNode;
	
	this->mpHead = pMem;

	// pCur = pCur->getNextPtr();

	while (pCur != nullptr)
	{
		pMem->setData(pCur->getData());
		pMem->setNextPtr(pNew);

		pNew = new ListNode;
		pCur = pCur->getNextPtr();
		pMem = pNew;
	}
}

List::~List()                   // destructor - implicitly invoked when a List object leaves scope
{
	cout << "Inside List's destructor! Freeing each ListNode in the List!" << endl;
	destroyList();
}

// this function must allocate new memory for each of the nodes in rhs to construct "this" object
List& List::operator= (const List& rhs) // overloaded assignment operator - must perform a deep copy
{
	// you must use a loop, which visits each of the nodes in List rhs, and assign the data to the new nodes
	// How to use new operator? ListNode *pMem = new ListNode; new is similar to the results of using malloc ()

	// fill in your code here!
	ListNode* pCur = rhs.mpHead;
	ListNode* pMem = new ListNode;
	ListNode* pNew = new ListNode;

	this->mpHead = pMem;

	// pCur = pCur->getNextPtr();

	while (pCur != nullptr)
	{
		pMem->setData(pCur->getData());
		pMem->setNextPtr(pNew);

		pNew = new ListNode;
		pCur = pCur->getNextPtr();
		pMem = pNew;
	}

	return (*this);
}

// getter
ListNode* List::getHeadPtr() const     // returns a copy of the address stored in mpHead
{
	return mpHead;
}

// setter
void List::setHeadPtr(ListNode* const pNewHead) // modifies mpHead
{
	mpHead = pNewHead;
}

// This function creates a new ListNode on the heap, and uses the ListNode constructor to initialize the node!
bool List::insertAtFront(const int newData)     // inserts newData at the beginning or front of the list
{
	ListNode* pMem = makeNode(newData);
	bool success = false;                   // C++ has built in bool types - false, true

	if (pMem != nullptr)
	{
		success = true; // allocated memory successfully
		// pMem is pointing to a ListNode object, but a List object does not have direct access to it; must use a setter!
		pMem->setNextPtr(mpHead);
		mpHead = pMem;
	}

	return success;
}

// insert newData in ascending order
bool List::insertInOrder(const int newData)
{
	bool success = false, inPosition = false;

	// fill in your code here!
	ListNode *pCur = this->mpHead;
	ListNode *pMem = new ListNode(newData);

	// Moves pCur to position that pMem should be inserted in (to get index value)
	int index = 0;
	while (inPosition == false)
	{
		if (pMem->getData() > pCur->getData())
		{
			pCur = pCur->getNextPtr();
			++index;
		}
		else
		{
			inPosition = true;
		}
	}
	// Moves pCur to position 1 before the insertion point
	pCur = this->mpHead;
	for (int i = 0; i < index - 1; ++i)
	{
		pCur = pCur->getNextPtr();
	}
	// Saves next node's address (next link)
	ListNode* temp = pCur->getNextPtr();

	// Inserts pMem
	pCur->setNextPtr(pMem);

	// Reconnects next link
	pMem->setNextPtr(temp);

	// Sets pCur to inserted node
	pCur = pCur->getNextPtr();

	// Checks if the inserted data matches the passed in data
	if (pCur->getData() == newData)
	{
		success = true;
	}

	return success;
}

// inserts newData at the end of the list
bool List::insertAtEnd(const int newData)
{
	bool success = false;

	// fill in your code here!
	ListNode* pCur = this->mpHead;
	
	// Sets pCur to last node in list
	while (pCur->getNextPtr() != nullptr)
	{
		pCur = pCur->getNextPtr();
	}

	ListNode* pMem = new ListNode(newData);

	// Inserts pMem at end, it's next ptr is already null
	pCur->setNextPtr(pMem);

	// Sets pCur back to beginning of list
	pCur = this->mpHead;

	// Sets pCur to end of list
	while (pCur->getNextPtr() != nullptr)
	{
		pCur = pCur->getNextPtr();
	}
	// Checks if last node is the node that was supposed to be inserted
	if (pCur->getData() == newData)
	{
		success = true;
	}

	return success;
}

// determines if the list is empty;  
// returns true if the list is empty; false otherwise
bool List::isEmpty()
{
	return (mpHead == nullptr);
}

// deletes the node at the front of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtFront()
{
	int data = 0;

	// fill in your code here! use the delete operator!

	return data;
}

// deletes the node with data == searchValue;
// returns true if the value was found; false otherwise
// precondition: list must not be empty
bool List::deleteNode(const int searchValue)
{
	bool success = false;

	// fill in your code here! use the delete operator!

	return success;
}

// deletes the node at the end of the list and returns a copy of the data
// precondition: list must not be empty
int List::deleteAtEnd()
{
	int data = 0;

	// fill in your code here! use the delete operator!

	return data;
}

// visits each node, print the node's data
void List::printList()
{
	ListNode* pCur = mpHead;

	while (pCur != nullptr)
	{
		cout << pCur->getData() << endl;
		pCur = pCur->getNextPtr();
	}
}


//////////// private member functions! //////////////

// allocates memory for a Listnode; initializes the memory with newData
ListNode* List::makeNode(const int newData)    // will only call within insert functions
{
	ListNode* pMem = new ListNode(newData);  // ListNode constructor is invoked!

	return pMem;
}

// we created this function so that we could use recursion to delete the nodes!
void List::destroyListHelper(ListNode* const pMem)
{
	if (pMem != nullptr)
	{
		destroyListHelper(pMem->getNextPtr());
		delete pMem;    // delete from the back of list to the front!
	}
}

// deletes each node to free memory; will call in the destructor
void List::destroyList()
{
	destroyListHelper(mpHead);
}