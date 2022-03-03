#pragma once

/*
*	����Ʈ�� ��� ( ��� )
*/
typedef struct _tagNode
{
	int					iData;		// �����ϴ� ������ Ÿ���� ���� int �� �����ϱ�� �Ѵ�.
	struct _tagNode*	pNextNode;	// ���� ����� �ּҸ� �˾ƾ� ���� ���� �̵��� �� �ִ�.
} tNode;

/*
*	������ ����Ʈ
*/
typedef struct _tagList
{
	tNode*	pHeadNode;
	int		iCount;		// ���� ������ �ִ� �ڷ��� ����
} tLinkedList;

// ������ ����Ʈ �ʱ�ȭ
void InitList(tLinkedList* _pList);
// ������ ����Ʈ ������ �߰�
void PushBack(tLinkedList* _pList, int _iData);
void PushFront(tLinkedList* _pList, int _iData);
// ������ ����Ʈ �޸� ����
void ReleaseList(tLinkedList* _pList);