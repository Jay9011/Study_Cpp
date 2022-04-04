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
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
* 
*	������, �����Լ� (virtual)
*		- �θ� ������ Ÿ������ �θ� Ŭ�����κ��� �Ļ��Ǵ� �ڽ� Ŭ���� ��ü���� �ּҸ� ����ų �� �ִ�.
*		��, ��� ��ü�� �θ� Ŭ���� Ÿ������ �ν��ϰ� �Ǳ� ������, ���� ��ü�� �������� �� �� ����.
* 
*	virtual Ű���带 ���ؼ� �� Ŭ������ �ڽŸ��� ������ �����Լ� ���̺��� ������ �ȴ�.
*	�� Ŭ������ ��ü���� �����Լ� ���̺� �����Ϳ��� �ش� Ŭ������ �´� ���̺��� ����Ű�� �ȴ�.
*	�� ���̺��� �ش� Ŭ������ �����Լ����� ��ϵǾ� �ִ�.
* 
*	�� �ٿ� ĳ����
*		- �θ� Ŭ�������� ������� ����, ���� �ڽ��ʿ����� �߰��� �Լ��� ȣ���ϰ� ���� ��
*		�ڽ� ������ Ÿ������ �Ͻ������� ĳ���� �ؼ� ȣ���Ѵ�.
*		��, ������ �߻��� �� �ֱ� ������ ! dynamic_cast ! �� �����ϰ� Ȯ���� �� �� �ִ�.
*	�� RTTI (Run Time Type Identification or Information) : ��Ÿ�� �߿� ���� Ÿ�� ������ Ȯ���� �� �ִ�.
* 
* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
* 
*	�߻�ȭ
*		- ���� ��ü�� ������ ������ Ŭ������ �ƴ�, ����� ���ؼ� �����ؾ� �� ������ �����ϴ� ��� �������� ������� Ŭ����
*		virtual , = 0 (1 �� �̻��� ���������Լ��� �����ϸ� �߻�Ŭ������ �ȴ�.)
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
	cout << "child�� Parent�� ������ �ִ�." << endl;
	CParent parent;
	parent.Output();

	CChild	child;
	child.CParent::Output();
	cout << endl;
	cout << "---------------------------------" << endl;

	// ��� and ������
	CParent* pParent = &child;	// Parent�� ��ӹ��� ��ü�� Parent* �� ����ų �� �ִ�.
	//CChild* pChild = &parent;

	cout << "pParent�� parent�� ����Ų ����" << endl;
	parent.Output();
	pParent = &parent;
	pParent->Output();
	
	cout << "pParent�� child�� ����Ų ����" << endl;
	child.Output();		// Child
	pParent = &child;
	pParent->Output();	// Parent (�̹� parent*�� ���� ������ Parent�� �����߱� ������ Parent�� �д´�.)
	cout << endl;
	cout << "---------------------------------" << endl;
	
	cout << "�����Լ� Ű���带 ����� ����" << endl;
	child.vOutput();	// Child
	pParent = &child;
	pParent->vOutput();	// Child (�̹� parent*�� ���� ������ Parent�� �����߱� ������ Parent�� �д´�.)
	cout << endl;
	cout << "---------------------------------" << endl;

	cout << "dynamic_cast�� ���� �ڽ� Ŭ�������� ������ �ִ� �Լ��� ȣ��" << endl;
	CChild* pChild = dynamic_cast<CChild*>(pParent);	// casting�� ������ ��� NULL�� ��ȯ�Ѵ�.
	if (nullptr != pChild)
	{
		pChild->OnlyChild();
	}
	cout << endl;
	cout << "---------------------------------" << endl;


	return 0;
}