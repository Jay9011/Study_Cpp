#include <iostream>

struct MyStruct
{
	// C++ 에서는 typedef를 사용하지 않아도 typedef를 사용한 것 처럼 쓸 수 있다.
};

class MyClass
{
	/*
	*	접근 제한 지정자
	*	 : private, protected (상속), public
	* 
	*	맴버변수
	*	 : 해당 클래스가 사용하는 변수. 해당 클래스의 객체가 필요함.
	* 
	*	맴버함수
	*	 : 해당 클래스가 사용하는 함수. 해당 클래스의 객체가 필요함.
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
		this->m_i = i;	// this   는 해당 함수를 호출한 객체의 주소 포인터.
		m_i = i;		// this-> 는 생략될 수 있다. (this->)m_i = i;
	}
};

int main()
{
	MyClass c;	// 지역변수 ( Stack Memory )
	c.SetInt(100);
	// Stack Memory 의 지역변수는 main() 함수 종료시 소멸한다.
	
	return 0;
}