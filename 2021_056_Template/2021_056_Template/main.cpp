/*
*	Template ( 템플릿 )
* 
*	함수나 클래스를 만들어 줄 템플릿(틀)을 만들어 주고,
*	컴파일러가 호출되는 템플릿을 확인하고 해당하는 함수나 클래스를 만들어 준다.
*	(① 코드에 맞는 오버로딩 함수나 클래스를 생성해준다.)
*	(② 템플릿 함수나 템플릿 클래스가 호출되지 않는다면 만들지 않는다.) 
*	(③ 만약 미리 만들어줘야 한다면 모든 가능성있는 형식으로 만들어져야 하는데, 그것은 매우 비현실적이다.)
* 
*	함수 템플릿 정의
*		template<typename 치환문자>
*		치환문자 함수명(치환문자 변수명)
*		{
*		}
*
*	클래스 템플릿 정의
*		template<typename 치환문자>
*		class 클래스명
*		{
*			멤버에서 치환문자 사용
*		}
*
*	※ 클래스 템플릿 구현시 주의사항 ※
* 
*	클래스 템플릿을 지정하면,
*	main쪽에서 클래스 템플릿을 호출할 때, class가 선언되어 있는 헤더 파일의 치환문자를 변경시킨다.
*	하지만, cpp 파일에 있는 구현부분은 처음 선언부분을 생성할 때 호출되지 않기 때문에 치환문자가 변경되지 않은 상태로 남아있게 된다.
*
*	따라서! 클래스 템플릿을 구현을 하기 위해서는 class 선언부분이 존재하는 헤더에서 한 번에 구현해야 한다.
*/


// 함수 템플릿
template<typename T>
T Add(T a, T b)
{
	return a + b;
}


int main()
{
	// 함수 템플릿 호출
	int i = Add<int>(10, 20);
}