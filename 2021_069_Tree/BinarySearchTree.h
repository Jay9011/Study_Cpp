#pragma once
#include <assert.h>

enum class NODE_TYPE
{
	PARENT, // 0
	LCHILD, // 1
	RCHILD, // 2
	END		// 3
};

template <typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
};

template <typename T1, typename T2>
Pair<T1, T2> make_bstPair(const T1& _first, const T2& _second)
{
	return Pair<T1, T2> { _first, _second };
}

template <typename T1, typename T2>
struct BSTNode
{
	Pair<T1, T2> pair;
	BSTNode*	 arrNode[(int)NODE_TYPE::END];

	BSTNode()
		: pair()
		, arrNode {}
	{}

	BSTNode(const Pair<T1, T2>& _pair, BSTNode* _pParent, BSTNode* _pLChild, BSTNode* _pRChild)
		: pair(_pair)
		, arrNode{ _pParent, _pLChild, _pRChild }
	{}

	bool IsRoot()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::PARENT])
			return true;
		return false;
	}

	bool IsLeftChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] == this)
			return true;
		return false;
	}

	bool IsRightChild()
	{
		if (arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] == this)
			return true;
		return false;
	}

	bool IsLeaf()
	{
		if (nullptr == arrNode[(int)NODE_TYPE::LCHILD] && nullptr == arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}

	bool IsFull()
	{
		if (arrNode[(int)NODE_TYPE::LCHILD] && arrNode[(int)NODE_TYPE::RCHILD])
			return true;
		return false;
	}
};

template <typename T1, typename T2>
class BST
{
private:
	BSTNode<T1, T2>*	m_pRoot;	// ��Ʈ ��� �ּ�
	int					m_iCount;	// ������ ����

public:
	BST()
		: m_pRoot(nullptr)
		, m_iCount(0)
	{}

private:
	BSTNode<T1, T2>* GetInOrderSuccessor(BSTNode<T1, T2>* _pNode);
	BSTNode<T1, T2>* GetInOrderPredecessor(BSTNode<T1, T2>* _pNode);
	BSTNode<T1, T2>* DeleteNode(BSTNode<T1, T2>* _pTargetNode);

public:
	bool Insert(const Pair<T1, T2>& _pair);

	class iterator;
	iterator begin();
	iterator end();
	iterator find(const T1& _find);
	iterator erase(const iterator& _iter);

	// iterator
	class iterator
	{
	private:
		BST<T1, T2>*		m_pBST;
		BSTNode<T1, T2>*	m_pNode;	// null �� ��� end iterator

	public:
		iterator()
			: m_pBST(nullptr)
			, m_pNode(nullptr)
		{}

		iterator(BST<T1, T2>* _pBST, BSTNode<T1, T2>* _pNode)
			: m_pBST(_pBST)
			, m_pNode(_pNode)
		{}

		bool operator == (const iterator& _other)
		{
			if (m_pBST == _other.m_pBST && m_pNode == _other.m_pNode)
				return true;

			return false;
		}

		bool operator != (const iterator& _other)
		{
			return !(*this == _other);
		}

		const Pair<T1, T2>& operator *()
		{
			// m_pNode nullptr üũ (end iterator ���� �ƴ���)
			assert(m_pNode);
			return m_pNode->pair;
		}

		const Pair<T1, T2>* operator ->()
		{
			// m_pNode nullptr üũ (end iterator ���� �ƴ���)
			assert(m_pNode);
			return &m_pNode->pair;
		}

		iterator& operator ++()
		{
			m_pNode = m_pBST->GetInOrderSuccessor(m_pNode);
			return *this;
		}

		friend class BST<T1, T2>;
		// end class iterator
	};
	// end class BST
};

template<typename T1, typename T2>
inline BSTNode<T1, T2>* BST<T1, T2>::GetInOrderSuccessor(BSTNode<T1, T2>* _pNode)
{
	BSTNode<T1, T2>* pSuccessor = nullptr;

	// 1. ������ �ڽ��� �ִ� ���, ������ �ڽ����� ���� ���� �ڽ��� ���� ������ ������
	if (nullptr != _pNode->arrNode[(int)NODE_TYPE::RCHILD])
	{
		pSuccessor = _pNode->arrNode[(int)NODE_TYPE::RCHILD];

		while (pSuccessor->arrNode[(int)NODE_TYPE::LCHILD])
		{
			pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::LCHILD];
		}
	}
	// 2. �θ�κ��� ���� �ڽ��� �� ���� ���� �ö�
	//		�׶� �θ� �ļ���
	else
	{
		pSuccessor = _pNode;

		while (true)
		{
			// �� �̻� ���� �ö� �� ���� ==> ������ ��忴��.
			if (pSuccessor->IsRoot())
				return nullptr;

			// �θ�κ��� ���� �ڽ����� Ȯ��
			if (pSuccessor->IsLeftChild())
			{
				// �׶� �θ� �ļ���
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
				break;
			}
			else
			{
				pSuccessor = pSuccessor->arrNode[(int)NODE_TYPE::PARENT];
			}
		}

	}

	return pSuccessor;
}

template<typename T1, typename T2>
inline BSTNode<T1, T2>* BST<T1, T2>::GetInOrderPredecessor(BSTNode<T1, T2>* _pNode)
{
	return nullptr;
}

