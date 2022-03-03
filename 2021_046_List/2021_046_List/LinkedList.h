#pragma once

/*
*	리스트의 요소 ( 노드 )
*/
typedef struct _tagNode
{
	int					iData;		// 저장하는 데이터 타입은 현재 int 만 저장하기로 한다.
	struct _tagNode*	pNextNode;	// 다음 노드의 주소를 알아야 다음 노드로 이동할 수 있다.
} tNode;

/*
*	연결형 리스트
*/
typedef struct _tagList
{
	tNode*	pHeadNode;
	int		iCount;		// 현재 가지고 있는 자료의 개수
} tLinkedList;

// 연결형 리스트 초기화
void InitList(tLinkedList* _pList);
// 연결형 리스트 데이터 추가
void PushBack(tLinkedList* _pList, int _iData);
void PushFront(tLinkedList* _pList, int _iData);
// 연결형 리스트 메모리 해제
void ReleaseList(tLinkedList* _pList);