int S02_Operator() 
{
	/**
	*	�� ������ ��
	* 
	*	���� ������
	*	�� =
	*	�� ��ǻ�ʹ� ������ ����� ���������� �����(AC)�� �����ϱ� ������ �޸𸮿� ���������� �ݿ��ϱ� ���ؼ��� ���� �����ڸ� �������� �Ѵ�.
	* 
	*	��� ������
	*	�� +, -, *, /, %(modular)
	* 
	*	��� ���� ������
	*	�� +=, -=
	* 
	*	���� ������
	*	�� ++(����), --(����)	: ��� �����ں��� �켱������ ����. (�ذ����ϸ� ���� �����ڸ� ���� ������ ������.)
	*	�� (����)++, (����)--	: ��� �����ں��� ������ �켱������ ����. (���Կ����ں��� ���� ������ ���� ������ ó�� �� ���� �����ڰ� �߻��Ѵ�.)
	*	�� ���� �����ڴ� �Ϲ������� ��������� ����� ������Ų�ٴ� ���� �ƴ϶� ���信 ���� ������ ���Ҹ� ��Ÿ����.
	* 
	*	�� ������
	*	�� ==, !=	: ���ų� �ٸ��� true
	*	�� <, >, <=, >=	: ũ�⸦ ���ؼ� ������ true
	* 
	*	���� ������
	*	�� !(���� ����), &&(���� ��), ||(���� ��)
	* 
	*	�� ��(true), ����(false)
	*		��(true)		: 0�� �ƴ� ��� ���. (�⺻ 1)
	*		����(false)	: 0
	* 
	*	���� ������
	*	�� (���ǹ�):(true��)?(false)	: ���ǹ��� true �� �� true �κ���, false �� �� false �κ��� �����Ѵ�.
	* 
	*/
	int data = 10 + 20;
	data + 30; // �����(AC)�� ����ǰ� �޸𸮿� ���� ������ �ϱ� �� ����

	// data = 10. % 3.;
	// data = 10 % 3.;	// �Ǽ����� �������� ���� ������ ��ȣ�ϱ� ������ modular(%) ������ �Ұ����ϴ�.

	double data2 = 0.25;
	data2++;

	int a = 10;
	a = data++;	// a = 30, data = 31 (���� ���� ���� ���� �����ڰ� �߻��ߴ�.)
	


	return 0;
}