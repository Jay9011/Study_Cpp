#pragma once
class Arr
{
	// Class의 경우 아무것도 적지 않은 경우 기본적으로 private로 인식한다.
	// 다만, 쉽게 알아볼 수 있게 적어두는 편이 좋다.
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