#pragma once

#include <iostream>
#include <vector>
#include <queue>
const auto inf = 0x3f3f3f3f;
using namespace std;

// 邻接矩阵
template<typename T>
class Graph {
public:
	Graph(const vector<vector<T>>& mat) :mat(mat) {}
	void dfs();
	void bfs();
	int prim();
	vector<T> dijkstra(size_t start);
	vector<vector<int>> floyd();
	size_t size();
private:
	void dfs(size_t i, vector<bool>& visited);
	vector<vector<T>> mat;
};

template<typename T>
inline void Graph<T>::dfs()
{
	vector<bool> visited(mat.size(), false);
	for (size_t i = 0; i < mat.size(); i++) {
		if (!visited[i]) {
			dfs(i, visited);
			std::cout << "end" << std::endl;
		}
	}

}

template<typename T>
inline void Graph<T>::dfs(size_t i, vector<bool>& visited)
{
	visited[i] = true;
	std::cout << i + 1 << "->";
	for (size_t j = 0; j < mat.size(); j++) {
		if (mat[i][j] < inf && !visited[j]) {
			dfs(j, visited);
		}
	}
}

template<typename T>
inline void Graph<T>::bfs()
{
	vector<bool> visited(mat.size(), false);
	queue<size_t> q;
	for (size_t i = 0; i < mat.size(); i++) {
		if (!visited[i]) {
			q.push(i);
			visited[i] = true;  // 认为入队即访问
			while (!q.empty()) {
				auto front = q.front();
				// 访问front
				std::cout << front + 1 << "->";
				q.pop();
				// front的未访问过邻居入队
				for (size_t j = 0; j < mat.size(); j++) {
					if (mat[front][j] < inf && !visited[j]) {
						q.push(j);
						visited[j] = true;  // 认为入队即访问
					}
				}
			}
			std::cout << "end" << std::endl;
		}
	}
}

template<typename T>
inline int Graph<T>::prim()
{
	vector<bool> visited(mat.size(), false);
	// 初始化已计算顶点
	vector<T> d(mat.size(), inf);
	d[0] = 0;  // 初始化第一个顶点
	int res = 0;
	for (size_t i = 0; i < mat.size(); i++) {  // 至多n次
		size_t u = -1;
		T min = inf;
		for (size_t j = 0; j < mat.size(); j++) //找到未访问的顶点中d[]最小的
			if (!visited[j] && d[j] < min) {
				u = j;
				min = d[j];
			}
		if (u == -1)
			return -1;
		visited[u] = true;
		res += d[u];
		// 尝试更新所有未访问顶点到d集合的距离
		for (size_t v = 0; v < mat.size(); v++)
			if (!visited[v] && mat[u][v] < d[v])
				d[v] = mat[u][v];
	}
	return res;
}

template<typename T>
inline vector<T> Graph<T>::dijkstra(size_t start)
{
	start -= 1;
	vector<bool> visited(mat.size(), false);
	vector<T> d(mat.size(), inf);
	// 初始化start到所有顶点的距离
	for (size_t i = 0; i < d.size(); i++)
		d[i] = mat[start][i];
	for (size_t i = 0; i < mat.size() - 1; i++) {  // 至多n-1次
		size_t u = -1;
		T min = inf;
		for (size_t j = 0; j < mat.size(); j++) //找到未访问的顶点中d[]最小的
			if (!visited[j] && d[j] < min) {
				u = j;
				min = d[j];
			}
		visited[u] = true;
		// 尝试更新所有顶点v到顶点u的距离
		for (size_t v = 0; v < mat.size(); v++) {
			T newDist = min + mat[u][v];
			d[v] = newDist < d[v] ? newDist : d[v];
		}

	}
	return d;
}

template<typename T>
inline vector<vector<int>> Graph<T>::floyd()
{
	auto res = mat;  // 直接拷贝
	for (size_t i = 0; i < res.size(); i++)
		for (size_t j = 0; j < res.size(); j++)
			for (size_t p = 0; p < res.size(); p++)
				if (res[j][p] > res[j][i] + res[i][p])
					res[j][p] = res[j][i] + res[i][p];
	return res;
}

template<typename T>
inline size_t Graph<T>::size()
{
	return mat.size();
}
