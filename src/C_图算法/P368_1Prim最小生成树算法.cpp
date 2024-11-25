/**
 * @Name Prim(普里姆)算法 求最小生成树的安全边
 */
#include <iostream>
#include <vector>
#include <climits>

using namespace std;

// Prim算法
void Prim(int graph[5][5], int V) {
    int parent[V]; // 存储生成树
    int key[V];    // 用于选择最小边
    bool mstSet[V]; // 为每个顶点标记是否在最小生成树中

    for (int i = 0; i < V; i++) {
        key[i] = INT_MAX; // 初始化所有键值为无穷大
        mstSet[i] = false; // 初始化所有顶点未被包含在最小生成树中
    }

    key[0] = 0; // 从第一个顶点开始
    parent[0] = -1; // 第一个顶点是根

    for (int count = 0; count < V - 1; count++) {
        int minKey = INT_MAX, minIndex;
        
        for (int v = 0; v < V; v++)
            if (!mstSet[v] && key[v] < minKey)
                minKey = key[v], minIndex = v;

        mstSet[minIndex] = true;

        for (int v = 0; v < V; v++)
            if (graph[minIndex][v] && !mstSet[v] && graph[minIndex][v] < key[v]) {
                parent[v] = minIndex;
                key[v] = graph[minIndex][v];
            }
    }

    cout << "Prim算法生成的最小生成树的边:\n";
    for (int i = 1; i < V; i++)
        cout << parent[i] << " -- " << i << " == " << graph[i][parent[i]] << endl;
}

int main() {
    int graph[5][5] = {
        {0, 10, 6, 5, 0},
        {10, 0, 0, 15, 0},
        {6, 0, 0, 4, 0},
        {5, 15, 4, 0, 0},
        {0, 0, 0, 0, 0}
    };

    cout << "使用Prim算法:\n";
    Prim(graph, 4);

    return 0;
}