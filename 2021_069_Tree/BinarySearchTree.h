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

public:
	bool Insert(const Pair<T1, T2>& _pair);

public:
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
	};

	iterator begin();
	iterator end();
	iterator find(const T1& _find);
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
