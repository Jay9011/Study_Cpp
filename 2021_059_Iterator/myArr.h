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
	T* data() { return this->m_pData };
	int size() { return this->m_iCount };
	int capacity() { return this->m_iMaxCount };
	T& operator[] (int idx);

	class iterator;		// 전방선언
	iterator begin();
	iterator end();

public:
	// inner 클래스를 포함하고 있는 클래스의 private 멤버에 접근 가능
	class iterator
	{
	private:
		MyArr*	m_pArr;		// iterator가 가리킬 데이터를 관리하는 가변배열 주소
		T*		m_pData;	// 데이터들의 시작 주소
		int		m_iIdx;		// 가리키는 데이터의 인덱스

	public:
		iterator()
			: m_pArr(nullptr)
			, m_pData(nullptr)
			, m_iIdx(-1)
		{
			
		}
		iterator(MyArr* _pArr, T* _pData, int _iIdx)
			: m_pArr(_pArr)
			, m_pData(_pData)
			, m_iIdx(_iIdx)
		{

		}
		~iterator()
		{

		}

	public:
		T& operator * ()
		{
			// iterator 가 알고 있는 주소와, 가변배열이 알고 있는 주소가 달라진 경우 (공간 확장으로 주소가 달라진 경우)
			// iterator 가 end iterator 인 경우
			if (this->m_pArr->m_pData != this->m_pData || -1 == this->m_iIdx)
				assert(nullptr);

			return this->m_pData[this->m_iIdx];
		}

		iterator& operator ++ ()
		{
			return *this;
		}

		iterator& operator -- ()
		{
			return *this;
		}

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
	// 힙 영역에 할당한 공간이 다 참
	if (this->m_iMaxCount <= this->m_iCount)
	{
		// 재할당
		resize(m_iMaxCount * 2);
	}

	// 데이터 추가
	this->m_pData[this->m_iCount++] = _Data;
}

template<typename T>
inline void MyArr<T>::resize(int _iResizeCount)
{
	// 현재 최대 수용량보다 더 적은 수치로 확장하려는 경우
	if (this->m_iMaxCount >= _iResizeCount)
	{
		assert(nullptr);
	}

	// 1. 리사이즈 시킬 개수만큼 동적할당 한다.
	T* pNew = new T[_iResizeCount];

	// 2. 기존 공간에 있던 데이터들을 새로 할당한 공간으로 복사시킨다.
	for (int i = 0; i < this->m_iCount; ++i)
	{
		pNew[i] = this->m_pData[i];
	}

	// 3. 기존 공간은 메모리 해제
	delete[] this->m_pData;

	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	this->m_pData = pNew;

	// 5. Max Count 변경점 적용
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
		return iterator(this, this->m_pData, -1);	// 데이터가 없는 경우, begin() == end()
	}
	else
	{
		return iterator(this, this->m_pData, 0);	// this 는 자기 자신을 가리키는 포인터
	}
}

template<typename T>
typename MyArr<T>::iterator MyArr<T>::end()
{
	// 끝을 가리키는 포인터는 인덱스를 -1로 생각한다.
	return iterator(this, this->m_pData, -1);
}
