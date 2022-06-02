#pragma once

#include<vector>
#include<queue>
#include<iostream>
using std::vector;
using std::queue;

template<typename T>
struct Node {
	Node* left;
	Node* right;
	T value;
	Node(T value) :value(value), left(nullptr), right(nullptr) {}
};

template<typename T>
class BTree {
public:
	// 通过顺序存储的完全二叉树构造
	BTree(const vector<T>& arr);
	void preOrder();
	void inOrder();
	void postOrder();
	// 层序遍历
	void levelOrder();
	// 递归析构
	~BTree();
private:
	Node<T>* buildTree(const vector<T>& arr, size_t i);
	void preOrder(Node<T>* root);
	void inOrder(Node<T>* root);
	void postOrder(Node<T>* root);
	void destroy(Node<T>* root);
	Node<T>* root;
};

template<typename T>
inline BTree<T>::BTree(const vector<T>& arr)
{
	root = buildTree(arr, 0);
}

template<typename T>
inline Node<T>* BTree<T>::buildTree(const vector<T>& arr, size_t i)
{

	if (i >= arr.size())
		return nullptr;
	Node<T>* root = new Node<T>(arr[i]);
	// 递归构造左右子树
	root->left = buildTree(arr, i * 2 + 1);
	root->right = buildTree(arr, i * 2 + 2);
	return root;
}

template<typename T>
inline void BTree<T>::preOrder()
{
	preOrder(root);
	std::cout << std::endl;
}

template<typename T>
inline void BTree<T>::inOrder()
{
	inOrder(root);
	std::cout << std::endl;
}

template<typename T>
inline void BTree<T>::postOrder()
{
	postOrder(root);
	std::cout << std::endl;
}

template<typename T>
inline void BTree<T>::preOrder(Node<T>* root)
{
	if (root == nullptr)
		return;
	std::cout << root->value << " ";
	preOrder(root->left);
	preOrder(root->right);
}

template<typename T>
inline void BTree<T>::inOrder(Node<T>* root)
{
	if (root == nullptr)
		return;
	inOrder(root->left);
	std::cout << root->value << " ";
	inOrder(root->right);
}

template<typename T>
inline void BTree<T>::postOrder(Node<T>* root)
{
	if (root == nullptr)
		return;
	postOrder(root->left);
	postOrder(root->right);
	std::cout << root->value << " ";
}

template<typename T>
inline void BTree<T>::levelOrder()
{
	queue<Node<T>*> q;
	q.push(root);
	while (!q.empty()) {  // BFS
		// 访问队首元素
		auto front = q.front();
		std::cout << front->value << " ";
		q.pop();
		// front左右孩子入队
		if (front->left != nullptr)
			q.push(front->left);
		if (front->right != nullptr)
			q.push(front->right);
	}
	std::cout << std::endl;
}

template<typename T>
inline BTree<T>::~BTree()
{
	destroy(root);
}

template<typename T>
inline void BTree<T>::destroy(Node<T>* root)
{
	if (root) {
		destroy(root->left);
		destroy(root->right);
		delete root;
	}
}
