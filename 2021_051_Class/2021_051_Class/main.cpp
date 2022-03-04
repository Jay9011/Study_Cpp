#include <iostream>

struct MyStruct
{
	// C++ ������ typedef�� ������� �ʾƵ� typedef�� ����� �� ó�� �� �� �ִ�.
};

class MyClass
{
	/*
	*	���� ���� ������
	*	 : private, protected (���), public
	* 
	*	�ɹ�����
	*	 : �ش� Ŭ������ ����ϴ� ����. �ش� Ŭ������ ��ü�� �ʿ���.
	* 
	*	�ɹ��Լ�
	*	 : �ش� Ŭ������ ����ϴ� �Լ�. �ش� Ŭ������ ��ü�� �ʿ���.
	*/
private:
	int m_i;

public:
	// ������
	MyClass() 
	// Initializer ( �ʱ�ȭ )
		: m_i(1)
	{
	}

	// �Ҹ���
	~MyClass()
	{
	}

public:
	void SetInt(int i)
	{
		this->m_i = i;	// this   �� �ش� �Լ��� ȣ���� ��ü�� �ּ� ������.
		m_i = i;		// this-> �� ������ �� �ִ�. (this->)m_i = i;
	}

	// ������ �������̵� : �ش� Ŭ�������� �����ڸ� ȣ���� ��, �ش� �Լ��� ȣ���Ѵ�.
	// ��ȯŸ�� operator ������ (�Ű�����)
	MyClass& operator=(const MyClass& _Other)
	{
		// �Ű������� �Լ� ������ ���ϸ� �ȵǱ� ������ const�� �����Ѵ�.
		this->m_i = _Other.m_i;

		// ��ȯ ��, this�� �ش��ϴ� �ڷ�� ���� ����� ������� ���� �ƴϱ� ������,
		// r-value�� ����� ���� ������ �ʿ� ����
		// �ٷ� �ڷ� �� ��ü(l-value)�� ��ȯ�Ѵ�
		// MyClass& <= *this	( this�� �ڱ� �ڽ��� ����Ű�� ������ )
		return *this;
		// ����, ���� ������ ����� ������� ���� ����� ����� �� �ֱ� ������ ����� ���� r-value�� ���Ͻ��Ѿ� �Ѵ�.
	}
};

int main()
{
	MyClass c1;	// �������� ( Stack Memory )
	c1.SetInt(10);
	// Stack Memory �� ���������� main() �Լ� ����� �Ҹ��Ѵ�.

	MyClass c2;
	c2.SetInt(100);
	MyClass c3;
	c3.SetInt(1000);

	c1 = c2 = c3;
	

	return 0;
}