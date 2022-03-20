#pragma once
#include <assert.h>

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
*	class MyList도 클래스 템플릿으로 정의해야 한다.
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
inline void MyList<T>::PushFront(const T& _data)
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

/*
*	Iterator 사용
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

	// 1. 새로운 데이터 노드를 생성
	tNode<T>* pNode = new tNode<T>(_data, nullptr, nullptr);

	// iterator가 가리키는 노드가 헤드노드인 경우
	if (_iter.m_pNode == pHeadNode)
	{
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;

		pHeadNode = pNode;
	}
	else
	{
		// iterator가 가리키고 있는 노드의 이전으로 가서 다음 노드 주소를 새로 생성한 노드로 지정하고
		// 새로 생성한 노드 이전을 iterator가 가리키고 있던 노드의 이전 주소를 그대로 받는다.
		_iter.m_pNode->pPrev->pNext = pNode;
		pNode->pPrev = _iter.m_pNode->pPrev;

		// iterator가 가리키고 있던 노드는 이전 노드 주소를 새로 생성한 노드로 지정하고 
		// 새로 생성한 노드 다음을 iterator가 가리키고 있는 노드를 가리키게 한다.
		_iter.m_pNode->pPrev = pNode;
		pNode->pNext = _iter.m_pNode;
	}

	// 증가된 노드만큼 Count 증가
	++iCount;

	return iterator();
}