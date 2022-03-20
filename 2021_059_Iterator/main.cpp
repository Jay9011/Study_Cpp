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
	*	기존의 Iterator
	*/
	cout << endl << "기존에 구현된 iterator" << endl;
	vector<int> vecInt;
	vecInt.push_back(10);
	vecInt.push_back(20);
	vecInt.push_back(30);
	vecInt.push_back(40);
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

	/*
	*	구현해야 할 내용
	* 
	*	*myIterator : 현재 iterator가 가리키고 있는 데이터를 가리켜야 한다.
	*	++ (전위, 후위), -- (전위, 후위)
	*	==, != (비교)
	*/
	cout << endl << "직접 구현한 iterator" << endl;
	MyArr<int> myArr;
	myArr.push_back(1);
	myArr.push_back(2);
	myArr.push_back(3);

	MyArr<int>::iterator myIter = myArr.begin();

	// ++ (전위, 후위), ==, != (비교)
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
	*	기존 erase 동작
	*/
	// vector::erase
	vecIter = vecInt.begin();
	vecIter = vecInt.erase(vecIter);	// erase는 삭제된 다음 요소를 가리키는 iterator를 반환한다.
	int i = *vecIter;

	/*
	*	erase 구현.
	*	1. 현재 iterator가 가리키는 데이터 삭제와 함께 사용할 수 없는 iterator임을 저장.
	*	2. erase()로 새로운 iterator를 받아온다.
	*/
	cout << endl << "erase()의 구현" << endl;
	cout << "※ vector.erase()의 특성을 잘 알아야 한다 !!!" << endl;
	myIter = myArr.begin();
	myIter = myArr.erase(myIter);

	for (myIter = myArr.begin(); myIter != myArr.end(); ++myIter)
	{
		cout << *myIter << endl;
	}

	/*
	*	Iterator를 사용해서 짝수만 제거
	*	※ erase() 의 특성을 잘 알아야 한다 !!!
	*/
	cout << endl << "Iterator를 사용해서 짝수만 제거하기" << endl;
	cout << "※ vector.erase()의 특성을 잘 알아야 한다 !!!" << endl;
	vecInt.clear();
	// 1 ~ 10을 벡터에 입력
	for (int i = 0; i < 10; ++i)
	{
		vecInt.push_back(i + 1);
	}

	// 짝수만 제거
	vecIter = vecInt.begin();
	for ( ; vecIter != vecInt.end(); )
	{
		if (0 == *vecIter % 2)
		{
			// 제거
			vecIter = vecInt.erase(vecIter);
			
		}
		else
		{
			// erase()로 제거시 뒤의 요소가 앞으로 당겨오기 때문에 제거하지 않은 경우에만 ++로 증가시킨다.
			++vecIter;
		}
	}

	for (int i = 0; i < vecInt.size(); i++)
	{
		cout << vecInt[i] << endl;
	}

	return 0;
}