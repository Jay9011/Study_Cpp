#include <iostream>
#include <vector>
#include <list>
#include "myArr.h"

using std::cout;
using std::endl;
using std::vector;
using std::list;

/*
*	iterator
*/

int main()
{
	/*
	*	������ Iterator
	*/
	cout << "������ ������ iterator" << endl;
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	cout << vecInt.at(0) << endl;		// Ư�� ��ġ�� ��带 �����´�.

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(20);

	vector<int>::iterator vecIter = vecInt.begin();	// vecIter�� vecInt�� ù ��° ��Ҹ� ����Ű�� �Ѵ�.
	*vecIter = 100;		// iterator�� ����Ű�� ��ġ�� ���� ����.
	vecInt[0] = 100;	// ���� ���� ����

	list<int>::iterator listIter = listInt.begin();
	int iData = *listIter;
	++listIter;			// ���� ��带 ����Ű�� �Ѵ�.
	iData = *listIter;

	/*
	*	�����ؾ� �� ����
	* 
	*	*myIterator : ���� iterator�� ����Ű�� �ִ� �����͸� �����Ѿ� �Ѵ�.
	*	++ (����, ����), -- (����, ����)
	*	==, != (��)
	*/
	cout << "���� ������ iterator" << endl;
	MyArr<int> myArr;
	myArr.push_back(1);
	myArr.push_back(2);
	myArr.push_back(3);

	MyArr<int>::iterator myIter = myArr.begin();

	// ++ (����, ����), ==, != (��)
	for (; myIter != myArr.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	myIter = myArr.begin();
	int testData = (*myIter++);

	return 0;
}