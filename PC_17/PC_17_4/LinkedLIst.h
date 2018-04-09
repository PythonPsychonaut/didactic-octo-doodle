#include <iostream>
#include <iomanip>
using namespace std;

class LinkedList
{
protected:
	struct ListNode
	{
		double value;
		ListNode *next;
		ListNode(double value1, ListNode *next1 = NULL)
		{
			value = value1;
			next = next1;
		}
	};
	ListNode *head;
public:
	LinkedList() { head = NULL; }
	void add(double x);
	bool isMember(double x);
	void print();
	// Copy Constructor
	LinkedList(const LinkedList& original);
private:
	static ListNode *copyList(ListNode *aList);
	bool isMemberSub(ListNode* , double);
};


//********************************************************************************
// add function adds a new node containing x at the front (head) of the list.    *
//********************************************************************************
void LinkedList::add(double x)
{
	if (head == NULL)
		head = new ListNode(x);
	else
		head = new ListNode(x, head);
}

//********************************************************************************
// isMember function accepts a double as an argument and tests it for membership *
//********************************************************************************
bool LinkedList::isMember(double x)
{
 	
 	ListNode *ptr = head;
 	return isMemberSub(ptr, x);
 
}

//********************************************************************************
// isMemberSub recursive function tests to see if the list contains a node with  *
// the value x.                                                                  *
//********************************************************************************
bool LinkedList::isMemberSub(ListNode* ptr, double x)
{
	if (ptr == NULL)
		return false;
	if (ptr->value == x)
		return true;
	else
	{
		ptr = ptr->next;
		return isMemberSub(ptr, x);
	}
}

//********************************************************************************
// Copy Constructor                                                              *
//********************************************************************************
LinkedList::LinkedList(const LinkedList& original)
{
	head = copyList(original.head);
}

//********************************************************************************
// copyList function makes a separate copy of the linked list inside a           *
// Linkedlist object.                                                            *
//********************************************************************************
LinkedList::ListNode * LinkedList::copyList(ListNode * aList)
{
	if (aList == NULL)
		return NULL;
	else
	{
		// First copy the tail
		ListNode *tailCopy = copyList(aList->next);
		// Return copy of  the head attached to copy of tail
		return new ListNode(aList->value, tailCopy);
	}
}

//********************************************************************************
// prints all the elements in the list.                                          *
//********************************************************************************
void LinkedList::print()
{
	ListNode *ptr = head;
	cout << fixed << showpoint << setprecision(1);
	while (ptr != NULL)
	{
		cout << ptr->value << " ";
		ptr = ptr->next;
	}
	cout << endl;
}