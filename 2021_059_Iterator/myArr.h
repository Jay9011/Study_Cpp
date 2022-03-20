#pragma once

#include <assert.h>

template<typename T>
class MyArr
{
private:
	T*	m_pData;
	int	m_iCount;
	int	m_iMaxCount;

public:
	MyArr();
	~MyArr();

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);
	T* data() { return this->m_pData; };
	int size() { return this->m_iCount; };
	int capacity() { return this->m_iMaxCount; };
	T& operator[] (int idx);

	class iterator;		// ���漱��
	iterator begin();
	iterator end();
	iterator erase(iterator& _iter);

public:
	// inner Ŭ������ �����ϰ� �ִ� Ŭ������ private ����� ���� ����
	class iterator
	{
	private:
		MyArr*	m_pArr;		// iterator�� ����ų �����͸� �����ϴ� �����迭 �ּ�
		T*		m_pData;	// �����͵��� ���� �ּ�
		int		m_iIdx;		// ����Ű�� �������� �ε���
		bool	m_bValid;	// iterator ��ȿ�� üũ

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
			, m_bValid(false)
		{
			
		}
		iterator(MyArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
			, m_bValid(false)
		{
			if (nullptr != _pArr && 0 <= _iIdx)
			{
				m_bValid = true;
			}
		}
		~iterator()
		{

		}

	public:
		T& operator * ()
		{
			// iterator �� �˰� �ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ��� (���� Ȯ������ �ּҰ� �޶��� ���)
			// iterator �� end iterator �� ���
			if (this->m_pArr->m_pData != this->m_pData || -1 == this->m_iIdx || !m_bValid)
				assert(nullptr);

			return this->m_pData[this->m_iIdx];
		}

		// ����
		iterator& operator ++ ()
		{
			// end iterator �� ���
			// iterator �� �˰� �ִ� �ּҿ�, �����迭�� �˰� �ִ� �ּҰ� �޶��� ��� (���� Ȯ������ �ּҰ� �޶��� ���)
			if (this->m_pArr->m_pData != this->m_pData || -1 == this->m_iIdx)
			{
				assert(nullptr);
			}
		
			// iterator �� ������ �����͸� ����Ű�� �ִ� ���
			// --> end iterator �� �ȴ�.
			if ((this->m_pArr->size() - 1) == (this->m_iIdx))
			{
				this->m_iIdx = -1;
			}
			else
			{
				++m_iIdx;
			}

			return *this;
		}
		// ����++
		iterator operator ++(int)
		{
			// ��������� this�� �����Ѵ�.
			iterator copy_iter = *this;
			
			// ���� �ڱ� �ڽ��� ������Ų��.
			++(*this);

			return copy_iter;
		}
		// --����
		iterator& operator -- ()
		{
			return *this;
		}
		// ����--
		iterator operator --(int)
		{
			// ��������� this�� �����Ѵ�.
			iterator copy_iter = *this;

			// ���� �ڱ� �ڽ��� ������Ų��.
			--(*this);

			return copy_iter;
		}

		// �� ������ ==, !=
		bool operator == (const iterator& _otherIter)
		{
			if (this->m_pData == _otherIter.m_pData && this->m_iIdx == _otherIter.m_iIdx)
			{
				return true;
			}
			return false;
		}
		bool operator != (const iterator& _otherIter)
		{
			return !(*this == _otherIter);
		}

		friend class MyArr;	// friend class�� �����ϸ� friend ������ class�� �ڱ� �ڽ��� private�� ������ �� �ִ�.
		// end class iterator
	};
	// end class MyArr
};

template<typename T>
inline MyArr<T>::MyArr()
	: m_pData(nullptr)
	, m_iCount(0)
	, m_iMaxCount(2)
{
	this->m_pData = new T[2];
}

template<typename T>
inline MyArr<T>::~MyArr()
{
	delete[] this->m_pData;
}

template<typename T>
inline void MyArr<T>::push_back(const T& _Data)
{
	// �� ������ �Ҵ��� ������ �� ��
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// ���Ҵ�
		resize(m_iMaxCount * 2);
	}

	// ������ �߰�
	this->m_pData[this->m_iCount++] = _Data;
}

template<typename T>
inline void MyArr<T>::resize(int _iResizeCount)
{
	// ���� �ִ� ���뷮���� �� ���� ��ġ�� Ȯ���Ϸ��� ���
	if (this->m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. �������� ��ų ������ŭ �����Ҵ� �Ѵ�.
	T* pNew = new T[_iResizeCount];

	// 2. ���� ������ �ִ� �����͵��� ���� �Ҵ��� �������� �����Ų��.
	for (int i = 0; i < this->m_iCount; ++i)
	{
		pNew[i] = this->m_pData[i];
	}

	// 3. ���� ������ �޸� ����
	delete[] this->m_pData;

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	this->m_pData = pNew;

	// 5. Max Count ������ ����
	this->m_iMaxCount = _iResizeCount;
}

template<typename T>
T& MyArr<T>::operator[](int idx)
{
	return this->m_pData[idx];
}

template<typename T>
typename MyArr<T>::iterator MyArr<T>::begin()
{
	if (0 == this->m_pData)
	{
		return iterator(this, this->m_pData, -1);	// �����Ͱ� ���� ���, begin() == end()
	}
	else
	{
		return iterator(this, this->m_pData, 0);	// this �� �ڱ� �ڽ��� ����Ű�� ������
	}
}

template<typename T>
typename MyArr<T>::iterator MyArr<T>::end()
{
	// ���� ����Ű�� �����ʹ� �ε����� -1�� �����Ѵ�.
	return iterator(this, this->m_pData, -1);
}
// iterator�� ���� �����͸� �����ϴ� �Լ�
template<typename T>
typename MyArr<T>::iterator MyArr<T>::erase(iterator& _iter)
{
	// �ٸ� iterator�� ������ ���
	// Ȥ�� end iterator �� ��� Ȥ�� �̻��� index�� ������ �ִ� ��� (�����Ҽ� ���� ����� ���)
	if (this != _iter.m_pArr || end() == _iter || m_iCount <= _iter.m_iIdx)
	{
		assert(nullptr);
	}

	// iterator �� ����Ű�� �����͸� �迭 ������ �����Ѵ�.
	int iLoopCount = m_iCount - (_iter.m_iIdx + 1);
	for (int i = 0; i < iLoopCount; i++)
	{
		m_pData[i + _iter.m_iIdx] = m_pData[i + _iter.m_iIdx + 1];
	}

	_iter.m_bValid = false;

	// ���ŵ� ��Ҹ�ŭ Count ����
	--m_iCount;

	return iterator(this, m_pData, _iter.m_iIdx);
}
