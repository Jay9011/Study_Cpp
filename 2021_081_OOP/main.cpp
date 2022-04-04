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
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 
*	다형성, 가상함수 (virtual)
*		- 부모 포인터 타입으로 부모 클래스로부터 파생되는 자식 클래스 객체들의 주소를 가리킬 수 있다.
*		단, 모든 객체를 부모 클래스 타입으로 인식하게 되기 때문에, 실제 객체가 무엇인지 알 수 없다.
* 
*	virtual 키워드를 통해서 각 클래스는 자신만의 고유한 가상함수 테이블을 가지게 된다.
*	각 클래스의 객체들은 가상함수 테이블 포인터에서 해당 클래스에 맞는 테이블을 가리키게 된다.
*	그 테이블에는 해당 클래스의 가상함수들이 등록되어 있다.
* 
*	┌ 다운 캐스팅
*		- 부모 클래스에서 선언되지 않은, 오직 자식쪽에서만 추가된 함수를 호출하고 싶을 때
*		자식 포인터 타입으로 일시적으로 캐스팅 해서 호출한다.
*		단, 문제가 발생할 수 있기 때문에 ! dynamic_cast ! 로 안전하게 확인해 볼 수 있다.
*	├ RTTI (Run Time Type Identification or Information) : 런타임 중에 실제 타입 정보를 확인할 수 있다.
* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* 
*	추상화
*		- 실제 객체를 생성할 목적의 클래스가 아닌, 상속을 통해서 구현해야 할 내용을 전달하는 상속 목적으로 만들어진 클래스
*		virtual , = 0 (1 개 이상의 순수가상함수를 포함하면 추상클래스가 된다.)
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

	virtual void vOutput()
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

	virtual void vOutput()
	{
		cout << "Child" << endl;
	}

	void OnlyChild()
	{
		cout << "Only Child" << endl;
	}
};

int main()
{
	cout << "child는 Parent를 가지고 있다." << endl;
	CParent parent;
	parent.Output();

	CChild	child;
	child.CParent::Output();
	cout << endl;
	cout << "---------------------------------" << endl;

	// 상속 and 포인터
	CParent* pParent = &child;	// Parent를 상속받은 객체는 Parent* 로 가리킬 수 있다.
	//CChild* pChild = &parent;

	cout << "pParent로 parent를 가리킨 상태" << endl;
	parent.Output();
	pParent = &parent;
	pParent->Output();
	
	cout << "pParent로 child를 가리킨 상태" << endl;
	child.Output();		// Child
	pParent = &child;
	pParent->Output();	// Parent (이미 parent*로 읽을 공간을 Parent로 제한했기 때문에 Parent를 읽는다.)
	cout << endl;
	cout << "---------------------------------" << endl;
	
	cout << "가상함수 키워드를 사용한 상태" << endl;
	child.vOutput();	// Child
	pParent = &child;
	pParent->vOutput();	// Child (이미 parent*로 읽을 공간을 Parent로 제한했기 때문에 Parent를 읽는다.)
	cout << endl;
	cout << "---------------------------------" << endl;

	cout << "dynamic_cast를 통해 자식 클래스만이 가지고 있는 함수를 호출" << endl;
	CChild* pChild = dynamic_cast<CChild*>(pParent);	// casting이 실패한 경우 NULL을 반환한다.
	if (nullptr != pChild)
	{
		pChild->OnlyChild();
	}
	cout << endl;
	cout << "---------------------------------" << endl;


	return 0;
}