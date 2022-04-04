#include <iostream>
/*
* 
*	객체지향 언어 특징
* 
*	1. 캡슐화 (은닉성)
*	2. 상속		: 자식 or 부모 클래스는 상속관계에서 다른 클래스의 멤버를 초기화 할 수 없다. (생성자 함수를 호출할 수 있다.)
*	3. 다형성
*	4. 추상화
* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 
*	상속 
*		- 자식 or 부모 클래스는 상속관계에서 다른 클래스의 멤버를 초기화 할 수 없다.
* 
*	생성자 '호출' 순서				: 주체가 되는 Class 부터 ( 자식 -> 부모 )
*	생성자 '실행' ('초기화') 순서	: 마지막으로 불려진 생성자부터 ( 부모 -> 자식 )
*	소멸자 '호출', '실행' 순서		: 소멸자 완료 후에 상속받은 상위 소멸자를 호출 ( 자식 -> 부모 )
* 
*	오버라이딩 : 부모 클래스의 멤버함수를 자식쪽에서 재정의 함으로써, 자식 클래스에 구현된 기능이 호출되도록 한다.
* 
* 
*/
using namespace std;
class CParent
{
protected:
	int		m_i;

public:
	CParent()
		: m_i(0)
	{
		cout << "Parent 생성자 실행" << endl;
	}
	CParent(int i)
		: m_i(i)
	{
		cout << "Parent 생성자2 실행" << endl;
	}
	~CParent()
	{
		cout << "Parent 소멸자 실행" << endl;
	}
	
	void SetInt(int _a)
	{
		m_i = _a;
	}

	void Output()
	{
		cout << "Parent" << endl;
	}
};

class CChild : public CParent
{
private:
	float	m_f;

public:
	CChild()
		: CParent()
		, m_f(0.f)
	{
		cout << "Child 생성자 실행" << endl;
	}
	CChild(int i)
		: CParent(i)		// 명시적으로 상위 생성자를 지정할 경우 기본생성자가 아닌 명시된 상위 생성자를 호출한다.
		, m_f(0.f)
	{
		cout << "Child 생성자2 실행" << endl;
	}
	~CChild()
	{
		cout << "Child 소멸자 실행" << endl;
	}

	void SetFloat(float _f)
	{
		m_f = _f;
	}

	// 상속 받은 부모 클래스 함수를 재정의 (오버라이드)
	void Output()
	{
		cout << "Child" << endl;
	}
};

int main()
{
	CParent parent;
	parent.Output();

	CChild	child;
	child.CParent::Output();
	child.SetInt(10);
	

	return 0;
}