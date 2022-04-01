#include <iostream>
/*
*	객체지향 언어 특징
*	1. 캡슐화 (은닉성)
*	2. 상속		: 자식 or 부모 클래스는 상속관계에서 다른 클래스의 멤버를 초기화 할 수 없다. (생성자 함수를 호출할 수 있다.)
*	3. 다형성
*	4. 추상화
* 
*	생성자 '호출' 순서 : 주체가 되는 Class ( 자식 -> 부모 )
*	생성자 '실행'('초기화') 순서 : 마지막으로 불려진 생성자부터 ( 부모 -> 자식 )
*/

class CParent
{
protected:
	int		m_i;

public:
	CParent()
		: m_i(0)
	{}
	CParent(int i)
		: m_i(i)
	{}
	
	void SetInt(int _a)
	{
		m_i = _a;
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
	{}
	CChild(int i)
		: CParent(i)		// 명시적으로 상위 생성자를 지정할 경우 기본생성자가 아닌 명시된 상위 생성자를 호출한다.
		, m_f(0.f)
	{
	}

	void SetFloat(float _f)
	{
		m_f = _f;
	}
};

int main()
{
	CParent parent;
	CChild	child;

	return 0;
}