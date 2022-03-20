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

	cout << endl << "������ ������ List Iterator�� insert(), begin(), end()" << endl;
	list<int>::iterator intIter = intList.begin();
	intIter = intList.insert(++intIter, 200);
	for (intIter = intList.begin(); intIter != intList.end(); ++intIter)
	{
		cout << *intIter << endl;
	}

	/*
	*	List Iterator
	*/
	cout << endl << "���Ӱ� ������ MyList Iterator�� insert(), begin(), end()" << endl;
	MyList<int> myList;

	myList.PushBack(100);
	myList.PushBack(200);
	myList.PushBack(300);

	MyList<int>::iterator listIter = myList.begin();
	*listIter = 150;
	// insert() : ���� iterator�� ����Ű�� ��ġ�� ���ο� ��带 �����Ѵ�.
	listIter = myList.begin();
	myList.insert(listIter, 50);

	for (listIter = myList.begin(); listIter != myList.end(); ++listIter)
	{
		cout << *listIter << endl;
	}

	return 0;
}