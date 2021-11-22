int main() 
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

	return 0;
}