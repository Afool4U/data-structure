// ������(��ʽ�ṹ)
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
	cout << "����" << u.count() << "����ͨ����" << endl;
	for (int i = 0; i < N - 1; i++) {
		cout << i << "��" << i + 1 << (u.connected(i, i + 1) ? "��ͨ" : "����ͨ") << endl;
	}

	return 0;
}