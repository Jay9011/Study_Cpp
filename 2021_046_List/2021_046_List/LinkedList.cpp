#include <iostream>
#include "LinkedList.h"

void InitList(tLinkedList* _pList)
{
	_pList->pHeadNode = nullptr;
	_pList->iCount = 0;
}

void PushBack(tLinkedList* _pList, int _iData)
{
	// �����͸� ������ ��� ����
	tNode* pNode = (tNode*)malloc(sizeof(tNode));
	pNode->iData = _iData;
	pNode->pNextNode = nullptr;

	// �߰��� �����Ͱ� ó������ �ƴ���
	if (0 == _pList->iCount)
	{
		_pList->pHeadNode = pNode;
	}
	else
	{
		// ���� ���� ������ ��带 ã�Ƽ� �ش� ����� pNextNode�� ���� ����� �ּҸ� �߰��ؾ� �Ѵ�.
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

// ��� �Լ� �������� �� �� ������, ���ÿ����÷ο찡 �Ͼ ���輺�� ũ��.
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
