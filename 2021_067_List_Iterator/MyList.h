#pragma once
#include <assert.h>

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
*	class MyList�� Ŭ���� ���ø����� �����ؾ� �Ѵ�.
*/
template<typename T>
class MyList
{
public:
	MyList();
	~MyList();

private:
	tNode<T>*	pHeadNode;
	tNode<T>*	pTailNode;
	int			iCount;

public:
	void PushBack(const T& _data);
	void PushFront(const T& _data);
	int size() { return iCount; }

public:
	class iterator;
	iterator begin();
	iterator end();
	iterator insert(const iterator& _iter, const T& _data);

public:
	class iterator
	{
	private:
		MyList<T>*	m_pList;
		tNode<T>*	m_pNode;
		bool		m_bValid;

	public:
		iterator()
			: m_pList(nullptr)
			, m_pNode(nullptr)
			, m_bValid(false)
		{}

		iterator(MyList<T>* _pList, tNode<T>* _pNode)
			: m_pList(_pList)
			, m_pNode(_pNode)
			, m_bValid(false)
		{
			if (nullptr != _pList && nullptr != _pNode)
			{
				m_bValid = true;
			}
		}

		~iterator() 
		{}

	public:
		T& operator* () 
		{
			return m_pNode->data;
		}

		bool operator == (const iterator& _otherIter)
		{
			if (m_pList == _otherIter.m_pList && m_pNode == _otherIter.m_pNode)
			{
				return true;
			}
			return false;
		}

		bool operator != (const iterator& _otherIter)
		{
			return !(*this == _otherIter);
		}

		iterator& operator ++ ()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pNext;

			return *this;
		}

		iterator& operator ++ (int)
		{
			iterator copyIter(*this);

			++(*this);

			return copyIter;
		}

		iterator& operator -- ()
		{
			if (nullptr == m_pNode || !m_bValid)
			{
				assert(nullptr);
			}

			m_pNode = m_pNode->pPrev;

			return *this;
		}

		iterator& operator -- (int)
		{
			iterator copyIter(*this);

			--(*this);

			return copyIter;
		}

		friend class MyList;
		// end iterator Class
	};
	// end MyList Class
};

template<typename T>
inline MyList<T>::MyList()
	: pHeadNode(nullptr)
	, pTailNode(nullptr)
	, iCount(0)
{
}

template<typename T>
inline MyList<T>::~MyList()
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
inline void MyList<T>::PushBack(const T& _data)
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
inline void MyList<T>::PushFront(const T& _data)
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

/*
*	Iterator ���
*/
template<typename T>
inline typename MyList<T>::iterator MyList<T>::begin()
{
	return iterator(this, pHeadNode);
}

template<typename T>
inline typename MyList<T>::iterator MyList<T>::end()
{
	return iterator(this, nullptr);
}

template<typename T>
inline typename MyList<T>::iterator MyList<T>::insert(const iterator& _iter, const T& _data)
{
	if (this->end() == _iter)
	{
		assert(nullptr);
	}

	// 1. ���ο� ������ ��带 ����
	tNode<T>* pNode = new tNode<T>(_data, nullptr, nullptr);

	// iterator�� ����Ű�� ��尡 ������� ���
	if (_iter.m_pNode == pHeadNode)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		pHeadNode = pNode;
	}
	else
	{
		// iterator�� ����Ű�� �ִ� ����� �������� ���� ���� ��� �ּҸ� ���� ������ ���� �����ϰ�
		// ���� ������ ��� ������ iterator�� ����Ű�� �ִ� ����� ���� �ּҸ� �״�� �޴´�.
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator�� ����Ű�� �ִ� ���� ���� ��� �ּҸ� ���� ������ ���� �����ϰ� 
		// ���� ������ ��� ������ iterator�� ����Ű�� �ִ� ��带 ����Ű�� �Ѵ�.
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	// ������ ��常ŭ Count ����
	++iCount;

	return iterator();
}