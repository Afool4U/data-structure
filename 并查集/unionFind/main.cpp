// 二叉树(链式结构)
// @Time 2022-6-1 13:01
// @Author HJL

#include<iostream>
#include"unionFind.hpp"
using namespace std;

int main() {
	const int N = 10;
	UnionFind u(N);
	for (int i = 0; i < N - 2; i++) {
		u.join(i, i + 1);
	}
	cout << "共有" << u.count() << "个连通分量" << endl;
	for (int i = 0; i < N - 1; i++) {
		cout << i << "和" << i + 1 << (u.connected(i, i + 1) ? "连通" : "不连通") << endl;
	}

	return 0;
}