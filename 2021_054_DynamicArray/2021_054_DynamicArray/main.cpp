#include <iostream>
#include "Arr.h"

int main()
{
	/*
	*	����ü --> Ŭ����
	* 
	*	C++ ���� �Ҵ� new, delete
	* 
	*	Class�� �����Ҵ翡 �־, �����Ϸ��� �޸𸮸� �Ҵ��ϰ�, ����� �ʱ�ȭ �� ����, �����ڸ� ȣ���ؾ� �Ѵ�.
	*	������! malloc�� ����ϰ� �Ǹ� ����� �� �޸𸮸� �Ҵ��ϴ� Ű�����̱� ������ � �ڷḦ ���� ������ �Ҵ��ϴ��� �� ����� ����.
	*	���� ���°Ϳ� new, delete �̴�.
	* 
	*	new		: Class�� �����صΰ� �ֱ� ������, �ڷ����� �ٿ���� �Ѵ�.
	* 
	*		Class* myClass = new Class;
	* 
	*	delete	: �����Ҵ� �� �޸𸮸� ��������� �ϴµ�, �̶� �����ͷ� �����Ҵ� �� �޸��� �ּҸ� �޾ư���.
	*			 ���� �ش� �޸𸮸� �����Ͽ� Class�� ��� �Ҹ��ڸ� ȣ���ϰ� �޸𸮸� �������ش�.
	*			 ���ӵ� �ڷ��� ��쿡�� delete[] �� ���ӵ� �ڷ����� �˷���� �Ѵ�. ( heap �޸𸮿��� ���ӵ� ������ ��� �������� �������ڿ��� ���ִ�. string ó�� )
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