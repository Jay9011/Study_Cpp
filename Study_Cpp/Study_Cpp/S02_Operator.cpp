int S02_Operator() 
{
	/**
	*	▒ 연산자 ▒
	* 
	*	대입 연산자
	*	① =
	*	※ 컴퓨터는 연산의 결과를 레지스터의 누산기(AC)에 저장하기 때문에 메모리에 실제적으로 반영하기 위해서는 대입 연산자를 사용해줘야 한다.
	* 
	*	산술 연산자
	*	① +, -, *, /, %(modular)
	* 
	*	산술 대입 연산자
	*	① +=, -=
	* 
	*	증감 연산자
	*	① ++(전위), --(전위)	: 모든 연산자보다 우선순위가 높다. (※가능하면 전위 연산자를 쓰는 습관을 들이자.)
	*	② (후위)++, (후위)--	: 모든 연산자보다 연산자 우선순위가 낮다. (대입연산자보다 낮기 때문에 대입 연산자 처리 후 후위 연산자가 발생한다.)
	*	※ 증감 연산자는 일반적으로 산술적으로 상수를 증감시킨다는 것이 아니라 개념에 대한 증가와 감소를 나타낸다.
	* 
	*	비교 연산자
	*	① ==, !=	: 같거나 다르면 true
	*	② <, >, <=, >=	: 크기를 비교해서 맞으면 true
	* 
	*	논리 연산자
	*	① !(논리 반전), &&(논리 곱), ||(논리 합)
	* 
	*	※ 참(true), 거짓(false)
	*		참(true)		: 0이 아닌 모든 상수. (기본 1)
	*		거짓(false)	: 0
	* 
	*	삼항 연산자
	*	① (조건문):(true일)?(false)	: 조건문이 true 일 때 true 부분을, false 일 때 false 부분을 실행한다.
	* 
	*/
	int data = 10 + 20;
	data + 30; // 누산기(AC)에 저장되고 메모리에 쓰기 동작을 하기 전 상태

	// data = 10. % 3.;
	// data = 10 % 3.;	// 실수에는 나머지에 대한 개념이 모호하기 때문에 modular(%) 연산이 불가능하다.

	double data2 = 0.25;
	data2++;

	int a = 10;
	a = data++;	// a = 30, data = 31 (대입 이후 후위 증감 연산자가 발생했다.)
	


	return 0;
}