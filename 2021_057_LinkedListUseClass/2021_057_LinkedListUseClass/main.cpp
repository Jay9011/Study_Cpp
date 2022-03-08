#include <iostream>
#include "CList.h"

int main()
{
	CList<int> iList;
	CList<float> fList;

	for (int i = 0; i < 4; i++)
	{
		iList.PushBack(i);
	}

	return 0;
}