template<typename T1, typename T2>
inline BSTNode<T1, T2>* BST<T1, T2>::DeleteNode(BSTNode<T1, T2>* _pTargetNode)
{
	// ������ų ����� �ļ��� ��带 ã�Ƶд�.
	BSTNode<T1, T2>* pSuccessor = GetInOrderSuccessor(_pTargetNode);

	// 1. �ڽ��� �ϳ��� ���� ���
	if (_pTargetNode->IsLeaf())
	{
		// ������ų ��尡 �ϳ� ���� Root Node�� ���
		if (_pTargetNode == m_pRoot)
		{
			m_pRoot = nullptr;
		}
		else
		{
			// �θ��忡�� ���� �� �ڽĳ���� �ּҸ� null �� �����.
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = nullptr;
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = nullptr;
		}

		--m_iCount;
		delete _pTargetNode;
	}
	// 2. �ڽ��� 2���� ���
	else if (_pTargetNode->IsFull())
	{
		// ������ �ڸ��� ���� �ļ����� ���� �����Ų��.
		_pTargetNode->pair = pSuccessor->pair;

		// ���� �ļ��� ��带 �����Ѵ�.
		DeleteNode(pSuccessor);

		// ������ ��尡 �� ���� �ļ��ڰ� �Ǿ���.
		pSuccessor = _pTargetNode;
	}
	// 3. �ڽ��� 1���� ���
	else
	{
		NODE_TYPE eChildType = NODE_TYPE::LCHILD;
		if (_pTargetNode->arrNode[(int)NODE_TYPE::RCHILD])
			eChildType = NODE_TYPE::RCHILD;

		// ������ų ��尡 Root Node�� ���
		if (_pTargetNode == m_pRoot)
		{
			// �ڽĳ�带 RootNode�� �����.
			m_pRoot = _pTargetNode->arrNode[(int)eChildType];
			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = nullptr;
		}
		// ������ ����� �θ��, ������ ����� �ڽ��� �������ش�.
		else
		{
			if (_pTargetNode->IsLeftChild())
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::LCHILD] = _pTargetNode->arrNode[(int)eChildType];
			else
				_pTargetNode->arrNode[(int)NODE_TYPE::PARENT]->arrNode[(int)NODE_TYPE::RCHILD] = _pTargetNode->arrNode[(int)eChildType];

			_pTargetNode->arrNode[(int)eChildType]->arrNode[(int)NODE_TYPE::PARENT] = _pTargetNode->arrNode[(int)NODE_TYPE::PARENT];
		}

		--m_iCount;
		delete _pTargetNode;
	}

	return pSuccessor;
}

template<typename T1, typename T2>
inline bool BST<T1, T2>::Insert(const Pair<T1, T2>& _pair)
{
	BSTNode<T1, T2>* pNewNode = new BSTNode<T1, T2>(_pair, nullptr, nullptr, nullptr);

	// ù��° �����Ͷ��
	if (m_pRoot == nullptr)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		BSTNode<T1, T2>* pNode = m_pRoot;
		NODE_TYPE node_type = NODE_TYPE::END;

		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
				node_type = NODE_TYPE::RCHILD;
			else if (pNode->pair.first > pNewNode->pair.first)
				node_type = NODE_TYPE::LCHILD;
			else
				return false;	// �񱳽� ���� ���� ���� ��� �������� ����

			if (nullptr == pNode->arrNode[(int)node_type])
			{
				pNode->arrNode[(int)node_type] = pNewNode;
				pNewNode->arrNode[(int)NODE_TYPE::PARENT] = pNode;
				break;
			}
			else
			{
				pNode = pNode->arrNode[(int)node_type];
			}
		}
	}

	// ������ ���� ����
	++m_iCount;
	return true;
}

template<typename T1, typename T2>
inline typename BST<T1, T2>::iterator BST<T1, T2>::begin()
{
	BSTNode<T1, T2>* pNode = m_pRoot;

	while (pNode->arrNode[(int)NODE_TYPE::LCHILD])
	{
		pNode = pNode->arrNode[(int)NODE_TYPE::LCHILD];
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename BST<T1, T2>::iterator BST<T1, T2>::end()
{
	return iterator(this, nullptr);
}

template<typename T1, typename T2>
inline typename BST<T1, T2>::iterator BST<T1, T2>::find(const T1& _find)
{
	BSTNode<T1, T2>* pNode = m_pRoot;
	NODE_TYPE node_type = NODE_TYPE::END;

	while (true)
	{
		if (pNode->pair.first < _find)
			node_type = NODE_TYPE::RCHILD;
		else if (pNode->pair.first > _find)
			node_type = NODE_TYPE::LCHILD;
		else
			break;	// �ش� �����͸� ã�� ���
		

		if (nullptr == pNode->arrNode[(int)node_type])
		{
			// �����Ͱ� ���� ���
			pNode = nullptr;
			break;
		}
		else
		{
			pNode = pNode->arrNode[(int)node_type];
		}
	}

	return iterator(this, pNode);
}

template<typename T1, typename T2>
inline typename BST<T1,T2>::iterator BST<T1, T2>::erase(const iterator& _iter)
{
	assert(this == _iter.m_pBST);

	BSTNode<T1, T2>* pSuccessor = DeleteNode(_iter.m_pNode);

	return iterator(this, pSuccessor);
}
