#include <iostream>
/*
* 
*	��ü���� ��� Ư¡
* 
*	1. ĸ��ȭ (���м�)
*	2. ���		: �ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ������ ����� �ʱ�ȭ �� �� ����. (������ �Լ��� ȣ���� �� �ִ�.)
*	3. ������
*	4. �߻�ȭ
* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 
*	��� 
*		- �ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ������ ����� �ʱ�ȭ �� �� ����.
* 
*	������ 'ȣ��' ����				: ��ü�� �Ǵ� Class ���� ( �ڽ� -> �θ� )
*	������ '����' ('�ʱ�ȭ') ����	: ���������� �ҷ��� �����ں��� ( �θ� -> �ڽ� )
*	�Ҹ��� 'ȣ��', '����' ����		: �Ҹ��� �Ϸ� �Ŀ� ��ӹ��� ���� �Ҹ��ڸ� ȣ�� ( �ڽ� -> �θ� )
* 
*	�������̵� : �θ� Ŭ������ ����Լ��� �ڽ��ʿ��� ������ �����ν�, �ڽ� Ŭ������ ������ ����� ȣ��ǵ��� �Ѵ�.
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
		cout << "Parent ������ ����" << endl;
	}
	CParent(int i)
		: m_i(i)
	{
		cout << "Parent ������2 ����" << endl;
	}
	~CParent()
	{
		cout << "Parent �Ҹ��� ����" << endl;
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
		cout << "Child ������ ����" << endl;
	}
	CChild(int i)
		: CParent(i)		// ��������� ���� �����ڸ� ������ ��� �⺻�����ڰ� �ƴ� ��õ� ���� �����ڸ� ȣ���Ѵ�.
		, m_f(0.f)
	{
		cout << "Child ������2 ����" << endl;
	}
	~CChild()
	{
		cout << "Child �Ҹ��� ����" << endl;
	}

	void SetFloat(float _f)
	{
		m_f = _f;
	}

	// ��� ���� �θ� Ŭ���� �Լ��� ������ (�������̵�)
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