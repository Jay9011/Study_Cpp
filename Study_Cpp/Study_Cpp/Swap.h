#pragma once

void Swap(int* ptrA, int* ptrB)
{
	int temp = *ptrA;
	*ptrA = *ptrB;
	*ptrB = temp;
}

void Swap(int& refA, int& refB)
{
	int temp = refA;
	refA = refB;
	refB = temp;
}