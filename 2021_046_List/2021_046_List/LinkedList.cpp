#include <iostream>
#include "LinkedList.h"

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// 데이터를 저장할 노드 생성
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// 추가한 데이터가 처음인지 아닌지
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// 현재 가장 마지막 노드를 찾아서 해당 노드의 pNextNode에 현재 노드의 주소를 추가해야 한다.
		tNode* pCurFinNode = _pList->pHeadNode;
		while (pCurFinNode->pNextNode)
		{
			pCurFinNode = pCurFinNode->pNextNode;
		}
		pCurFinNode->pNextNode = pNode;
	}

	++_pList->iCount;
}

void PushFront(tLinkedList* _pList, int _iData)
{
}

// 재귀 함수 버전으로 할 수 있으나, 스택오버플로우가 일어날 위험성이 크다.
void Release(tNode* _pNode)
{
	if (nullptr == _pNode)
		return;

	Release(_pNode->pNextNode);
	free(_pNode);
}

void ReleaseList(tLinkedList* _pList)
{
	//Release(_pList->pHeadNode);

	tNode* pDeleteNode = _pList->pHeadNode;
	while (pDeleteNode)
	{
		tNode* pNext = pDeleteNode->pNextNode;
		free(pDeleteNode);
		pDeleteNode = pNext;
	}
}
