#include "linkedList.h"
#include <iostream>

template<typename T>
void print(Iterator<T>* itr){
	for(itr->Reset(); !itr->IsDone(); itr->Next()){
		std::cout << itr->Current() << " " ;
	}
  std::cout << std::endl;
}

struct testobj
{
    int data;
    testobj(): data(0) {}
};

int main()
{
    std::cout << "==== This is a list of int. ==== " << std::endl;
    List<int> a;
    for (int i = 0; i < 10; ++i)
        a.PushBack(i);   
    std::cout << a << std::endl;   

    std::cout << "==== This is a list of int cloned from the one above. ==== " << std::endl;
    List<int> b(a);
    std::cout << b << std::endl;   

    std::cout << "==== This is a list of float. ==== " << std::endl;
    List<float> c;
    for (int i = 0; i < 5; ++i)
    {
      c.PushFront( rand() * 0.01f );
    }
    std::cout << c << std::endl;   

    std::cout << "==== This is a list of std::string. ==== " << std::endl;
    List<std::string> d;
    d.PushBack("I");
    d.PushBack("AM");
    d.PushBack("A");
    d.PushBack("TEAPOT");
    d.PushBack("418");
    std::cout << d << std::endl;   

    std::cout << "==== This is a POINTER FORWARD iterator of a list of int. ==== " << std::endl;
    List<int>::ForwardIterator* f = new List<int>::ForwardIterator(a);
    print(f);
    delete f;

    std::cout << "==== This is a POINTER REVERSE iterator of a copy constructed! list of int. ==== " << std::endl;
    List<int>::ReverseIterator* g = new List<int>::ReverseIterator(b);
    print(g);
    delete g;

    std::cout << "==== This is a FORWARD iterator of a list of float. ==== " << std::endl;
    List<float>::ForwardIterator h(c);
    print(&h);

    std::cout << "==== This is a REVERSE iterator of a list of std::string. ==== " << std::endl;
    List<std::string>::ReverseIterator i(d);
    print(&i);

    std::cout << "=== This is a list of testobject pointers, where testobject is a struct containing an int that will always be 0. ===" << std::endl;
    List<testobj*> z;
    for (int i = 0; i < 2; ++i)
    {
      z.PushBack(new testobj());
    }
    for (int i = 0; i < 2; ++i)
    {
      z.PushFront(new testobj());
    }
    std::cout << z << std::endl;

    std::cout << "=== This is a forward iterator of a list of testobject pointers. ===" << std::endl;
    List<testobj*>::ForwardIterator x(z);// = new List<int>::ForwardIterator(a);
    print(&x);

    std::cout << "=== This is a reverse iterator of a list of testobject pointers. ===" << std::endl;
    List<testobj*>::ReverseIterator w(z);// = new List<int>::ReverseIterator(b);
    print(&w);
    
    std::cout << "Yes, they will be addresses only, because that's the closest thing T can translate to in the print() function." << std::endl;

    std::cout << std::endl; //line feed
    std::cout << "=== Now lets test our iterator by having it clean up our list of testobject pointers. === " << std::endl;
    for (x.Reset(); x.IsDone(); x.Next())
    {
       std::cout << "*** deleting " << x.Current() << " ***" << std::endl;
       delete x.Current();
    }
    std::cout << "This will leave me with " << z.Count() << " items because I still need to run clear()" << std::endl;
    std::cout << z << std::endl;

    z.Clear();
    std::cout << "But once I run clear I have " << z.Count() << " items" << std::endl;
    std::cout << z << std::endl;
    std::cout << std::endl; //line feed

    std::cout << "=== This is a Pointer to a List of Int. === " << std::endl;
    List<int> *pointerList = new List<int>();
    for (int i = 0; i < 10; ++i)
    {
      pointerList->PushBack(rand());
    }    
    std::cout << *pointerList << std::endl;

    std::cout << "=== This is a Pointer Forward Iterator to a Pointer to a List of Int. === " << std::endl;
    List<int>::ForwardIterator* pointerListIterator = new List<int>::ForwardIterator(*pointerList);// = new List<int>::ForwardIterator(a);
    print(pointerListIterator);
    
    delete pointerListIterator;
    delete pointerList;

    std::cout << std::endl; //line feed
    std::cout << "=== Everything should be cleaned up properly at this point. End!=== " << std::endl;
}

