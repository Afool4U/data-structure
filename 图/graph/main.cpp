// ͼ(�ڽӾ���)
// @Time 2022-6-1 3:01
// @Author HJL

#include<iostream>
#include"graph.hpp"
using namespace std;

int main() {
	vector<vector<int>> data1({
		{0,inf,6,4,8},
		{9,0,2,inf,7},
		{1,inf,0,3,5},
		{inf,4,inf,0,3},
		{8,4,inf,3,0},
		});
	vector<vector<int>> data2({
		{0,2,6,4,8},
		{9,0,2,5,7},
		{1,3,0,3,5},
		{7,4,8,0,3},
		{8,4,4,3,0},
		});
	Graph<int> g(data1);
	cout << "DFS: ";
	g.dfs();
	cout << "BFS: ";
	g.bfs();
	cout << "prim�㷨���MST��Ȩ��: "<< Graph<int>(data2).prim() << endl;
	for (size_t i = 1; i <= g.size(); i++) {
		int start = i;  // ����̾�������
		cout << "dijkstra�㷨��ö���" << start << "�������������̾���: ";
		auto v = g.dijkstra(start);
		for (auto& i : v)
			cout << i << " ";
		cout << endl;
	}
	cout << "floyd�㷨���ȫ����̾���: " << endl;
	vector<vector<int>> g_min = g.floyd();
	for (auto& i : g_min) {
		for (auto& j : i)
			cout << j << " ";
		cout << endl;
	}
	return 0;
}