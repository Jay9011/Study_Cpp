//int main() 
int S01_DataType()
{
	/**
	*	�� �ڷ��� (DataType) ��
	*	(ũ�� ���� byte) : 1byte == 8bit
	*	�� ������ : char(1), short(2), int(4), long(4), long long(8)
	*	�� �Ǽ��� : float(4), double(8)
	*/
	int		������	= 0;
// (�ڷ���) (������) (������)
	// �ڷ��� => ��������� ���¿� ũ�⸦ ���ϴ� �κ�.
	// ������ => ��������� ���ٸ�Ī�� ���ϴ� �κ�.

	/**
	*	�� �ڷ����� ũ�� ��
	*	1byte = 8bit
	*	8bit�� ǥ���� �� �ִ� ����� �� : 2^8 (256 ������)
	*	8bit�� ���� ������ ǥ���Ѵٸ� : 0 ~ 255 ���� ǥ�� ����
	* 
	*	�� unsigned �� �տ� ���̸� ����� �������� ǥ���Ѵ�.
	*/
	int i = 0;
	unsigned char c = 0;

	/**
	*	�� ��ǻ�Ϳ����� ��� 1 �� 
	*	��ǻ���� ��� 1���� bit�� 0�� 1�� ���°� ����.
	*	���� bit ����� �������� ����Ѵ�.
	*	�������� ��� 0�� 1�� ���ϸ� 1�� �Ǹ� 1�� 1�� ���ϸ� �¼��� �߻��Ͽ� ���� bit�� 0���� ���� �� ���� bit�� 1�� �����Ѵ�.
	*/

	c = 0;		// c = 0
	c = 255;	// c = 255
	c = 256;	// c = 0
	c = -1;		// c = 255

	/**
	*	�� ��ǻ�Ϳ����� ��� 2 �� 
	*	��ǻ�ʹ� ���ѵ� �������(bit) ������ ������ ����� ǥ���ؾ� �Ѵ�.
	*	���� �̸� ǥ���ϱ� ���� ������� MSB(Most Significant Bit)�� ä��, �ֻ��� ��Ʈ�� ��ȣ�� ����ϰ� �Ǿ���.
	*	char �ڷ����� ��� 8bit�� �ֻ����� 1bit�� ��ȣ ��Ʈ�� ���,
	*	�� 0�� ��� ���, 1�� ��� ������ ǥ���Ѵ�.
	*	�� ��ǻ���� ������ �¼��� ���Ե� �������� ���� �����̴�. (���� ������ ���� ����)
	*	�� ���� ������ �ϱ� ���ؼ��� �¼��� �������� ������ �̿��ؼ� ������ �ϴµ�, ������ ǥ������ ������� 2�� �������� ����� ������� ��Ÿ����.
	*	�� ���� ��� 1 + (-1) �� �ϸ� 0�� �Ǵ� bit ������ ������ �Ѵ�.
	*	��	 1	: 0 000 0001
	*		 0	: 0 000 0000
	*		-1	: 1 111 1111
	*	��	1 + (-1) �� �ϰ� �Ǹ� �������� �������� ���� 10 000 0000�� �� ���̰� 8bit�̱� ������ 0 000 0000 �̶�� ����� ������ �ȴ�.
	* 
	*	�� signed �� ������ ��� �� �� ǥ���Ѵ�. (default�� �Է����� �ʾ��� �� �⺻������ signed�� ����Ѵ�.)
	*/
	signed char c1 = 0;
	c1 = -1;	// c1 = -1
	c1 = 255;	// c1 = -1

	/**
	*	�� ������ ������ �ڷ����� ũ�� �� 
	*	8bit�� ������ ǥ���Ѵٸ� : -128 ~ 127 ���� ǥ�� ����
	*/

	/**
	*	�� �� ��ǻ�Ϳ����� �޸� �ؼ� �� ��
	*	�޸𸮿� ���� ���� ���־ �ڷ����� ���� ��ǻ�ʹ� �ؼ��� �޸��� �� �ִ�.
	*	���� ����, unsigned char ���� 1111 1111 �� 255�� �ؼ��ȴ�.
	*	������ �Ϲ� signed char ������ 1111 1111 �� -1�� �ؼ��ȴ�.
	*/

	/**
	*	�� �Ǽ��� �ڷ��� ��
	*	��ǻ�ʹ� ������ �޸𸮿��� �Ǽ��� ǥ���ϱ� ���� �ε��Ҽ����� ����Ѵ�. (�ܼ��� 0 ~ 1 ������ �Ǽ� ���� �ϴ��� ���Ѵ�� ������� �� �ֱ� �����̴�.)
	*	�� �Ǽ��� �޸𸮿��� ��ȣ��Ʈ, ����ǥ����, ����ǥ���η� ������ ����Ѵ�.
	*	�� ����ǥ���δ� (2^-����)�� �Ҽ����� ��Ÿ����.
	*	�� ����ǥ������ �޸𸮴� ���ѵǾ��ְ� (2^-����)�� ����ϱ� ������ �Ǽ��� �����ϰ� ǥ������ ���� �� �ִ�.
	*		�� �Ǽ� ǥ���� �־� ���Ǻδ� ��ȣ(==) ����� �����Ѵ�.
	*	�� �� ������ �Ǽ� ǥ���� �ϱ� ���ؼ��� ����ǥ���ΰ� ū double�� ���е��� �� ����. (������ ������ ��Ȯ�ϴٰ� �� �� ����)
	*/
	float f1 = -118.625;	// 1 10000101 11011010100000000000000

	/**
	*	�� ������ �Ǽ��� ���� ��
	*	��ǻ�ʹ� ������ �޸𸮿��� �Ǽ��� ǥ���ϱ� ������
	*	�� ������ �Ǽ��� ������ �߻��ϴ� ��� �� �� �ϳ��� �ڷ������� ��ȯ��Ű�� ������ ���ܳ���.
	*	�� ������ �Ǽ��� ������ ȥ��� ��� ���������� ����ȯ�� �����ϴ� ���� ��õ�Ѵ�.
	*/
	float f2 = 10.123f + (float)20;

	/**
	*	�� �⺻�� ��
	*	�� ��ǻ�Ϳ��� ����� �������� ��, �ڷ����� ���õ��� ���� ����鿡�� �⺻���� ����ȴ�.
	*	�� ������ �⺻���� int , �Ǽ��� �⺻���� double �̴�.
	*	�� Long�� ����� �����ϱ� ���ؼ��� ���� �ڿ� L �Ǵ� l�� �ٿ���� �Ѵ�.
	*	�� Float�� ����� �����ϱ� ���ؼ��� �Ǽ� �ڿ� F �Ǵ� f�� �ٿ���� �Ѵ�.
	*/
	long L = 10L;
	float f3 = 3.F;

	return 0;
}