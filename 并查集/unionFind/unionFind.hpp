// 并查集 路径压缩+按秩合并
// @Time 2022-6-1 13:01
// @Author HJL

class UnionFind {
private:
    int* root;
    int* rank;
    int cnt;
public:
    UnionFind(int n) {
        root = new int[n];
        for (int i = 0; i < n; i++)
            root[i] = i;
        rank = new int[n];
        cnt = n;
    }
    void join(int x, int y) {
        int rootX = find(x);
        int rootY = find(y);
        if (rootX == rootY)
            return;
        if (rank[rootX] > rank[rootY])
            root[rootY] = rootX;
        else if (rank[rootX] < rank[rootY])
            root[rootX] = rootY;
        else {
            root[rootY] = rootX;
            rank[rootX]++;
        }
        cnt--;
    }
    int find(int x) {
        if (x == root[x])
            return x;
        return root[x] = find(root[x]);  // 其实路径压缩的同时已经破坏秩了
    }
    bool connected(int x, int y) {
        return find(x) == find(y);
    }
    int count() {
        return cnt;
    }
    ~UnionFind() {
        delete[] root;
        delete[] rank;  // 记录秩
    }
};
