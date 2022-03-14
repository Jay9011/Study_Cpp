#pragma once

#include <assert.h>

template<typename T>
class MyArr
{
public:
	MyArr();
	~MyArr();

private:
	T*		m_pData;
	int		m_iCount;
	int		m_iManxCount;

public:
	void push_back(const T& _Data);
	void resize(int _iResizeCount);
	T* data() { return this->m_pData };
	int size() { return this->m_iCount };
	int capacity() { return this->m_iManxCount };
	T& operator[] (int idx);

	class iterator;		// 전방선언
	iterator begin();

public:
	class iterator
	{
	public:
		iterator()
			: m_pData(nullptr)
			, m_iIdx(-1)
		{

		}
		iterator(T* _pData, int _iIdx)
			: m_pData(_pData)
			, m_iIdx(_iIdx)
		{

		}
		~iterator()
		{

		}

	private:
		T*		m_pData;
		int		m_iIdx;
	};
};

template<typename T>
inline MyArr<T>::MyArr()
	: m_pData(nullptr)
{
}

template<typename T>
inline MyArr<T>::~MyArr()
{
}

template<typename T>
T& MyArr<T>::operator[](int idx)
{
	return this->m_pData[idx];
}

template<typename T>
typename MyArr<T>::iterator MyArr<T>::begin()
{
	return iterator(m_pData, 0);
}
