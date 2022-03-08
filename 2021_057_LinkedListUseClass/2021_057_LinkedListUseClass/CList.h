#pragma once

/*
*	클래스 템플릿 (구조체 템플릿)을 정의한 경우, 사용하는 포인터에서 템플릿의 타입을 정해줘야 한다.
*/
template<typename T>
struct tNode
{
	T			data;
	tNode*		pPrev;
	tNode<T>*	pNext;	// 본인 선언 내부이기 때문에 <T>로 템플릿을 요청하지 않아도 컴파일러가 알아서 처리해준다.
						// 하지만, 외부에서는 알 방법이 없기 때문에 <T>로 템플릿 인수를 명시해줘야 한다.

	tNode()
		: data()
		, pPrev(nullptr)
		, pNext(nullptr)
	{
	}
	tNode(const T& _data, tNode<T>* _pPrev, tNode<T>* _pNext)
		: data(_data)
		, pPrev(_pPrev)
		, pNext(_pNext)
	{
	}
};

/*
*	하지만, 템플릿의 목적은 다양한 자료형으로 리스트를 만들기 위함이므로
*	class CList도 클래스 템플릿으로 정의해야 한다.
*/
template<typename T>
class CList
{
public:
	CList();
	~CList();

private:
	tNode<T>*	pHeadNode;
	tNode<T>*	pTailNode;
	int			iCount;

public:
	void PushBack(const T& _data);
	void PushFront(const T& _data);
};

template<typename T>
inline CList<T>::CList()
	: pHeadNode(nullptr)
	, pTailNode(nullptr)
	, iCount(0)
{
}

template<typename T>
inline CList<T>::~CList()
{
	tNode<T>* pDeleteNode = this->pHeadNode;

	while (pDeleteNode)
	{
		tNode<T>* pNext = pDeleteNode->pNext;
		delete(pDeleteNode);
		pDeleteNode = pNext;
	}
}

template<typename T>
inline void CList<T>::PushBack(const T& _data)
{
	// 입력된 데이터를 저장할 노드를 동적할당 한다
	tNode<T>* pNewNode = new tNode<T>(_data, nullptr, nullptr);

	if (nullptr == this->pHeadNode)
	{
		// 처음 입력된 데이터라면
		this->pHeadNode = pNewNode;
		this->pTailNode = pNewNode;
	}
	else
	{
		// 데이터가 1개 이상이라면
		// 현재 가장 마지막 데이터(tail) 노드가 새로 생성된 노드와 서로 가리키게 한다.
		this->pTailNode->pNext = pNewNode;
		pNewNode->pPrev = this->pTailNode;

		// List의 마지막 노드를 가리키는 주소를, 새로 만들어진 노드를 가리키게 한다.
		this->pTailNode = pNewNode;
	}

	// 데이터 개수 증가
	++this->iCount;
}

template<typename T>
inline void CList<T>::PushFront(const T& _data)
{
	// 새로 생성된 노드의 다음 주소를 현재 헤드노드의 주소값으로 채운다
	tNode<T>* pNewNode = new tNode<T>(_data, nullptr, this->pHeadNode);

	// 현재 헤드노드의 이전 주소값을 새로 생성된 노드의 주소로 채움
	this->pHeadNode->pPrev = pNewNode;

	// 리스트가 새로 생성된 노드의 주소를 새로운 헤드 주소로 갱신한다.
	this->pHeadNode = pNewNode;

	// 데이터 개수 증가
	++this->iCount;
}
