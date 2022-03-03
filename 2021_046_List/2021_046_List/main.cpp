#include <iostream>
#include <time.h>

#include "LinkedList.h"

int main()
{
	tLinkedList list = {};
	InitList(&list);

	PushFront(&list, 100);
	PushFront(&list, 200);
	PushFront(&list, 300);

	tNode* pNode = list.pHeadNode;
	for (int i = 0; i < list.iCount; i++)
	{
		printf("%d\n", pNode->iData);
		pNode = pNode->pNextNode;
	}

	ReleaseList(&list);

	return 0;
}