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
	cout << vecInt.at(0) << endl;		// 특정 위치의 노드를 가져온다.

	list<int> listInt;
	listInt.push_back(10);
	listInt.push_back(20);

	vector<int>::iterator vecIter = vecInt.begin();	// vecIter가 vecInt의 첫 번째 요소를 가리키게 한다.
	*vecIter = 100;		// iterator가 가리키는 위치의 값을 수정.
	vecInt[0] = 100;	// 위와 같은 동작

	list<int>::iterator listIter = listInt.begin();
	int iData = *listIter;
	++listIter;			// 다음 노드를 가리키게 한다.
	iData = *listIter;

	// *myIterator : 현재 iterator가 가리키고 있는 데이터를 가리켜야 한다.
	// ++ (전위, 후위), -- (전위, 후위)

	return 0;
}