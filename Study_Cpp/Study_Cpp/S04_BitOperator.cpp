/**
*	▒ 전처리기 ▒
*	컴파일 과정에서 컴파일러가 가장 먼저 처리하는 과정.
*
*	#define	: 지정한 단어를 해당 구문으로 치환
*		① 컴파일 과정에서 해당 단어를 해당 구문으로 바꿔주고 다음 컴파일을 진행한다.
*		② 가독성이 좋아진다.
*		③ 유지보수가 좋다.
*		※ define의 경우 뒤의 구문을 치환하기 때문에 ;를 붙이면 사용하기 어려울 수 있다.
* 
*	▒ bit 연산을 사용하기 위한 상태값을 만들 때에는 16진수로 만드는 것이 편하다. ▒
*	16진수로 만들게 되면 4bit씩 띄워서 계산하기 편하다. (1, 2, 4, 8 반복)
*/
#define HUNGRY	0x001		// #define HUNGRY	1
#define THIRSTY	0x002		// #define THIRSTY	2
#define TIRED	0x004		// #define TIRED	4
#define HEAT	0x008		// #define HEAT		8

#define COLD	0x010		// #define COLD		16
#define STATE1	0x020		// #define STATE1	32
#define STATE2	0x040		// #define STATE2	64
#define STATE3	0x080		// #define STATE3	128

#define STATE4	0x100		// #define STATE4	256
#define STATE5	0x200		// #define STATE5	512
#define STATE6	0x400		// #define STATE6	1024
#define STATE6	0x800		// #define STATE7	2048


int S04_BitOperator()
{
	/**
	*	▤ 비트 연산자를 사용한 상태이상 표현 ▤
	*	비트 연산자
	*	① <<, >> (shift)
	*	② <<=, >>= (비트 대입 연산자)
	*	③ ~(비트 반전), &(비트 곱), |(비트 합), ^(XOR, 배타적 논리합)
	*		ⅰ) & (AND)	: 두 개의 비트 모두 true면 true를 리턴한다.
	*					  두 비트 값을 곱해서 나온 결과와 같다고 해서 비트 곱이라고도 한다.
	*		ⅱ) | (OR)	: 두 개의 비트 중 하나라도 true면 true를 리턴한다.
	*					  두 개의 비트를 더해서 1 이상이면 1로 출력하기 때문에 비트 합이라고도 한다.
	*		ⅱ) ^ (XOR)	: 두 개의 비트가 서로 달라야 true를 리턴한다.
	*					  두 개의 비트가 서로 달라야 true를 리턴하기 때문에 베타적 비트 합이라고 한다. (쉽게 생각하면 승수를 버린 결과라고 볼 수 있다)
	*/
	unsigned int iStatus = 0;	// 아무런 상태이상이 없는 상태
	iStatus |= HUNGRY;	// iStatus의 결과에 해당 비트의 | (비트합)을 사용하면 해당 비트만 상태이상을 부여할 수 있다.
	iStatus |= COLD;	// iStatus의 결과에 서로 다른 상태를 비트합 했기 때문에 두 개의 상태이상이 부여 된 상황이다.

	if (iStatus & HUNGRY)
	{
		// 배고픈 상태라면 들어온다.
	}

	// ※ 상태이상 해제 (특정 자리의 상태이상 해제)
	iStatus &= ~COLD;	// COLD 상태를 해제하기 위해 비트 반전을 하면 해당 상태 자리가 false가 되기 때문에
						// 비트곱을 수행하면 원래 상태가 true인 상태는 true로, false면 false로 놔두고
						// 해당 상태이상 자리만 false이기 때문에 무조건 false로 리턴하게 된다.

	return 0;
}