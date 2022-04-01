#include <iostream>
/*
*	��ü���� ��� Ư¡
*	1. ĸ��ȭ (���м�)
*	2. ���		: �ڽ� or �θ� Ŭ������ ��Ӱ��迡�� �ٸ� Ŭ������ ����� �ʱ�ȭ �� �� ����. (������ �Լ��� ȣ���� �� �ִ�.)
*	3. ������
*	4. �߻�ȭ
* 
*	������ 'ȣ��' ���� : ��ü�� �Ǵ� Class ( �ڽ� -> �θ� )
*	������ '����'('�ʱ�ȭ') ���� : ���������� �ҷ��� �����ں��� ( �θ� -> �ڽ� )
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
		: CParent(i)		// ��������� ���� �����ڸ� ������ ��� �⺻�����ڰ� �ƴ� ��õ� ���� �����ڸ� ȣ���Ѵ�.
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