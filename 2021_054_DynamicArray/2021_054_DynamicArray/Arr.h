#pragma once
class Arr
{
	// Class�� ��� �ƹ��͵� ���� ���� ��� �⺻������ private�� �ν��Ѵ�.
	// �ٸ�, ���� �˾ƺ� �� �ְ� ����δ� ���� ����.
private:
	int*	pInt;
	int		iCount;
	int		iMaxCount;

public:
	Arr();
	~Arr();

public:
	void PushBack(int _iData);
	void Resize(int _iDataCount);

public:
	int& operator[] (const int& idx);
};