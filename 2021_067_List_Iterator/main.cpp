#include <iostream>
#include <list>
#include "MyList.h"

using std::cout;
using std::endl;
using std::list;

int main()
{
	list<int> intList;
	intList.push_back(100);
	intList.push_back(300);

	cout << endl << "기존에 구현된 List Iterator의 insert(), begin(), end()" << endl;
	list<int>::iterator intIter = intList.begin();
	intIter = intList.insert(++intIter, 200);
	for (intIter = intList.begin(); intIter != intList.end(); ++intIter)
	{
		cout << *intIter << endl;
	}

	/*
	*	List Iterator
	*/
	cout << endl << "새롭게 구현한 MyList Iterator의 insert(), begin(), end()" << endl;
	MyList<int> myList;

	myList.PushBack(100);
	myList.PushBack(200);
	myList.PushBack(300);

	MyList<int>::iterator listIter = myList.begin();
	*listIter = 150;
	// insert() : 현재 iterator가 가리키는 위치에 새로운 노드를 삽입한다.
	listIter = myList.begin();
	myList.insert(listIter, 50);

	for (listIter = myList.begin(); listIter != myList.end(); ++listIter)
	{
		cout << *listIter << endl;
	}

	return 0;
}