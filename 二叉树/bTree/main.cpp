// ������(��ʽ�ṹ)
// @Time 2022-5-31 21:15
// @Author HJL

#include<iostream>
#include"bTree.hpp"
using namespace std;

int main() {
	BTree<int> btree({1,2,3,4,5,6,7,8});

	cout << "�������: ";
	btree.preOrder();
	cout << "�������: ";
	btree.inOrder();
	cout << "�������: ";
	btree.postOrder();
	cout << "�������: ";
	btree.levelOrder();

	return 0;
}