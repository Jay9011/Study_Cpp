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
	std::cout << vecInt.at(0) << std::endl;		// 특정 위치의 노드를 가져온다.

	std::list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(20);

	std::vector<int>::iterator vecIter = vecInt.begin();	// vecIter가 vecInt의 첫 번째 요소를 가리키게 한다.
	*vecIter = 100;		// iterator가 가리키는 위치의 값을 수정.
	vecInt[0] = 100;	// 위와 같은 동작

	std::list<int>::iterator listIter = listInt.begin();
	int iData = *listIter;
	++listIter;			// 다음 노드를 가리키게 한다.
	iData = *listIter;

	return 0;
}