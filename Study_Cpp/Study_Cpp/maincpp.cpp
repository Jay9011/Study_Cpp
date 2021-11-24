/**
*	▒ 전처리기 ▒
*	컴파일 과정에서 컴파일러가 가장 먼저 처리하는 과정.
* 
*	#define	: 지정한 구문을 특정 숫자로 치환
*		① 컴파일 과정에서 해당 구문을 해당 숫자로 바꿔주고 다음 컴파일을 진행한다.
*		② 가독성이 좋아진다.
*		③ 유지보수가 좋다.
*/
#define HUNGRY 1;

extern int S01_DataType();
extern int S02_Operator();
extern int S03_Condition();

int main()
{
	S02_Operator();
}