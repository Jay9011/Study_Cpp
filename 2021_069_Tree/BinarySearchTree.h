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
	BSTNode<T1, T2>*	m_pRoot;	// 루트 노드 주소
	int					m_iCount;	// 데이터 개수

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

	// 첫번째 데이터라면
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
				// 비교시 둘이 같은 값인 경우 삽입하지 않음
				return false;
			}
		}
	}

	// 데이터 개수 증가
	++m_iCount;
	return true;
}
