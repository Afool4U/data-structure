// 二叉树(链式结构)
// @Time 2022-5-31 21:15
// @Author HJL

#include<iostream>
#include"bTree.hpp"
using namespace std;

int main() {
	BTree<int> btree({1,2,3,4,5,6,7,8});

	cout << "先序遍历: ";
	btree.preOrder();
	cout << "中序遍历: ";
	btree.inOrder();
	cout << "后序遍历: ";
	btree.postOrder();
	cout << "层序遍历: ";
	btree.levelOrder();

	return 0;
}