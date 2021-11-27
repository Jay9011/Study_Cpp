#pragma once
/**
*	▒ 분할 구현 ▒
*	전체적인 빌드 과정은
*	[ 전처리기 - 컴파일러 - 어셈블러 - 링크 ] 로 나뉘는데,
*	이때, 링크 과정에서 선언부과 구현부를 연결시켜주기 때문에 이를 이용해 선언부와 구현부를 나눠서 구현한 것을 분할 구현이라고 한다.
* 
*	① header(선언부)와 cpp(구현부)를 나눠서 구현하여 링크(Link) 단계에서 코드들을 연결시킨다.
*	② 
*/

int add(int num1, int num2);
int sub(int num1, int num2);
void printNumbers(int num1, int num2);