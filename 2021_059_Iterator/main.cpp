#include <iostream>
#include <vector>
#include <list>

using std::cout;
using std::endl;
using std::vector;
using std::list;

/*
*	iterator
*/

int main()
{
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

	// *myIterator : ���� iterator�� ����Ű�� �ִ� �����͸� �����Ѿ� �Ѵ�.
	// ++ (����, ����), -- (����, ����)

	return 0;
}