/******************************************************************************
Brief Description: A header file containing Iterator and List classes

Motivation: A way for a data structure to expose its elements without
without exposing its internal structure. It also allows you to provide
different ways of traversing the structure.
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
	virtual ~Iterator() {};
};

// TODO: Convert this List class to a templated version that supports the Iterator pattern
// Note: You are to maintain all functionality of the original list class and
//       also implement the commented iterator-based classes & functions
template<typename T>
class List
{
private:
	struct Node
	{	
		T data; 
		Node* next;
		Node(const T& _data) : data(_data), next() {};
		~Node() {};
	};
	Node* head;
	int size;
	T defaultValue;

public:
	// TODO: Default Constructor
	List() : head(nullptr) { size = 0; };

	// TODO: Copy Constructor, must ensure that data is copied and not linked
	List(const List& _rhs) : head(nullptr) {
		head = new Node(_rhs.head -> data);
		Node* temp = _rhs.head;
		Node* curr = head;
		while (temp -> next != nullptr) {
			Node* node = new Node(temp -> next -> data);
			curr -> next = node;
			temp = temp -> next;
			curr = curr -> next;
		}
		size = _rhs.size;
	};
	
	// TODO: Deconstructor, must ensure all allocated memory is freed
	~List() { Clear(); };

	// TODO: adds the item to the front of the list (at the head)
	void PushFront(const T& _value) {
		Node* node = new Node(_value);
		if (head == nullptr) {
			head = node;
		}
		else {
			node -> next = head;
			head = node;
		}
		++size;
	};

	// TODO: adds the item to the end of the list (at the tail)
	void PushBack(const T& value_) {
		Node* node = new Node(value_);
		Node* curr = head;
		if (head == nullptr) {
			head = node;
		}
		else {
			while (curr -> next != nullptr) {
				curr = curr -> next;
			}
			curr -> next = node;
		}
		++size;
	};

	// TODO: removes the first item (head) in the list and return the value
	// If there's nothing to remove, do nothing and return the type default value
	// You are to ensure the removed Node's memory is properly freed from this operation
	T PopFront() { 		
		Node* temp = head;
		int toReturn;
		if (temp == nullptr)
			return defaultValue;
		if (head != nullptr) {
			toReturn = temp -> data;
			head = head -> next;
		}
		delete temp;
		--size;
		return toReturn; 
	};

	// TODO: removes the last item (tail) in the list and return the value
	// If there's nothing to remove, do nothing and return the type default value
	// You are to ensure the removed Node's memory is properly freed from this operation
	T PopBack() { 
		Node* curr = head;
		Node* prev = nullptr;
		int toReturn;
		if (curr == nullptr)
			return defaultValue;
		else 
		{
			while (curr -> next != nullptr) {
				prev = curr;
				curr = curr -> next;
			}
			prev -> next = nullptr;
			toReturn = curr -> data;
			delete curr;
		}
		--size;
		return toReturn; 
	};

	// TODO: returns the number of items in the list
	size_t Count() const { return size; };

	// TODO: returns true if empty, else false
	inline bool IsEmpty() const { 
		if (head == nullptr)
			return true;
		return false;
	};

	// TODO: clears the list, must ensure that all allocated memory is freed
	void Clear() {
		Node* curr;
		Node* temp;
		if (head == nullptr)
			return;
		curr = head;
		while (curr -> next != nullptr) {
			temp = curr -> next;
			delete curr;
			curr = temp;
			--size;
		}
		delete curr;
		--size;
		head = nullptr;
	};

	// TODO: class ForwardIterator that implements Iterator (Starts from head and goes to tail)
	class ForwardIterator : public Iterator<T>
	{
	private:	
		List<T>& linkedList;
		Node* cursor;

	public:
		ForwardIterator(List<T>& _linkedList)
			: linkedList(_linkedList), cursor(nullptr) {}

		void Reset() {
			cursor = linkedList.head;
		}

		void Next() {
			cursor = cursor -> next;
		}
		
		bool IsDone() const {
			return cursor == nullptr;
		}

		T& Current() {
			return cursor -> data;
		}
	};

	// TODO: class ReverseIterator that implements Iterator (Starts from tail and goes to head)
	class ReverseIterator : public Iterator<T>
	{
	private:	
		List<T>& linkedList;
		Node* cursor;
		int indexOfNode = 0;

	public:
		ReverseIterator(List<T>& _linkedList)
			: linkedList(_linkedList), cursor(nullptr) {}

		void Reset() {
			cursor = linkedList.head;
			while (cursor -> next != nullptr) {
				cursor = cursor->next;
			}
			indexOfNode = linkedList.Count() - 1;
		}

		void Next() {
			if (indexOfNode != 0) {
				cursor = linkedList.head;
				for (int i = 1; i < indexOfNode; ++i)
					cursor = cursor->next;
				--indexOfNode;
			} else {
				cursor = linkedList.head;
				--indexOfNode;
			}
		}
		
		bool IsDone() const {
			return indexOfNode < 0;
		}

		T& Current() {
			return cursor->data;
		}
	};

	

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
	inline ForwardIterator* CreateForwardIterator() {
		return new ForwardIterator(*this);
	}
	//TODO: inline ReverseIterator* CreateReverseIterator()
	inline ReverseIterator* CreateReverseIterator() {
		return new ReverseIterator(*this);
	}
};

#endif // TEMPLATED_LINKED_LIST_H

/*
Your implementation will be tested against a fixed driver which will be using the intended interface.
Penalties will be imposed if your implementation does not work with the fixed driver.
*/

//http://www.cplusplus.com/articles/E3wTURfi/
//https://distance.sg.digipen.edu/file.php/3607/Week_3_Materials/Iterator.cpp
//https://codereview.stackexchange.com/a/42964 
//https://gist.github.com/erogol/8539526 
//http://www.cplusplus.com/forum/beginner/165512/
