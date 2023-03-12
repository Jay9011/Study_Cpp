#include "stdio.h"
#include "S07_Implementation.h"
#include "Swap.h"

extern int S01_DataType();
extern int S02_Operator();
extern int S03_Condition();
extern int S04_BitOperator();
extern int S05_Variable();
extern int S06_RecursiveFunction();

// 외부 변수 선언부
extern int _iExternV;

int main()
{
	int a = 1, b = 2;
	Swap(&a, &b);
	Swap(a, b);
}