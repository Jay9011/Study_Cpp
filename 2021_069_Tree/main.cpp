#include <iostream>
#include "BinarySearchTree.h"

using std::cout;
using std::endl;

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
	bstint.Insert(make_bstPair(100, 0));
	bstint.Insert(make_bstPair(150, 0));
	bstint.Insert(make_bstPair(50, 0));

	BST<int, int>::iterator iter;
	iter = bstint.begin();
	iter = bstint.find(150);

	for (iter = bstint.begin(); iter != bstint.end(); ++iter)
	{
		cout << iter->first << " " << iter->second << endl;
	}

	return 0;
}