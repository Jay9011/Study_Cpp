int S03_Condition()
{
	/**
	*	▒ 구문 ▒
	*	① if ~ else if ~ else : if / else if 조건을 확인하고 true가 걸리면 해당 if문을 실행하고 나온다. 만약, true인 조건이 없다면 마지막 else문을 실행한다.
	*		※ [else if]가 없다면 모든 [if]문을 검사하기 때문에 조건 중 하나만 실행하고자 한다면 [else if]를 쓰는게 좋다.
	* 
	*	② switch ~ case ~ default : switch 조건문에 들어오는 값을 가지고 각각의 case에 해당하는 값을 비교하여 같은 값이 존재한다면 해당 case를 실행한다.
	*		※ case 실행 후 break로 빠져나오지 않으면 다음 case도 실행하게 된다. (if문의 경우 brackets로 구역이 분할되어 있지만 case는 구역이 나눠져있지 않기 때문에)
	*		※ if ~ else if ~ else 문과 비슷하지만, case에는 기본 리터럴이 정해진 값만 들어갈 수 있기 때문에, 복합 조건을 사용하기는 어렵다.
	* 
	*	③ 조건:참?거짓 (삼항연산자) : 조건의 결과에 따라 참이나 거짓 구문을 실행하는 연산자.
	*/

	// switch문과 if문
	int iTest = 20;
	switch (iTest)
	{
	case 10:
	case 20:
	case 30:
		break;
	default:
		break;
	}

	if (iTest == 10 || iTest == 20 || iTest == 30)
	{

	}
	else 
	{

	}

	// 삼항 연산자와 if문
	iTest == 20 ? iTest = 100 : iTest = 200;

	if (iTest == 20)
	{
		iTest = 100;
	}
	else
	{
		iTest = 200;
	}
}