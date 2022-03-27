#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	/*
	*	※ 이진 탐색
	*		: 정렬되어 있는 데이터를 처음 중간에서 시작해 검색 범위를 줄여 나가는 탐색법
	* 
	*	※ 이진 탐색 트리
	*	1. 이진 탐색을 사용 할 수 있게 고안된 트리
	*	2. 데이터 입력 시 O(log N)의 효율
	*	3. 탐색 효율은 O(log N)
	*	4. 트리의 모양이 밸런스가 유지되지 않으면 제대로 된 탐색 효율이 나오지 않는다.
	*		- 자가 균형 기능 필요 ( AVL, Red/Black )
	*/

	BST<int, int> bstint;

	Pair<int, int> pair;
	
	pair.first = 100;
	bstint.Insert(pair);

	pair.first = 150;
	bstint.Insert(pair);
	
	pair.first = 50;
	bstint.Insert(pair);

	return 0;
}