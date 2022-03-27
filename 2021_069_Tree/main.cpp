#include <iostream>
#include "BinarySearchTree.h"

int main()
{
	/*
	*	�� ���� Ž��
	*		: ���ĵǾ� �ִ� �����͸� ó�� �߰����� ������ �˻� ������ �ٿ� ������ Ž����
	* 
	*	�� ���� Ž�� Ʈ��
	*	1. ���� Ž���� ��� �� �� �ְ� ��ȵ� Ʈ��
	*	2. ������ �Է� �� O(log N)�� ȿ��
	*	3. Ž�� ȿ���� O(log N)
	*	4. Ʈ���� ����� �뷱���� �������� ������ ����� �� Ž�� ȿ���� ������ �ʴ´�.
	*		- �ڰ� ���� ��� �ʿ� ( AVL, Red/Black )
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