#pragma once

template <typename T1, typename T2>
struct Pair
{
	T1 first;
	T2 second;
};

template <typename T1, typename T2>
struct BSTNode
{
	Pair<T1, T2> pair;

	BSTNode<T1, T2>* pParent;
	BSTNode<T1, T2>* pLeftChild;
	BSTNode<T1, T2>* pRightChild;
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

public:
	bool Insert(const Pair<T1, T2>& _pair);

};

template<typename T1, typename T2>
inline bool BST<T1, T2>::Insert(const Pair<T1, T2>& _pair)
{
	BSTNode<T1, T2>* pNewNode = new BSTNode<T1, T2>();
	pNewNode->pParent = nullptr;
	pNewNode->pLeftChild = nullptr;
	pNewNode->pRightChild = nullptr;
	pNewNode->pair = _pair;

	// ù��° �����Ͷ��
	if (m_pRoot == nullptr)
	{
		m_pRoot = pNewNode;
	}
	else
	{
		BSTNode<T1, T2>* pNode = m_pRoot;

		while (true)
		{
			if (pNode->pair.first < pNewNode->pair.first)
			{
				if (pNode->pRightChild == nullptr)
				{
					pNode->pRightChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pRightChild;
				}
			}
			else if (pNode->pair.first > pNewNode->pair.first)
			{
				if (pNode->pLeftChild == nullptr)
				{
					pNode->pLeftChild = pNewNode;
					pNewNode->pParent = pNode;
					break;
				}
				else
				{
					pNode = pNode->pLeftChild;
				}
			}
			else
			{
				// �񱳽� ���� ���� ���� ��� �������� ����
				return false;
			}
		}
	}

	// ������ ���� ����
	++m_iCount;
	return true;
}
