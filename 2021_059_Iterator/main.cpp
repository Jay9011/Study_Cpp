#include <iostream>
#include <vector>
#include <list>

/*
*	iterator
*/

int main()
{
	std::vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	std::cout << vecInt.at(0) << std::endl;		// Ư�� ��ġ�� ��带 �����´�.

	std::list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(20);

	std::vector<int>::iterator vecIter = vecInt.begin();	// vecIter�� vecInt�� ù ��° ��Ҹ� ����Ű�� �Ѵ�.
	*vecIter = 100;		// iterator�� ����Ű�� ��ġ�� ���� ����.
	vecInt[0] = 100;	// ���� ���� ����

	std::list<int>::iterator listIter = listInt.begin();
	int iData = *listIter;
	++listIter;			// ���� ��带 ����Ű�� �Ѵ�.
	iData = *listIter;

	return 0;
}