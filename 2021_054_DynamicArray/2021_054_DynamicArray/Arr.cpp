#include <assert.h>
#include "Arr.h"

Arr::Arr()
	:pInt(nullptr), iCount(0), iMaxCount(2)
{
	// new	: �޸𸮸� ���� �Ҵ��ϰ� �ش� �ּҸ� ����.
	pInt = new int[2];
}

Arr::~Arr()
{
	// delete	: �����Ҵ� �� �޸𸮸� �������ִ� Ű����.
	delete[] pInt;
}

// �ڿ� int ������ �߰�
void Arr::PushBack(int _iData)
{
	int i = 0;

	// �� ������ �Ҵ� ������ �� ��
	if (iMaxCount <= iCount)
	{
		// ���Ҵ�
		Resize(iMaxCount * 2);
	}
	
	// ������ �߰�
	pInt[iCount++] = _iData;
}

// ���� ���Ҵ�
void Arr::Resize(int _iDataCount)
{
	// ���� �������� �� ���� ������ ��û�� ���
	if (iMaxCount >= _iDataCount)
	{
		assert(nullptr);
	}

	// 1. �Ű������� �޾ƿ� ��ŭ ������ ���Ҵ�
	int* pNew = new int[_iDataCount];

	// 2. ������ �ִ� �����͵��� �� ������ ����
	for (int i = 0; i < iCount; i++)
	{
		pNew[i] = pInt[i];
	}
	// 3. ���� ������ �޸� ����
	delete[] pInt;

	// 4. �迭�� ���� �Ҵ�� ������ ����Ű�� �Ѵ�.
	pInt = pNew;

	// 4. MaxCount ���� ����
	iMaxCount = _iDataCount;
}

int& Arr::operator[](const int& idx)
{
	// return pInt[idx];
	return *(pInt + idx);
}
