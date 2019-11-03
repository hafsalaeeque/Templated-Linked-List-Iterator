/******************************************************************************
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

// TODO: Convert this List class to a `templated version that supports the Iterator pattern`
// Note: You are to maintain all functionality of the original list class and
//       also implement the `commented iterator-based classes & functions`  

template<typename T>
class List
{
private:
	// TODO: Update this work with the `templated List of any type`
	// NOTE: You are to maintain single-forward-link linked list (only next pointer allowed)
	struct Node
	{	//https://codereview.stackexchange.com/a/42964
		T data; 
		// int data;	// Data stored //
		// http://users.monash.edu/~jonmc/CSE2305/Topics/10.20.Templates/html/text.html
		Node* next; // Pointer to the next node

		// Constructor
		// Node(const int& _data) : data(_data), next(nullptr) {};
		Node(const int& _data) : data(_data), next() {};
		// Deconstructor
		~Node() {};
	};
	Node* head; // Pointer to the head/front of the list //
public:
	// TODO: Default Constructor
	// List() : head(nullptr) {};
	List<T>() : head(nullptr) {};

	// TODO: Copy Constructor, must ensure that data is copied and not linked
	// List(const List& _rhs) : head(nullptr) {};
	List(const List<T>& _rhs) : head(nullptr) {};
	
	// TODO: Deconstructor, must ensure all allocated memory is freed
	~List<T>() {};

	// TODO: adds the item to the front of the list (at the head)
	// void PushFront(const int& _value) {};
	void PushFront(T data){};

	// TODO: adds the item to the end of the list (at the tail)
	// void PushBack(const int& value_) {};
	void PushBack(T data){};

	// TODO: removes the first item (head) in the list and return the value
	// If there's nothing to remove, do nothing and return the type default value
	// You are to ensure the removed Node's memory is properly freed from this operation
	T PopFront() { return 0; };

	// TODO: removes the last item (tail) in the list and return the value
	// If there's nothing to remove, do nothing and return the type default value
	// You are to ensure the removed Node's memory is properly freed from this operation
	T PopBack() { return 0; };

	// TODO: returns the number of items in the list
	// 
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
	//TODO: class ForwardIterator that implements Iterator (Starts from head and goes to tail)
	//TODO: inline ForwardIterator* CreateForwardIterator()
	class ForwardIterator: public Iterator<T>{
		List<T>& linkedList;
		int current;
	public:
		ForwardIterator(List<T>& linkedList)
			: linkedList(linkedList), current (0){}
		
		void Reset() override{
			current = 0;
		}

		void Next() override{
			if(current < linkedList.GetSize())
				++current;
		}

		bool isDone() const override{
			return current == linkedList.GetSize();
		}

		T& Current() override{
			return linkedList.arr[current];
		}
	};
	//TODO: class ReverseIterator that implements Iterator (Starts from tail and goes to head)
	//TODO: inline ReverseIterator* CreateReverseIterator()
	class ReverseIterator : public Iterator<T> {
		List<T>& linkedList;
		int current;
	public:
		ReverseIterator(List<T>& linkedList)
			: linkedList(linkedList), current(linkedList.GetSize() - 1) {}

		void Reset() override {
			current = linkedList.GetSize() - 1;
		}

		void Next() override {
			if (current >= 0)
				--current;
		}

		bool IsDone() const override {
			return current == -1;
		}

		T& Current() override {
			return linkedList.arr[current];
		}
	};
	inline ForwardIterator* CreateBeginIterator() {
		return new ForwardIterator(*this);
	}

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

// Iterator design pattern example
//
// Motivation: A way for a data structure to expose its elements without
// without exposing its internal structure. It also allows you to provide
// different ways of traversing the structure.
