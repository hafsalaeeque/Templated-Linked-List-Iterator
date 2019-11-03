/******************************************************************************
filename original.h
Brief Description: A header file containing Iterator and List classes
******************************************************************************/
#ifndef TEMPLATED_LINKED_LIST_H
#define TEMPLATED_LINKED_LIST_H
#include <iostream>

// This is the standard templated iterator class definition
// DO NOT MODIFY! To be used in your linked list implementation
template<typename T>
class Iterator 
{
public:
	virtual void Reset() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual T& Current() = 0;
};

// TODO: Convert this List class to a templated version that supports the Iterator pattern
// Note: You are to maintain all functionality of the original list class and
//       also implement the commented iterator-based classes & functions
class List
{
public:
	// TODO: class ForwardIterator that implements Iterator (Starts from head and goes to tail)
	// TODO: class ReverseIterator that implements Iterator (Starts from tail and goes to head)

	// TODO: Default Constructor
	List() : head(nullptr) {};

	// TODO: Copy Constructor, must ensure that data is copied and not linked
	List(const List& _rhs) : head(nullptr) {};
	
	// TODO: Deconstructor, must ensure all allocated memory is freed
	~List() {};

	// TODO: adds the item to the front of the list (at the head)
	void PushFront(const int& _value) {};

	// TODO: adds the item to the end of the list (at the tail)
	void PushBack(const int& value_) {};

	// TODO: removes the first item (head) in the list and return the value
	// If there's nothing to remove, do nothing and return the type default value
	// You are to ensure the removed Node's memory is properly freed from this operation
	int PopFront() { return 0; };

	// TODO: removes the last item (tail) in the list and return the value
	// If there's nothing to remove, do nothing and return the type default value
	// You are to ensure the removed Node's memory is properly freed from this operation
	int PopBack() { return 0; };

	// TODO: returns the number of items in the list
	size_t Count() const { return 0; };

	// TODO: returns true if empty, else false
	inline bool IsEmpty() const { return false; };

	// TODO: clears the list, must ensure that all allocated memory is freed
	void Clear() {};

	// NOTE: Do not change the printing style!
	friend std::ostream & operator<<(std::ostream& _os, const List& _list) 
	{
		// Print name and opening bracket
		_os << "List(";
		Node* curr = _list.head;

		// Special case for first node (print without comma)
		if (curr != nullptr)
		{
			_os << curr->data;
			curr = curr->next;
		}

		// Print for each node (add comma and then value)
		while (curr != nullptr)
		{
			_os << "," << curr->data;
			curr = curr->next;
		}

		// Print closing bracket and return the ostream
		_os << ")" << std::endl;
		return _os;
	};

	//TODO: inline ForwardIterator* CreateForwardIterator()
	//TODO: inline ReverseIterator* CreateReverseIterator()

private:
	// TODO: Update this work with the templated List of any type
	// NOTE: You are to maintain single-forward-link linked list (only next pointer allowed)
	struct Node
	{
		// Constructor
		Node(const int& _data) : data(_data), next(nullptr) {};
		// Deconstructor
		~Node() {};

		Node* next; // Pointer to the next node
		int data;	// Data stored
	};

	Node* head; // Pointer to the head/front of the list
};

#endif // TEMPLATED_LINKED_LIST_H