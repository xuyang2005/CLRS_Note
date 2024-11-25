/**
 * @Name Kruskal(克鲁斯卡尔)算法 求最小生成树的安全边
 */
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

// 边的结构体
struct Edge {
    int src, dest, weight;
};

// 比较函数，用于排序边
bool compare(Edge a, Edge b) {
    return a.weight < b.weight;
}

// 查找集的代表
int find(int parent[], int i) {
    if (parent[i] == -1)
        return i;
    return find(parent, parent[i]);
}

// 连接两个子集
void unionSets(int parent[], int x, int y) {
    int xset = find(parent, x);
    int yset = find(parent, y);
    parent[xset] = yset;
}

// Kruskal算法
void Kruskal(vector<Edge> edges, int V) {
    sort(edges.begin(), edges.end(), compare);
    
    int parent[V];
    fill_n(parent, V, -1);
    
    cout << "Kruskal算法生成的最小生成树的边:\n";

    for (auto &edge : edges) {
        int x = find(parent, edge.src);
        int y = find(parent, edge.dest);
        
        if (x != y) {
            cout << edge.src << " -- " << edge.dest << " == " << edge.weight << endl;
            unionSets(parent, x, y);
        }
    }
}

int main() {
    int V = 4; // 顶点数
    vector<Edge> edges = {
        {0, 1, 10},
        {0, 2, 6},
        {0, 3, 5},
        {1, 3, 15},
        {2, 3, 4}
    };

    Kruskal(edges, V);
    return 0;
}