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
		: m_i(1)
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

	// 연산자 오버라이딩 : 해당 클래스에서 연산자를 호출할 때, 해당 함수를 호출한다.
	// 반환타입 operator 연산자 (매개변수)
	MyClass& operator=(const MyClass& _Other)
	{
		// 매개변수는 함수 내에서 변하면 안되기 때문에 const로 선언한다.
		this->m_i = _Other.m_i;

		// 반환 시, this에 해당하는 자료는 지역 종료시 사라지는 것이 아니기 때문에,
		// r-value로 복사된 값을 전달할 필요 없이
		// 바로 자료 그 자체(l-value)로 반환한다
		// MyClass& <= *this	( this는 자기 자신을 가리키는 포인터 )
		return *this;
		// 만약, 지역 내에서 선언된 변수라면 지역 종료시 사라질 수 있기 때문에 복사된 값인 r-value를 리턴시켜야 한다.
	}
};

int main()
{
	MyClass c1;	// 지역변수 ( Stack Memory )
	c1.SetInt(10);
	// Stack Memory 의 지역변수는 main() 함수 종료시 소멸한다.

	MyClass c2;
	c2.SetInt(100);
	MyClass c3;
	c3.SetInt(1000);

	c1 = c2 = c3;
	

	return 0;
}