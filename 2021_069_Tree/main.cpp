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
	bstint.Insert(make_bstPair(100, 0));	//                    100                                 
	bstint.Insert(make_bstPair(150, 0));	//          50                  150                            
	bstint.Insert(make_bstPair(50, 0));		//      20     60          120      170                        
	bstint.Insert(make_bstPair(120, 0));	//                 80                                   
	bstint.Insert(make_bstPair(60, 0));		//                                                   
	bstint.Insert(make_bstPair(80, 0));		//                                                   
	bstint.Insert(make_bstPair(170, 0));	//                                                   
	bstint.Insert(make_bstPair(20, 0));		//                                                   

	BST<int, int>::iterator iter;
	iter = bstint.begin();
	iter = bstint.find(50);
	iter = bstint.erase(iter);
	

	return 0;
}