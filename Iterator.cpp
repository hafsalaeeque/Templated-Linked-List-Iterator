// Iterator design pattern example
//
// Motivation: A way for a data structure to expose its elements without
// without exposing its internal structure. It also allows you to provide
// different ways of traversing the structure.
//
#include <iostream>
using namespace std;

template<typename T>
class Iterator {
public:
	virtual void Reset() = 0;
	virtual void Next() = 0;
	virtual bool IsDone() const = 0;
	virtual T& Current() = 0;
};

// Simple data structure that works like std::vector
// but does not expand. 
template<typename T>
class FixedVector 
{
	T * arr;
	int capacity;
	int size;
public:
	// Iterator
	class ForwardIterator : public Iterator<T> {
		FixedVector<T>& container;
		int current;
	public:
		ForwardIterator(FixedVector<T>& container)
			: container(container), current(0) {}

		void Reset() override {
			current = 0;
		}

		void Next() override {
			if (current < container.GetSize())
				++current;
		}

		bool IsDone() const override  {
			return current == container.GetSize();
		}

		T& Current() override  {
			return container.arr[current];
		}

	};

	class ReverseIterator : public Iterator<T> {
		FixedVector<T>& container;
		int current;
	public:
		ReverseIterator(FixedVector<T>& container)
			: container(container), current(container.GetSize() - 1) {}

		void Reset() override {
			current = container.GetSize() - 1;
		}

		void Next() override {
			if (current >= 0)
				--current;
		}

		bool IsDone() const override {
			return current == -1;
		}

		T& Current() override {
			return container.arr[current];
		}

	};

	// Class functions
	FixedVector(size_t capacity)
		: capacity(capacity), size(0)
	{
		arr = new T[capacity];
	}

	~FixedVector() {
		delete[] arr;
	}

	void PushBack(const T& item) {
		if (size == capacity)
			return; 
		arr[size++] = item;
	}

	void PopBack() {
		if (size > 0)
			--size;
	}

	inline int GetSize() {
		return size;
	}

	inline int GetCapacity() {
		return capacity;
	}

	inline ForwardIterator* CreateBeginIterator() {
		return new ForwardIterator(*this);
	}

	inline ReverseIterator* CreateReverseIterator() {
		return new ReverseIterator(*this);
	}

};

// This function does not care about the type of iterator as long
// as it inherits from the Iterator<T> interface!
template<typename T>
void print(Iterator<T>* itr) {
	for (; !itr->IsDone(); itr->Next()) {
		cout << itr->Current() << " ";
	}
	itr->Reset(); // reset because I'm nice guy
}

int main() {
	FixedVector<int> fixedVector(10);
	for (int i = 0; i < 10; ++i) {
		fixedVector.PushBack(i);
	}

	FixedVector<int>::ForwardIterator* beg = fixedVector.CreateBeginIterator();
	FixedVector<int>::ReverseIterator* rbeg = fixedVector.CreateReverseIterator();

	print(beg);
	cout << endl;
	print(rbeg);
	
	cout << endl;

	delete beg;
	delete rbeg;
	system("pause");
}

