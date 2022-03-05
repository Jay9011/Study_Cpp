#include <iostream>
#include "Arr.h"

int main()
{
	/*
	*	구조체 --> 클래스
	* 
	*	C++ 동적 할당 new, delete
	* 
	*	Class의 동적할당에 있어서, 컴파일러는 메모리를 할당하고, 멤버를 초기화 한 다음, 생성자를 호출해야 한다.
	*	하지만! malloc을 사용하게 되면 상수로 된 메모리를 할당하는 키워드이기 때문에 어떤 자료를 담을 공간을 할당하는지 알 방법이 없다.
	*	따라서 나온것에 new, delete 이다.
	* 
	*	new		: Class를 염두해두고 있기 때문에, 자료형을 붙여줘야 한다.
	* 
	*		Class* myClass = new Class;
	* 
	*	delete	: 동적할당 된 메모리를 해제해줘야 하는데, 이때 포인터로 동적할당 된 메모리의 주소를 받아간다.
	*			 이후 해당 메모리를 참조하여 Class의 경우 소멸자를 호출하고 메모리를 해제해준다.
	*			 연속된 자료의 경우에는 delete[] 로 연속된 자료임을 알려줘야 한다. ( heap 메모리에는 연속된 공간의 경우 마지막에 마감문자열이 들어가있다. string 처럼 )
	* 
	*		delete myClass;
	*		delete[] arr;
	* 
	*/
	Arr arr;
	arr.PushBack(10);
	arr.PushBack(20);
	arr.PushBack(30);

	arr[1] = 100;
	int iData = arr[1];

	std::cout << "iData : " << iData << std::endl;

	return 0;
}