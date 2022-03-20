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
	cout << endl << "������ ������ iterator" << endl;
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
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
	cout << endl << "���� ������ iterator" << endl;
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
	int prefixData = *(++myIter);

	myIter = myArr.begin();
	int postfixData = *(myIter++);

	cout << "prefixData : " << prefixData << endl;
	cout << "postfixData : " << postfixData << endl;

	/*
	*	���� erase ����
	*/
	// vector::erase
	vecIter = vecInt.begin();
	vecIter = vecInt.erase(vecIter);	// erase�� ������ ���� ��Ҹ� ����Ű�� iterator�� ��ȯ�Ѵ�.
	int i = *vecIter;

	/*
	*	erase ����.
	*	1. ���� iterator�� ����Ű�� ������ ������ �Բ� ����� �� ���� iterator���� ����.
	*	2. erase()�� ���ο� iterator�� �޾ƿ´�.
	*/
	cout << endl << "erase()�� ����" << endl;
	cout << "�� vector.erase()�� Ư���� �� �˾ƾ� �Ѵ� !!!" << endl;
	myIter = myArr.begin();
	myIter = myArr.erase(myIter);

	for (myIter = myArr.begin(); myIter != myArr.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	/*
	*	Iterator�� ����ؼ� ¦���� ����
	*	�� erase() �� Ư���� �� �˾ƾ� �Ѵ� !!!
	*/
	cout << endl << "Iterator�� ����ؼ� ¦���� �����ϱ�" << endl;
	cout << "�� vector.erase()�� Ư���� �� �˾ƾ� �Ѵ� !!!" << endl;
	vecInt.clear();
	// 1 ~ 10�� ���Ϳ� �Է�
	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// ¦���� ����
	vecIter = vecInt.begin();
	for ( ; vecIter != vecInt.end(); )
	{
		if (0 == *vecIter % 2)
		{
			// ����
			vecIter = vecInt.erase(vecIter);
			
		}
		else
		{
			// erase()�� ���Ž� ���� ��Ұ� ������ ��ܿ��� ������ �������� ���� ��쿡�� ++�� ������Ų��.
			++vecIter;
		}
	}

	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt[i] << endl;
	}

	return 0;
}