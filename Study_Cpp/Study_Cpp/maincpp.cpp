#include "stdio.h"
#include "S07_Implementation.h"

extern int S01_DataType();
extern int S02_Operator();
extern int S03_Condition();
extern int S04_BitOperator();
extern int S05_Variable();
extern int S06_RecursiveFunction();

// �ܺ� ���� �����
extern int _iExternV;

int main()
{
	S06_RecursiveFunction();

	int iNum1 = add(1, 2);

	printf("_iExternV �� : %d", _iExternV);
}