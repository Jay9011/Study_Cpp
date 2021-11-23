//int main() 
int S01_DataType()
{
	/**
	*	▒ 자료형 (DataType) ▒
	*	(크기 단위 byte) : 1byte == 8bit
	*	① 정수형 : char(1), short(2), int(4), long(4), long long(8)
	*	② 실수형 : float(4), double(8)
	*/
	int		변수명	= 0;
// (자료형) (변수명) (연산자)
	// 자료형 => 저장공간의 형태와 크기를 정하는 부분.
	// 변수명 => 저장공간의 접근명칭을 정하는 부분.

	/**
	*	▒ 자료형의 크기 ▒
	*	1byte = 8bit
	*	8bit에 표현할 수 있는 경우의 수 : 2^8 (256 가짓수)
	*	8bit를 양의 정수로 표현한다면 : 0 ~ 255 까지 표현 가능
	* 
	*	□ unsigned 를 앞에 붙이면 양수의 범위만을 표현한다.
	*/
	int i = 0;
	unsigned char c = 0;

	/**
	*	▒ 컴퓨터에서의 계산 1 ▒ 
	*	컴퓨터의 경우 1개의 bit에 0과 1의 상태가 들어간다.
	*	따라서 bit 연산시 이진법을 사용한다.
	*	정수형의 경우 0에 1을 더하면 1이 되며 1에 1을 더하면 승수가 발생하여 현재 bit를 0으로 만든 뒤 이후 bit에 1을 전달한다.
	*/

	c = 0;		// c = 0
	c = 255;	// c = 255
	c = 256;	// c = 0
	c = -1;		// c = 255

	/**
	*	▒ 컴퓨터에서의 계산 2 ▒ 
	*	컴퓨터는 제한된 저장공간(bit) 내에서 음수와 양수를 표현해야 한다.
	*	따라서 이를 표현하기 위한 방법으로 MSB(Most Significant Bit)를 채용, 최상위 비트를 부호로 사용하게 되었다.
	*	char 자료형의 경우 8bit중 최상위의 1bit를 부호 비트로 사용,
	*	① 0의 경우 양수, 1의 경우 음수로 표현한다.
	*	② 컴퓨터의 연산은 승수가 포함된 이진수의 덧셈 연산이다. (뺄셈 연산이 따로 없다)
	*	③ 따라서 뺄셈을 하기 위해서는 승수와 이진수의 덧셈을 이용해서 만들어야 하는데, 음수의 표현법은 양수에서 2의 보수법을 사용한 방법으로 나타낸다.
	*	④ 예를 들어 1 + (-1) 을 하면 0이 되는 bit 구조를 만들어야 한다.
	*	⑤	 1	: 0 000 0001
	*		 0	: 0 000 0000
	*		-1	: 1 111 1111
	*	⑥	1 + (-1) 을 하게 되면 이진수의 덧셈법에 따라 10 000 0000이 될 것이고 8bit이기 때문에 0 000 0000 이라는 결과가 나오게 된다.
	* 
	*	□ signed 는 음수와 양수 둘 다 표현한다. (default로 입력하지 않았을 때 기본적으로 signed를 사용한다.)
	*/
	signed char c1 = 0;
	c1 = -1;	// c1 = -1
	c1 = 255;	// c1 = -1

	/**
	*	▒ 음수를 포함한 자료형의 크기 ▒ 
	*	8bit를 정수로 표현한다면 : -128 ~ 127 까지 표현 가능
	*/

	/**
	*	▒ ※ 컴퓨터에서의 메모리 해석 ※ ▒
	*	메모리에 같은 값이 들어가있어도 자료형에 따라 컴퓨터는 해석을 달리할 수 있다.
	*	위의 예로, unsigned char 에서 1111 1111 은 255로 해석된다.
	*	하지만 일반 signed char 에서는 1111 1111 은 -1로 해석된다.
	*/

	/**
	*	▒ 실수형 자료형 ▒
	*	컴퓨터는 한정된 메모리에서 실수를 표현하기 위해 부동소수점을 사용한다. (단순히 0 ~ 1 사이의 실수 값만 하더라도 무한대로 만들어질 수 있기 때문이다.)
	*	① 실수는 메모리에서 부호비트, 지수표현부, 가수표현부로 나눠서 사용한다.
	*	② 가수표현부는 (2^-지수)로 소숫점을 나타낸다.
	*	③ 가수표현부의 메모리는 제한되어있고 (2^-지수)로 계산하기 때문에 실수는 정밀하게 표현되지 않을 수 있다.
	*		※ 실수 표현에 있어 조건부는 등호(==) 사용을 지양한다.
	*	④ 더 정밀한 실수 표현을 하기 위해서는 가수표현부가 큰 double이 정밀도가 더 높다. (하지만 여전히 정확하다고 할 수 없다)
	*/
	float f1 = -118.625;	// 1 10000101 11011010100000000000000

	/**
	*	▒ 정수와 실수의 연산 ▒
	*	컴퓨터는 한정된 메모리에서 실수를 표현하기 때문에
	*	① 정수와 실수의 연산이 발생하는 경우 둘 중 하나의 자료형으로 변환시키는 과정이 생겨난다.
	*	② 정수와 실수의 연산이 혼용될 경우 명시적으로 형변환을 지정하는 것을 추천한다.
	*/
	float f2 = 10.123f + (float)20;

	/**
	*	▒ 기본형 ▒
	*	① 컴퓨터에는 상수를 컴파일할 때, 자료형이 명시되지 않은 상수들에는 기본형이 적용된다.
	*	② 정수형 기본형은 int , 실수형 기본형은 double 이다.
	*	④ Long형 상수를 지정하기 위해서는 정수 뒤에 L 또는 l을 붙여줘야 한다.
	*	⑤ Float형 상수를 지정하기 위해서는 실수 뒤에 F 또는 f를 붙여줘야 한다.
	*/
	long L = 10L;
	float f3 = 3.F;

	return 0;
}