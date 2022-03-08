#pragma once

/*
*	Ŭ���� ���ø� (����ü ���ø�)�� ������ ���, ����ϴ� �����Ϳ��� ���ø��� Ÿ���� ������� �Ѵ�.
*/
template<typename T>
struct tNode
{
	T			data;
	tNode*		pPrev;
	tNode<T>*	pNext;	// ���� ���� �����̱� ������ <T>�� ���ø��� ��û���� �ʾƵ� �����Ϸ��� �˾Ƽ� ó�����ش�.
						// ������, �ܺο����� �� ����� ���� ������ <T>�� ���ø� �μ��� �������� �Ѵ�.

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
*	������, ���ø��� ������ �پ��� �ڷ������� ����Ʈ�� ����� �����̹Ƿ�
*	class CList�� Ŭ���� ���ø����� �����ؾ� �Ѵ�.
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
	// �Էµ� �����͸� ������ ��带 �����Ҵ� �Ѵ�
	tNode<T>* pNewNode = new tNode<T>(_data, nullptr, nullptr);

	if (nullptr == this->pHeadNode)
	{
		// ó�� �Էµ� �����Ͷ��
		this->pHeadNode = pNewNode;
		this->pTailNode = pNewNode;
	}
	else
	{
		// �����Ͱ� 1�� �̻��̶��
		// ���� ���� ������ ������(tail) ��尡 ���� ������ ���� ���� ����Ű�� �Ѵ�.
		this->pTailNode->pNext = pNewNode;
		pNewNode->pPrev = this->pTailNode;

		// List�� ������ ��带 ����Ű�� �ּҸ�, ���� ������� ��带 ����Ű�� �Ѵ�.
		this->pTailNode = pNewNode;
	}

	// ������ ���� ����
	++this->iCount;
}

template<typename T>
inline void CList<T>::PushFront(const T& _data)
{
	// ���� ������ ����� ���� �ּҸ� ���� ������� �ּҰ����� ä���
	tNode<T>* pNewNode = new tNode<T>(_data, nullptr, this->pHeadNode);

	// ���� ������� ���� �ּҰ��� ���� ������ ����� �ּҷ� ä��
	this->pHeadNode->pPrev = pNewNode;

	// ����Ʈ�� ���� ������ ����� �ּҸ� ���ο� ��� �ּҷ� �����Ѵ�.
	this->pHeadNode = pNewNode;

	// ������ ���� ����
	++this->iCount;
}
