#include <iostream>

struct MyStruct
{
	// C++ 에서는 typedef를 사용하지 않아도 typedef를 사용한 것 처럼 쓸 수 있다.
};

class MyClass
{
	/*
	*	접근 제한 지정자
	*	 : private, protected, public
	*	
	*	멤버변수
	*	 : 해당 클래스가 사용하는 변수
	*	멤버함수
	*	 : 해당 클래스가 사용하는 함수
	*/
private:
	int m_i;

public:
	// 생성자
	MyClass() 
	// Initializer ( 초기화 )
		: m_i(100)
	{
	}

	// 소멸자
	~MyClass()
	{
	}

public:
	void SetInt(int i)
	{
		m_i = i;
	}
};

int main()
{
	MyClass c;	// 지역변수 ( Stack Memory )
	c.SetInt(100);
	// Stack Memory 의 지역변수는 main() 함수 종료시 소멸한다.
	
	return 0;
}