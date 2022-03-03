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
		: m_i(100)
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
};

int main()
{
	MyClass c;	// �������� ( Stack Memory )
	c.SetInt(100);
	// Stack Memory �� ���������� main() �Լ� ����� �Ҹ��Ѵ�.
	
	return 0;
}