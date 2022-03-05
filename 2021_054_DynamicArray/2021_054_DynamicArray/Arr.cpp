#include <assert.h>
#include "Arr.h"

Arr::Arr()
	:pInt(nullptr), iCount(0), iMaxCount(2)
{
	// new	: 메모리를 동적 할당하고 해당 주소를 리턴.
	pInt = new int[2];
}

Arr::~Arr()
{
	// delete	: 동적할당 된 메모리를 해제해주는 키워드.
	delete[] pInt;
}

// 뒤에 int 데이터 추가
void Arr::PushBack(int _iData)
{
	int i = 0;

	// 힙 영역에 할당 공간이 다 참
	if (iMaxCount <= iCount)
	{
		// 재할당
		Resize(iMaxCount * 2);
	}
	
	// 데이터 추가
	pInt[iCount++] = _iData;
}

// 공간 재할당
void Arr::Resize(int _iDataCount)
{
	// 현재 공간보다 더 적은 공간을 요청한 경우
	if (iMaxCount >= _iDataCount)
	{
		assert(nullptr);
	}

	// 1. 매개변수로 받아온 만큼 공간을 재할당
	int* pNew = new int[_iDataCount];

	// 2. 기존에 있던 데이터들을 새 공간에 복사
	for (int i = 0; i < iCount; i++)
	{
		pNew[i] = pInt[i];
	}
	// 3. 기존 공간은 메모리 해제
	delete[] pInt;

	// 4. 배열이 새로 할당된 공간을 가리키게 한다.
	pInt = pNew;

	// 4. MaxCount 변경 적용
	iMaxCount = _iDataCount;
}

int& Arr::operator[](const int& idx)
{
	// return pInt[idx];
	return *(pInt + idx);
}
